#include "And.h"

Node* And::execute() {
    /*Node* f = first->execute();
    Node* s = second->execute();*/
    Node* f = first;
    Node* s = second;
    if (compatible(t::CONSTINT, f, s))
        return new Bool(new bool(getInt(first) && getInt(second)));
    throw std::exception("Cannot cast expression to bool");
}
