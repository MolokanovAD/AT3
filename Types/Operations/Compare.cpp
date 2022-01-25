#include "Compare.h"

Node* Compare::execute() {
    /*Node* f = first->execute();
    Node* s = second->execute();*/
    Node* f = first;
    Node* s = second;
    if (compatible(t::CONSTINT, f, s))
        return new Bool(bigger ? new bool((getInt(first) > getInt(second))) : new bool((getInt(first) < getInt(second))));
    throw std::exception("Wrong operands");
}
