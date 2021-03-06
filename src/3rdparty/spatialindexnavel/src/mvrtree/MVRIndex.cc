// Spatial Index Library
//
// Copyright (C) 2002 Navel Ltd.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//  Email:
//    mhadji@gmail.com

#include "../spatialindex/SpatialIndexImpl.h"
#include "MVRTree.h"
#include "MVRNode.h"
#include "MVRLeaf.h"
#include "MVRIndex.h"

using namespace SpatialIndex::MVRTree;

Index::~Index()
{
}

Index::Index(SpatialIndex::MVRTree::MVRTree* pTree, id_type id, size_t level) : Node(pTree, id, level, pTree->m_indexCapacity)
{
}

NodePtr Index::chooseSubtree(const TimeRegion& mbr, size_t insertionLevel, std::stack<id_type>& pathBuffer)
{
	if (m_level == insertionLevel) return NodePtr(this, &(m_pTree->m_indexPool));

	pathBuffer.push(m_identifier);

	size_t child = 0;

	switch (m_pTree->m_treeVariant)
	{
		case RV_LINEAR:
		case RV_QUADRATIC:
			child = findLeastEnlargement(mbr);
			break;
		case RV_RSTAR:
			if (m_level == 1)
			{
				// if this node points to leaves...
				child = findLeastOverlap(mbr);
			}
			else
			{
				child = findLeastEnlargement(mbr);
			}
		break;
		default:
			throw Tools::NotSupportedException("Index::chooseSubtree: Tree variant not supported.");
	}
	assert (child != std::numeric_limits<size_t>::max());

	NodePtr n = m_pTree->readNode(m_pIdentifier[child]);
	NodePtr ret = n->chooseSubtree(mbr, insertionLevel, pathBuffer);
	assert(n.unique());
	if (ret.get() == n.get()) n.relinquish();

	return ret;
}

NodePtr Index::findLeaf(const TimeRegion& mbr, id_type id, std::stack<id_type>& pathBuffer)
{
	pathBuffer.push(m_identifier);

	for (size_t cChild = 0; cChild < m_children; cChild++)
	{
		// check live nodes only.
		if (m_ptrMBR[cChild]->m_endTime < std::numeric_limits<double>::max()) continue;
		//if (m_ptrMBR[cChild]->m_endTime < std::numeric_limits<double>::max() ||
		//		m_ptrMBR[cChild]->m_startTime > mbr.m_startTime) continue;

		if (m_ptrMBR[cChild]->containsRegion(mbr))
		{
			NodePtr n = m_pTree->readNode(m_pIdentifier[cChild]);
			NodePtr l = n->findLeaf(mbr, id, pathBuffer);
			if (n.get() == l.get()) n.relinquish();
			if (l.get() != 0) return l;
		}
	}

	pathBuffer.pop();

	return NodePtr();
}

void Index::split(
	size_t dataLength, byte* pData, TimeRegion& mbr, id_type id, NodePtr& pLeft, NodePtr& pRight,
	TimeRegion& mbr2, id_type id2, bool bInsertMbr2)
{
	m_pTree->m_stats.m_splits++;

	std::vector<size_t> g1, g2;

	switch (m_pTree->m_treeVariant)
	{
		case RV_LINEAR:
		case RV_QUADRATIC:
			rtreeSplit(dataLength, pData, mbr, id, g1, g2, mbr2, id2, bInsertMbr2);
			break;
		case RV_RSTAR:
			rstarSplit(dataLength, pData, mbr, id, g1, g2, mbr2, id2, bInsertMbr2);
			break;
		default:
			throw Tools::NotSupportedException("Index::split: Tree variant not supported.");
	}

	pLeft = m_pTree->m_indexPool.acquire();
	pRight = m_pTree->m_indexPool.acquire();

	if (pLeft.get() == 0) pLeft = NodePtr(new Index(m_pTree, m_identifier, m_level), &(m_pTree->m_indexPool));
	if (pRight.get() == 0) pRight = NodePtr(new Index(m_pTree, -1, m_level), &(m_pTree->m_indexPool));

	pLeft->m_nodeMBR = m_pTree->m_infiniteRegion;
	pRight->m_nodeMBR = m_pTree->m_infiniteRegion;

	size_t cIndex;

	for (cIndex = 0; cIndex < g1.size(); cIndex++)
	{
		pLeft->insertEntry(0, 0, *(m_ptrMBR[g1[cIndex]]), m_pIdentifier[g1[cIndex]]);
	}

	for (cIndex = 0; cIndex < g2.size(); cIndex++)
	{
		pRight->insertEntry(0, 0, *(m_ptrMBR[g2[cIndex]]), m_pIdentifier[g2[cIndex]]);
	}
}

