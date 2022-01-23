#include "Compare.h"

Node* Compare::execute() {
    Node* f = first->execute();
    Node* s = second->execute();
    if (compatible(t::CONSTINT, f, s))
        return new Bool(bigger ? (getInt(first) > getInt(second)) : (getInt(first) < getInt(second)));

    throw std::exception("Wrong operands");
}
