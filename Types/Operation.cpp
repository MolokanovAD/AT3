#include "Operation.h"
int Operation::getInt(Node* p) {
    auto cInt1 = dynamic_cast<ConstInt*>(p);
    if (cInt1)
        return cInt1->getValue();
    else {
        auto cBool1 = dynamic_cast<ConstBool*>(p);
        if (cBool1)
            return cBool1->getValue();
        else
            throw std::exception("Wrong parameter");
    }
}

//Operation::Operation(Node* f, Node* s) {
//    if (dynamic_cast<Operation*>(f))
//        first = f;
//    else if (dynamic_cast<Variable*>(f))
//        first = f->clone();
//    if (dynamic_cast<Operation*>(s))
//        second = s;
//    else if (dynamic_cast<Variable*>(s))
//        second = s->clone();
//}
