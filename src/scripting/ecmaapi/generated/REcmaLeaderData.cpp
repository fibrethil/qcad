// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaLeaderData.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaEntityData.h"
                
                  #include "REcmaPolyline.h"
                 void REcmaLeaderData::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RLeaderData*) 0)));
        protoCreated = true;
    }

    
        // primary base class REntityData:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<REntityData*>());

            if (dpt.isValid()) {
                proto->setPrototype(dpt);
            }
          
        /*
        REcmaPolyline::init(engine, proto);
          
        */
    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    
        // conversion for base class REntityData
        REcmaHelper::registerFunction(&engine, proto, getREntityData, "getREntityData");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, castToShape, "castToShape");
            
            REcmaHelper::registerFunction(&engine, proto, getDimasz, "getDimasz");
            
            REcmaHelper::registerFunction(&engine, proto, setArrowHead, "setArrowHead");
            
            REcmaHelper::registerFunction(&engine, proto, hasArrowHead, "hasArrowHead");
            
            REcmaHelper::registerFunction(&engine, proto, getEndPoint, "getEndPoint");
            
            REcmaHelper::registerFunction(&engine, proto, getStartPoint, "getStartPoint");
            
            REcmaHelper::registerFunction(&engine, proto, countVertices, "countVertices");
            
            REcmaHelper::registerFunction(&engine, proto, countSegments, "countSegments");
            
            REcmaHelper::registerFunction(&engine, proto, appendVertex, "appendVertex");
            
            REcmaHelper::registerFunction(&engine, proto, getReferencePoints, "getReferencePoints");
            
            REcmaHelper::registerFunction(&engine, proto, moveReferencePoint, "moveReferencePoint");
            
            REcmaHelper::registerFunction(&engine, proto, getExploded, "getExploded");
            
            REcmaHelper::registerFunction(&engine, proto, getShapes, "getShapes");
            
            REcmaHelper::registerFunction(&engine, proto, getArrowShape, "getArrowShape");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RLeaderData*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RLeaderData",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaLeaderData::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
    if (context->thisObject().strictlyEquals(
       engine->globalObject())) {
       return REcmaHelper::throwError(
       QString::fromLatin1("RLeaderData(): Did you forget to construct with 'new'?"),
           context);
    }

    QScriptValue result;
        
            // generate constructor variants:
            
    if( context->argumentCount() ==
        0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            RLeaderData
                    * cppResult =
                    new
                    RLeaderData
                    ();
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
    } else 

    if( context->argumentCount() ==
        2
                && (
                
                        context->argument(
                        0
                        ).isVariant()
                        ||
                    
                        context->argument(
                        0
                        ).isQObject()
                        ||
                    
                        context->argument(
                        0
                        ).isNull()
                ) /* type: RPolyline */
            
                && (
                
                        context->argument(
                        1
                        ).isBool()
                ) /* type: bool */
            
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RPolyline*
                    ap0 =
                    qscriptvalue_cast<
                    RPolyline*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("RLeaderData: Argument 0 is not of type RPolyline.",
                               context);                    
                    }
                    RPolyline 
                    a0 = 
                    *ap0;
                
                    // argument isStandardType
                    bool
                    a1 =
                    (bool)
                    
                    context->argument( 1 ).
                    toBool();
                
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            RLeaderData
                    * cppResult =
                    new
                    RLeaderData
                    (
                    a0
        ,
    a1
                    );
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
    } else 

    {
       return REcmaHelper::throwError(
       QString::fromLatin1("RLeaderData(): no matching constructor found."),
           context);
    }
    
    return result;
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaLeaderData::getREntityData(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                REntityData* cppResult =
                    qscriptvalue_cast<RLeaderData*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaLeaderData::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RLeaderData"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaLeaderData::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("REntityData");
    

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaLeaderData::castToShape
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::castToShape", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::castToShape";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("castToShape", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'RShape *'
    RShape * cppResult =
        
               self->castToShape();
        // return type: RShape *
                // RShape:
                result = REcmaHelper::toScriptValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.castToShape().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::castToShape", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::getDimasz
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::getDimasz", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::getDimasz";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("getDimasz", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'double'
    double cppResult =
        
               self->getDimasz();
        // return type: double
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.getDimasz().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::getDimasz", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::setArrowHead
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::setArrowHead", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::setArrowHead";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("setArrowHead", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isBool()
        ) /* type: bool */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    bool
                    a0 =
                    (bool)
                    
                    context->argument( 0 ).
                    toBool();
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->setArrowHead(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.setArrowHead().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::setArrowHead", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::hasArrowHead
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::hasArrowHead", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::hasArrowHead";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("hasArrowHead", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'bool'
    bool cppResult =
        
               self->hasArrowHead();
        // return type: bool
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.hasArrowHead().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::hasArrowHead", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::getEndPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::getEndPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::getEndPoint";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("getEndPoint", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'RVector'
    RVector cppResult =
        
               self->getEndPoint();
        // return type: RVector
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.getEndPoint().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::getEndPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::getStartPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::getStartPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::getStartPoint";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("getStartPoint", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'RVector'
    RVector cppResult =
        
               self->getStartPoint();
        // return type: RVector
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.getStartPoint().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::getStartPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::countVertices
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::countVertices", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::countVertices";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("countVertices", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'int'
    int cppResult =
        
               self->countVertices();
        // return type: int
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.countVertices().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::countVertices", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::countSegments
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::countSegments", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::countSegments";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("countSegments", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'int'
    int cppResult =
        
               self->countSegments();
        // return type: int
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.countSegments().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::countSegments", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::appendVertex
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::appendVertex", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::appendVertex";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("appendVertex", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RVector */
    
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RVector*
                    ap0 =
                    qscriptvalue_cast<
                    RVector*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("RLeaderData: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->appendVertex(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.appendVertex().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::appendVertex", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::getReferencePoints
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::getReferencePoints", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::getReferencePoints";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("getReferencePoints", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'QList < RVector >'
    QList < RVector > cppResult =
        
               self->getReferencePoints();
        // return type: QList < RVector >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isNumber()
        ) /* type: RS::ProjectionRenderingHint */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    RS::ProjectionRenderingHint
                    a0 =
                    (RS::ProjectionRenderingHint)
                    (int)
                    context->argument( 0 ).
                    toNumber();
                
    // end of arguments

    // call C++ function:
    // return type 'QList < RVector >'
    QList < RVector > cppResult =
        
               self->getReferencePoints(a0);
        // return type: QList < RVector >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.getReferencePoints().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::getReferencePoints", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::moveReferencePoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::moveReferencePoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::moveReferencePoint";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("moveReferencePoint", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    2 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RVector */
     && (
            context->argument(1).isVariant() || 
            context->argument(1).isQObject() || 
            context->argument(1).isNull()
        ) /* type: RVector */
    
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RVector*
                    ap0 =
                    qscriptvalue_cast<
                    RVector*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("RLeaderData: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RVector*
                    ap1 =
                    qscriptvalue_cast<
                    RVector*
                        >(
                        context->argument(
                        1
                        )
                    );
                    if (ap1 == NULL) {
                           return REcmaHelper::throwError("RLeaderData: Argument 1 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a1 = 
                    *ap1;
                
    // end of arguments

    // call C++ function:
    // return type 'bool'
    bool cppResult =
        
               self->moveReferencePoint(a0
        ,
    a1);
        // return type: bool
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.moveReferencePoint().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::moveReferencePoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::getExploded
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::getExploded", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::getExploded";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("getExploded", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'QList < QSharedPointer < RShape > >'
    QList < QSharedPointer < RShape > > cppResult =
        
               self->getExploded();
        // return type: QList < QSharedPointer < RShape > >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.getExploded().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::getExploded", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::getShapes
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::getShapes", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::getShapes";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("getShapes", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'QList < QSharedPointer < RShape > >'
    QList < QSharedPointer < RShape > > cppResult =
        
               self->getShapes();
        // return type: QList < QSharedPointer < RShape > >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RBox */
    
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RBox*
                    ap0 =
                    qscriptvalue_cast<
                    RBox*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("RLeaderData: Argument 0 is not of type RBox.",
                               context);                    
                    }
                    RBox 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'QList < QSharedPointer < RShape > >'
    QList < QSharedPointer < RShape > > cppResult =
        
               self->getShapes(a0);
        // return type: QList < QSharedPointer < RShape > >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.getShapes().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::getShapes", context, engine);
            return result;
        }
         QScriptValue
        REcmaLeaderData::getArrowShape
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLeaderData::getArrowShape", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLeaderData::getArrowShape";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLeaderData* self = 
                        getSelf("getArrowShape", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'RTriangle'
    RTriangle cppResult =
        
               self->getArrowShape();
        // return type: RTriangle
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLeaderData.getArrowShape().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLeaderData::getArrowShape", context, engine);
            return result;
        }
         QScriptValue REcmaLeaderData::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RLeaderData* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RLeaderData(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaLeaderData::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RLeaderData* self = getSelf("RLeaderData", context);
        //Q_ASSERT(self!=NULL);
        if (self==NULL) {
            return REcmaHelper::throwError("self is NULL", context);
        }
        
    
        delete self;
        context->thisObject().setData(engine->nullValue());
        context->thisObject().prototype().setData(engine->nullValue());
        context->thisObject().setPrototype(engine->nullValue());
        context->thisObject().setScriptClass(NULL);
        return engine->undefinedValue();
    }
    RLeaderData* REcmaLeaderData::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RLeaderData* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RLeaderData >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RLeaderData.%1(): "
                        "This object is not a RLeaderData").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RLeaderData* REcmaLeaderData::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RLeaderData* selfBase = getSelf(fName, context);
                RLeaderData* self = dynamic_cast<RLeaderData*>(selfBase);
                //return REcmaHelper::scriptValueTo<RLeaderData >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RLeaderData.%1(): "
                    "This object is not a RLeaderData").arg(fName),
                    context);
            }

            return self;
            


        }
        