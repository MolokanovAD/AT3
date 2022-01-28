#include "ElemMult.h"

Node* ElemMult::execute() {
	/*auto f = first->execute();
	auto s = second->execute();*/
	Node* f = nullptr, * s = nullptr;
	try {
		f = operand[0]->execute();
		s = operand[1]->execute();
	}
	catch (std::exception& ex) {
		throw ex;
	}
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
		std::vector<std::vector<int*>> res(rows, std::vector<int*>(columns, nullptr));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				res[i][j] = new int(0);
				if (i < matrix1.size() && i < matrix2.size() && j < matrix1.front().size() && j < matrix2.front().size())
					*res[i][j] = (*matrix1[i][j]) * (*matrix2[i][j]);
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
		auto res = std::vector<int*>(vec1.size() > vec2.size() ? vec1.size() : vec2.size(), nullptr);
		int maxSize = vec1.size() > vec2.size() ? vec1.size() : vec2.size();
		//if(vec1.size() != vec2.size())
		//	throw std::exception("Different sizes");
		for (int i = 0; i < maxSize;i++) {
			res[i] = new int(0);
			if (i < vec1.size() && i < vec2.size())
				*res[i] = (*vec1[i]) * (*vec2[i]);
		}
		return new IntArray(res);
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
	throw std::exception(errStr.c_str());
}
