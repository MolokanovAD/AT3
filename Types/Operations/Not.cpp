#include "Not.h"

Node* Not::execute() {
    //Node* val = first->execute();
    Node* val = first;
    ConstBool* boolVal = dynamic_cast<ConstBool*>(val);
    if (boolVal)
        return new Bool(new bool(!boolVal->getValue()));
    ConstInt* intVal = dynamic_cast<ConstInt*>(val);
    if (intVal)
        return new Bool(new bool(!intVal->getValue()));
}
