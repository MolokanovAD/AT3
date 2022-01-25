#include "ExprSequence.h"

Node* ExprSequence::execute() {
	if (exprs.size() != 0) {
		Node* res = createContainer(exprs[0]->execute());
		for (int i = 1; i < exprs.size(); i++) {
			addElementToContainer(res, exprs[i]->execute());
		}
		return res;
	}
}