size_t Index::findLeastEnlargement(const TimeRegion& r) const
{
	double area = std::numeric_limits<double>::max();
	size_t best = std::numeric_limits<size_t>::max();

	TimeRegionPtr t = m_pTree->m_regionPool.acquire();

	for (size_t cChild = 0; cChild < m_children; cChild++)
	{
		// if this child is already dead do not consider it.
		if (m_ptrMBR[cChild]->m_endTime <= r.m_startTime) continue;

		m_ptrMBR[cChild]->getCombinedRegion(*t, r);

		double a = m_ptrMBR[cChild]->getArea();
		double enl = t->getArea() - a;

		if (enl < area)
		{
			area = enl;
			best = cChild;
		}
		else if (
				enl > area - std::numeric_limits<double>::epsilon() &&
				enl < area + std::numeric_limits<double>::epsilon())
		{
			if (a < m_ptrMBR[best]->getArea()) best = cChild;
		}
	}

#ifndef NDEBUG
	if (best == std::numeric_limits<size_t>::max())
	{
		std::ostringstream s;
		s << "findLeastEnlargement: All entries of node " << m_identifier << " are dead.";
		throw Tools::IllegalStateException(s.str());
	}
#endif

	return best;
}

size_t Index::findLeastOverlap(const TimeRegion& r) const
{
	OverlapEntry** entries = new OverlapEntry*[m_children];

	double leastOverlap = std::numeric_limits<double>::max();
	double me = std::numeric_limits<double>::max();
	OverlapEntry* best = 0;
	size_t cLiveEntries = 0;

	// find combined region and enlargement of every entry and store it.
	for (size_t cChild = 0; cChild < m_children; cChild++)
	{
		if (m_ptrMBR[cChild]->m_endTime <= r.m_startTime) continue;

		try
		{
			entries[cLiveEntries] = new OverlapEntry();
		}
		catch (...)
		{
			for (size_t i = 0; i < cLiveEntries; i++) delete entries[i];
			delete[] entries;
			throw;
		}

		entries[cLiveEntries]->m_index = cChild;
		entries[cLiveEntries]->m_original = m_ptrMBR[cChild];
		entries[cLiveEntries]->m_combined = m_pTree->m_regionPool.acquire();
		m_ptrMBR[cChild]->getCombinedRegion(*(entries[cLiveEntries]->m_combined), r);
		entries[cLiveEntries]->m_oa = entries[cLiveEntries]->m_original->getArea();
		entries[cLiveEntries]->m_ca = entries[cLiveEntries]->m_combined->getArea();
		entries[cLiveEntries]->m_enlargement = entries[cLiveEntries]->m_ca - entries[cLiveEntries]->m_oa;

		if (entries[cLiveEntries]->m_enlargement < me)
		{
			me = entries[cLiveEntries]->m_enlargement;
			best = entries[cLiveEntries];
		}
		else if (entries[cLiveEntries]->m_enlargement == me && entries[cLiveEntries]->m_oa < best->m_oa)
		{
			best = entries[cLiveEntries];
		}
		cLiveEntries++;
	}

#ifndef NDEBUG
	if (cLiveEntries == 0)
	{
		std::ostringstream s;
		s << "findLeastOverlap: All entries of node " << m_identifier << " are dead.";
		throw Tools::IllegalStateException(s.str());
	}
#endif

	if (me < -std::numeric_limits<double>::epsilon() || me > std::numeric_limits<double>::epsilon())
	{
		size_t cIterations;

		if (cLiveEntries > m_pTree->m_nearMinimumOverlapFactor)
		{
			// sort entries in increasing order of enlargement.
			::qsort(entries, cLiveEntries,
							sizeof(OverlapEntry*),
							OverlapEntry::compareEntries);
			assert(entries[0]->m_enlargement <= entries[m_children - 1]->m_enlargement);

			cIterations = m_pTree->m_nearMinimumOverlapFactor;
		}
		else
		{
			cIterations = cLiveEntries;
		}

		// calculate overlap of most important original entries (near minimum overlap cost).
		for (size_t cIndex = 0; cIndex < cIterations; cIndex++)
		{
			double dif = 0.0;
			OverlapEntry* e = entries[cIndex];

			for (size_t cChild = 0; cChild < cLiveEntries; cChild++)
			{
				if (cIndex != cChild)
				{
					double f = e->m_combined->getIntersectingArea(*(entries[cChild]->m_original));
					if (f != 0.0) dif += f - e->m_original->getIntersectingArea(*(entries[cChild]->m_original));
				}
			} // for (cChild)

			if (dif < leastOverlap)
			{
				leastOverlap = dif;
				best = e;
			}
			else if (dif == leastOverlap)
			{
				if (e->m_enlargement == best->m_enlargement)
				{
					// keep the one with least area.
					if (e->m_original->getArea() < best->m_original->getArea()) best = e;
				}
				else
				{
					// keep the one with least enlargement.
					if (e->m_enlargement < best->m_enlargement) best = e;
				}
			}
		} // for (cIndex)
	}

	size_t ret = best->m_index;

	for (size_t cChild = 0; cChild < cLiveEntries; cChild++)
	{
		delete entries[cChild];
	}
	delete[] entries;

	return ret;
}

