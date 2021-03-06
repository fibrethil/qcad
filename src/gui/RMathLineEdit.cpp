/**
 * Copyright (c) 2011-2013 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */
//#include <QtPlugin>

#include <QColor>
#include <QKeyEvent>
#include <QPalette>
#include <QTimer>
#include <QToolTip>

#include "RMainWindowQt.h"
#include "RMath.h"
#include "RMathLineEdit.h"
#include "RUnit.h"

RMathLineEdit::RMathLineEdit(QWidget* parent) :
    QLineEdit(parent), angle(false), integer(false), value(0.0), noEmit(false) {

    oriPalette = palette();
    slotTextChanged(text());
    originalToolTip = QString();
    QLineEdit::setToolTip("");

    connect(this, SIGNAL(textChanged(QString)),
       this, SLOT(slotTextChanged(QString)));

    connect(this, SIGNAL(textEdited(QString)),
       this, SLOT(slotTextEdited(QString)));
}

//int RMathLineEdit::getDefaultUnit() {
//    return (int)defaultUnit;
//}

//void RMathLineEdit::setDefaultUnit(int defaultUnit) {
//    this->defaultUnit = (RS::Unit)defaultUnit;
//}

void RMathLineEdit::slotTextChanged(const QString& text) {
    if (originalToolTip.isNull()) {
        // save original tooltip, typically set in designer:
        originalToolTip = toolTip();
        if (originalToolTip.isNull()) {
            originalToolTip = "";
        }
    }

    value = RMath::eval(text);

    QPalette p = palette();
    if (RMath::hasError()) {
        error = RMath::getError();
        //res = defaultValue;
        // special case: don't report an error for text between * 
        // (e.g. *VARIES* in property editor)
        if (!(text.startsWith('*') && text.endsWith('*'))) {
            p.setColor(QPalette::Text, QColor(Qt::red));
            setToolTip(error);
        }
    }
    else {
        error = "";
        p.setColor(QPalette::Text, QColor(Qt::black));
        QString str;
        //str.sprintf("%.6g%s",value,(const char*)RUnit::unitToSymbol(defaultUnit).toUtf8());
        str.sprintf("%.6g",value);
        setToolTip(str);
    }

    if (isEnabled()) {
        setPalette(p);
    } else {
        setPalette(oriPalette);
    }

    if (!RMath::isNaN(value) && isAngle()) {
        value = RMath::deg2rad(value);
    }

    /*if (parentWidget()!=NULL && isVisible()) {
        QPoint tPos = parentWidget()->mapToGlobal(pos());
        tPos+=QPoint(0, height());
        QToolTip::showText(tPos, toolTip(), this);

        // TODO: improved tool tip for result display:
//        if (resultTip==NULL) {
//            resultTip = new QLabel(toolTip(), RMainWindowQt::getMainWindow());
//            resultTip->resize(resultTip->sizeHint());
//            resultTip->move(tPos);
//            QPalette lp = resultTip->palette();
//    //        if (RMath::hasError()) {
//    //            lp.setColor(QPalette::Text, Qt::red);
//    //        }
//    //        else {
//    //            lp.setColor(QPalette::Text, Qt::black);
//    //        }
//            lp.setColor(QPalette::Window, Qt::yellow);
//            resultTip->setPalette(lp);
//        }

//        resultTip->show();
//        QTimer::singleShot(2000, resultTip, "hide");
    }*/

    if (!noEmit) {
        emit valueChanged(value, error);
    }
}

void RMathLineEdit::slotTextEdited(const QString& text) {
    noEmit = true;
    // make sure that value and error message are up to date:
    slotTextChanged(text);
    noEmit = false;

    if (parentWidget()!=NULL && isVisible()) {
        QPoint tPos = parentWidget()->mapToGlobal(pos());
        tPos+=QPoint(0, height());
        QToolTip::showText(tPos, toolTip(), this);

        // TODO: improved tool tip for result display:
        //        if (resultTip==NULL) {
        //            resultTip = new QLabel(toolTip(), RMainWindowQt::getMainWindow());
        //            resultTip->resize(resultTip->sizeHint());
        //            resultTip->move(tPos);
        //            QPalette lp = resultTip->palette();
        //    //        if (RMath::hasError()) {
        //    //            lp.setColor(QPalette::Text, Qt::red);
        //    //        }
        //    //        else {
        //    //            lp.setColor(QPalette::Text, Qt::black);
        //    //        }
        //            lp.setColor(QPalette::Window, Qt::yellow);
        //            resultTip->setPalette(lp);
        //        }

        //        resultTip->show();
        //        QTimer::singleShot(2000, resultTip, "hide");
    }
}

void RMathLineEdit::setValue(double v, int precision) {
    if (isAngle()) {
        v = RMath::rad2deg(v);
    }
    setText(QString("%1").arg(v, 0, 'g', precision));
}

double RMathLineEdit::getValue() {
    if (isInteger()) {
        return RMath::mround(value);
    }
    else {
        return value;
    }
}

QString RMathLineEdit::getError() {
    return error;
}

void RMathLineEdit::clearError() {
    error = "";
    QPalette p = palette();
    p.setColor(QPalette::Text, QColor(Qt::black));
    setPalette(p);
}


void RMathLineEdit::setToolTip(const QString& toolTip) {
    QLineEdit::setToolTip(
        QString(
            "%1%2"
            "<span style=\""
                "color: %3; "
                "font-size: small; "
                "font-family: monospace"
            "\">%4</span>"
        )
        .arg(originalToolTip)
        .arg(originalToolTip.isEmpty() ? "" : "<br>")
        .arg(error.isEmpty() ? "black" : "red")
        .arg(toolTip)
    );
}

void RMathLineEdit::keyPressEvent (QKeyEvent* event) {
    if (event->key()==Qt::Key_Escape) {
        clearFocus();
        event->accept();
    }
    else {
        QLineEdit::keyPressEvent(event);
    }
}

void RMathLineEdit::keyReleaseEvent (QKeyEvent* event) {
    if (event->key()==Qt::Key_Escape) {
        event->accept();
    }
    else {
        QLineEdit::keyReleaseEvent(event);
    }
}
