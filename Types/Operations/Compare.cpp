#include "Compare.h"

Node* Compare::execute() {
    Node* f = nullptr, * s = nullptr;
    try {
        f = operand[0]->execute();
        s = operand[1]->execute();
    }
    catch (std::exception& ex) {
        throw ex;
    }
    if (compatible(t::CONSTINT, f, s))
        return new Bool(bigger ? new bool((getInt(f) > getInt(s))) : new bool((getInt(f) < getInt(s))),line);
    std::string errStr = "Error: Incomparable operands, line " + std::to_string(line);
    throw std::exception(errStr.c_str());
}