void Index::adjustTree(Node* n, std::stack<id_type>& pathBuffer)
{
	m_pTree->m_stats.m_adjustments++;

	// find entry pointing to old node;
	size_t child;
	for (child = 0; child < m_children; child++)
	{
		if (m_pIdentifier[child] == n->m_identifier) break;
	}

	// MBR needs recalculation if either:
	//   1. the NEW child MBR is not contained.
	//   2. the OLD child MBR is touching.
	bool bContained = m_nodeMBR.containsRegion(n->m_nodeMBR);
	bool bTouches = m_nodeMBR.touchesRegion(*(m_ptrMBR[child]));
	bool bRecompute = (! bContained || (bTouches && m_pTree->m_bTightMBRs));

	// we should not adjust time here
	double st = m_ptrMBR[child]->m_startTime;
	double en = m_ptrMBR[child]->m_endTime;
	*(m_ptrMBR[child]) = n->m_nodeMBR;
	m_ptrMBR[child]->m_startTime = st;
	m_ptrMBR[child]->m_endTime = en;

	if (bRecompute)
	{
		// no need to update times here. The inserted MBR is younger than all nodes.

		for (size_t cDim = 0; cDim < m_nodeMBR.m_dimension; cDim++)
		{
			m_nodeMBR.m_pLow[cDim] = std::numeric_limits<double>::max();
			m_nodeMBR.m_pHigh[cDim] = -std::numeric_limits<double>::max();

			for (size_t cChild = 0; cChild < m_children; cChild++)
			{
				m_nodeMBR.m_pLow[cDim] = std::min(m_nodeMBR.m_pLow[cDim], m_ptrMBR[cChild]->m_pLow[cDim]);
				m_nodeMBR.m_pHigh[cDim] = std::max(m_nodeMBR.m_pHigh[cDim], m_ptrMBR[cChild]->m_pHigh[cDim]);
			}
		}
	}

	m_pTree->writeNode(this);

	if (bRecompute && (! pathBuffer.empty()))
	{
		id_type cParent = pathBuffer.top(); pathBuffer.pop();
		NodePtr ptrN = m_pTree->readNode(cParent);
		Index* p = static_cast<Index*>(ptrN.get());
		p->adjustTree(this, pathBuffer);
	}
}

void Index::adjustTree(Node* n, Node* nn, std::stack<id_type>& pathBuffer)
{
	m_pTree->m_stats.m_adjustments++;

	// find entry pointing to old node;
	size_t child, child2 = m_capacity;
	for (child = 0; child < m_children; child++)
	{
		if (m_pIdentifier[child] == nn->m_identifier) child2 = child;
		if (m_pIdentifier[child] == n->m_identifier) break;
	}

	if (child2 == m_capacity)
	{
		for (child2 = child + 1; child2 < m_children; child2++)
		{
			if (m_pIdentifier[child2] == nn->m_identifier) break;
		}
	}

	// MBR needs recalculation if either:
	//   1. the NEW child MBR is not contained.
	//   2. the OLD child MBR is touching.
	//   3. the SIBLING MBR is touching.
	bool b1 = m_nodeMBR.containsRegion(n->m_nodeMBR);
	bool b2 = m_nodeMBR.touchesRegion(*(m_ptrMBR[child]));
	bool b3 = m_nodeMBR.touchesRegion(*(m_ptrMBR[child2]));
	bool bRecompute = (! b1) || ((b2 || b3) && m_pTree->m_bTightMBRs);

	// we should not adjust time here
	double st = m_ptrMBR[child]->m_startTime;
	double en = m_ptrMBR[child]->m_endTime;
	*(m_ptrMBR[child]) = n->m_nodeMBR;
	m_ptrMBR[child]->m_startTime = st;
	m_ptrMBR[child]->m_endTime = en;

	st = m_ptrMBR[child2]->m_startTime;
	en = m_ptrMBR[child2]->m_endTime;
	*(m_ptrMBR[child2]) = nn->m_nodeMBR;
	m_ptrMBR[child2]->m_startTime = st;
	m_ptrMBR[child2]->m_endTime = en;

	if (bRecompute)
	{
		// no need to update times here. The inserted MBR is younger than all nodes.

		for (size_t cDim = 0; cDim < m_nodeMBR.m_dimension; cDim++)
		{
			m_nodeMBR.m_pLow[cDim] = std::numeric_limits<double>::max();
			m_nodeMBR.m_pHigh[cDim] = -std::numeric_limits<double>::max();

			for (size_t cChild = 0; cChild < m_children; cChild++)
			{
				m_nodeMBR.m_pLow[cDim] = std::min(m_nodeMBR.m_pLow[cDim], m_ptrMBR[cChild]->m_pLow[cDim]);
				m_nodeMBR.m_pHigh[cDim] = std::max(m_nodeMBR.m_pHigh[cDim], m_ptrMBR[cChild]->m_pHigh[cDim]);
			}
		}
	}

	m_pTree->writeNode(this);

	if (bRecompute && (! pathBuffer.empty()))
	{
		id_type cParent = pathBuffer.top(); pathBuffer.pop();
		NodePtr ptrN = m_pTree->readNode(cParent);
		Index* p = static_cast<Index*>(ptrN.get());
		p->adjustTree(this, pathBuffer);
	}
}
