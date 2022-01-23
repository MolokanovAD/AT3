#include "MatrixMult.h"

Node* MatrixMult::execute() {
	auto f = dynamic_cast<ConstIntMatrix*>(first->execute());
	auto s = dynamic_cast<ConstIntMatrix*>(second->execute());
	if (!f || !s)
		throw std::exception("Wrong parameters");
	if (f->getRow(0)->getValue().size() != s->getColumn(0)->getValue().size())
		throw std::exception("Cannot multiply, incompatible size");
	auto m1 = f->getMatrix(), m2 = s->getMatrix();
	std::vector<std::vector<int>> result(m1.size(), std::vector<int>(m2.front().size(), 0));
	for (int i = 0; i < m1.size(); i++) {//for each row in m1
		for (int k = 0; k < m2.front().size(); k++) {//for each column in m2
			for (int j = 0; j < m1.front().size(); j++) {//for each element in current row of m1
				result[i][k] += m1[i][j] * m2[j][k];
			}
		}
	}
	return new IntMatrix(result);
}
