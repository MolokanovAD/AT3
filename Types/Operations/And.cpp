#include "And.h"

Node* And::execute() {
    Node* f = first->execute();
    Node* s = second->execute();
    if (compatible(t::CONSTINT, f, s))
        return new Bool(getInt(first) && getInt(second));
    throw std::exception("Cannot cast expression to bool");
}
