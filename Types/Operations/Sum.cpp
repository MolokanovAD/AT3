#include "Sum.h"
Node* Sum::execute() {
	auto f = first->execute();
	if (f->type() == INTARR || f->type() == CONSTINTARR) {
		auto vec = dynamic_cast<ConstIntArray*>(f)->getValue();
		int res = 0;
		for (auto k : vec)
			res += k;
		return new Int(res);
	}
	if (f->type() == INTMATRIX || f->type() == CONSTINTMATRIX) {
		auto matrix = dynamic_cast<ConstIntMatrix*>(f)->getMatrix();
		int res = 0;
		for (auto& row : matrix) {
			for (auto val : row)
				res += val;
		}
		return new Int(res);
	}
	throw std::exception("Wrong parameter");
}