// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaCoordinateListener.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RDocumentInterface.h"
            
            
        // includes for base ecma wrapper classes
         void REcmaCoordinateListener::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RCoordinateListener*) 0)));
        protoCreated = true;
    }

    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, updateCoordinate, "updateCoordinate");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RCoordinateListener*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RCoordinateListener",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaCoordinateListener::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
           return REcmaHelper::throwError("Abstract class RCoordinateListener: Cannot be constructed.",
               context); 
    }
    

    // conversion functions for base classes:
    

    // returns class name:
     QScriptValue REcmaCoordinateListener::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RCoordinateListener"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaCoordinateListener::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaCoordinateListener::updateCoordinate
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaCoordinateListener::updateCoordinate", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaCoordinateListener::updateCoordinate";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RCoordinateListener* self = 
                        getSelf("updateCoordinate", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RDocumentInterface * */
    
    ){
    // prepare arguments:
    
                    // argument is pointer
                    RDocumentInterface * a0 = NULL;

                    a0 = 
                        REcmaHelper::scriptValueTo<RDocumentInterface >(
                            context->argument(0)
                        );
                    
                    if (a0==NULL && 
                        !context->argument(0).isNull()) {
                        return REcmaHelper::throwError("RCoordinateListener: Argument 0 is not of type RDocumentInterface *RDocumentInterface *.", context);                    
                    }
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->updateCoordinate(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RCoordinateListener.updateCoordinate().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaCoordinateListener::updateCoordinate", context, engine);
            return result;
        }
         QScriptValue REcmaCoordinateListener::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RCoordinateListener* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RCoordinateListener(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaCoordinateListener::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RCoordinateListener* self = getSelf("RCoordinateListener", context);
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
    RCoordinateListener* REcmaCoordinateListener::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RCoordinateListener* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RCoordinateListener >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RCoordinateListener.%1(): "
                        "This object is not a RCoordinateListener").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RCoordinateListener* REcmaCoordinateListener::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RCoordinateListener* selfBase = getSelf(fName, context);
                RCoordinateListener* self = dynamic_cast<RCoordinateListener*>(selfBase);
                //return REcmaHelper::scriptValueTo<RCoordinateListener >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RCoordinateListener.%1(): "
                    "This object is not a RCoordinateListener").arg(fName),
                    context);
            }

            return self;
            


        }
        