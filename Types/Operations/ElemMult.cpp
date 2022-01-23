#include "ElemMult.h"

Node* ElemMult::execute() {
	auto f = first->execute();
	auto s = second->execute();
	auto m1 = dynamic_cast<ConstIntMatrix*>(f);
	auto m2 = dynamic_cast<ConstIntMatrix*>(s);
	if (m1 && m2) {//both matrix
		auto matrix1 = m1->getMatrix();
		auto matrix2 = m2->getMatrix();
		//if (matrix1.size() != matrix2.size() || matrix1.front().size() != matrix2.front().size())
		//	throw std::exception("Different sizes");
		//int rows = matrix1.size();
		//int columns = matrix1.front().size();
		int rows = matrix1.size() > matrix2.size() ? matrix1.size() : matrix2.size();
		int columns = matrix1.front().size() > matrix2.front().size() ? matrix1.front().size() : matrix2.front().size();
		std::vector<std::vector<int>> res(rows, std::vector<int>(columns, 0));
		for (int i = 0; i < matrix1.size() && i < matrix2.size(); i++) {
			for (int j = 0; j < matrix1.front().size() && j < matrix2.front().size(); j++) {
				res[i][j] = matrix1[i][j] * matrix2[i][j];
				//matrix1[i][j] *= matrix2[i][j];
			}
		}
		return new IntMatrix(res);
		//return new IntMatrix(matrix1);
	}
	auto v1 = dynamic_cast<ConstIntArray*>(f);
	auto v2 = dynamic_cast<ConstIntArray*>(s);
	if (v1 && v2) {
		auto vec1 = v1->getValue();
		auto vec2 = v2->getValue();
		auto res = std::vector<int>(vec1.size() > vec2.size() ? vec1.size() : vec2.size(), 0);
		//if(vec1.size() != vec2.size())
		//	throw std::exception("Different sizes");
		for (int i = 0; i < vec1.size() && i < vec2.size();i++) {
			res[i] = vec1[i] * vec2[i];
		}
		return new IntArray(res);
	}
	throw std::exception("Wrong operands");
}
