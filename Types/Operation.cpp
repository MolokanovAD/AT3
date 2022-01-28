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

Operation::Operation(const Operation& op) {
    for (auto i : op.operand) {
        operand.push_back(i->clone());
    }
}

Node* Operation::operator[](int index) {
    if (index > -1 && index < operand.size()) {
        return operand[index];
    }
    throw std::exception("Out of range");
}

Operation::~Operation() {
    for (auto& i : operand)
        delete i;
    operand.clear();
}