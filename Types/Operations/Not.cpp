#include "Not.h"

Node* Not::execute() {
    Node* val = nullptr;
    try {
        val = operand[0]->execute();
    }
    catch (std::exception& ex) {
        throw ex;
    }
    ConstBool* boolVal = dynamic_cast<ConstBool*>(val);
    if (boolVal)
        return new Bool(new bool(!boolVal->getValue()),line);
    ConstInt* intVal = dynamic_cast<ConstInt*>(val);
    if (intVal)
        return new Bool(new bool(!intVal->getValue()),line);
}
