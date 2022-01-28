#include "MatrixMult.h"

Node* MatrixMult::execute() {
	ConstIntMatrix* f = nullptr, * s = nullptr;
	try {
		f = dynamic_cast<ConstIntMatrix*>(operand[0]->execute());
		s = dynamic_cast<ConstIntMatrix*>(operand[1]->execute());
	}
	catch (std::exception& ex) {
		throw ex;
	}
	/*auto f = dynamic_cast<ConstIntMatrix*>(operand[0]);
	auto s = dynamic_cast<ConstIntMatrix*>(operand[1]);*/
	if (!f || !s) {
		std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
	if (f->getRow(0)->getValue().size() != s->getColumn(0)->getValue().size()) {
		std::string errStr = "Error: Size mismatch, line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
	auto m1 = f->getMatrix(), m2 = s->getMatrix();
	std::vector<std::vector<int*>> result(m1.size(), std::vector<int*>(m2.front().size(), nullptr));
	for (int i = 0; i < m1.size(); i++) {//for each row in m1
		for (int k = 0; k < m2.front().size(); k++) {//for each column in m2
			result[i][k] = new int(0);
			for (int j = 0; j < m1.front().size(); j++) {//for each element in current row of m1
				*result[i][k] += (*m1[i][j]) * (*m2[j][k]);
			}
		}
	}
	return new IntMatrix(result,line);
}
