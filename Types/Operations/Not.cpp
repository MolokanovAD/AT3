#include "Not.h"

Node* Not::execute() {
    Node* val = first->execute();
    ConstBool* boolVal = dynamic_cast<ConstBool*>(val);
    if (boolVal)
        return new Bool(!boolVal->getValue());
    ConstInt* intVal = dynamic_cast<ConstInt*>(val);
    if (intVal)
        return new Bool(!intVal->getValue());
}
