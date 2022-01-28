#include "Functions.h"

bool compatible(Node* first, Node* second) {
	if ((dynamic_cast<ConstInt*>(first)) || (dynamic_cast<ConstBool*>(first)) && (dynamic_cast<ConstInt*>(second)) || (dynamic_cast<ConstBool*>(second)))//both int or bool
		return true;
	if(dynamic_cast<ConstIntArray*>(first) && dynamic_cast<ConstIntArray*>(second))//both int arrays
		return true;
	if (dynamic_cast<ConstBoolArray*>(first) && dynamic_cast<ConstBoolArray*>(second))//both bool arrays
		return true;
	if (dynamic_cast<ConstIntMatrix*>(first) && dynamic_cast<ConstIntMatrix*>(second))//both int matrices
		return true;
	if (dynamic_cast<ConstBoolMatrix*>(first) && dynamic_cast<ConstBoolMatrix*>(second))//both bool matrices
		return true;
	return false;
}

bool compatible(t type, Node* node) {
	if ((type == t::CONSTINT || type == t::CONSTBOOL || type == t::VARINT || type == t::VARBOOL) && (dynamic_cast<ConstInt*>(node) || dynamic_cast<ConstBool*>(node)))//both int or bool 
		return true;
	if ((type == t::CONSTINTARR || type == t::INTARR) && dynamic_cast<ConstIntArray*>(node))//both int arrays
		return true;
	if ((type == t::CONSTBOOLARR || type == t::BOOLARR) && dynamic_cast<ConstBoolArray*>(node))//both bool arrays
		return true;
	if ((type == t::CONSTINTMATRIX || type == t::INTMATRIX) && dynamic_cast<ConstIntMatrix*>(node))//both int matrices
		return true;
	if ((type == t::CONSTBOOLMATRIX || type == t::BOOLMATRIX) && dynamic_cast<ConstBoolMatrix*>(node))//both bool matrices
		return true;
	return false;
}

bool compatible(t type, Node* first, Node* second) {
	return compatible(type, first) && compatible(type, second);
}

bool addable(Node* first, Node* second) {
	if ((dynamic_cast<ConstInt*>(first)) || (dynamic_cast<ConstBool*>(first)) && (dynamic_cast<ConstInt*>(second)) || (dynamic_cast<ConstBool*>(second)))//both int or bool
		return true;
	if (dynamic_cast<ConstIntArray*>(first) && dynamic_cast<ConstIntArray*>(second))//both int arrays
		return true;
	if (dynamic_cast<ConstIntMatrix*>(first) && dynamic_cast<ConstIntMatrix*>(second))//both int matrices
		return true;
	return false;
}

int toInt(Node* n) {
	auto cInt = dynamic_cast<ConstInt*>(n);
	if (cInt)
		return cInt->getValue();
	auto cBool = dynamic_cast<ConstBool*>(n);
	if (cBool)
		return cBool->getValue();
	throw std::exception("Not compatible");
}

Node* createContainer(Node* child) {
	switch (child->type()) 	{
		case VARBOOL:
			return new BoolArray({ dynamic_cast<ConstBool*>(child)->pop() });
		case CONSTBOOL:
			return new BoolArray({ dynamic_cast<ConstBool*>(child)->pop() });
		case VARINT:
			return new IntArray({ dynamic_cast<ConstInt*>(child)->pop() });
		case CONSTINT:
			return new IntArray({ dynamic_cast<ConstInt*>(child)->pop() });
		case INTARR:
			return new IntMatrix({ dynamic_cast<ConstIntArray*>(child)->pop() });
		case CONSTINTARR:
			return new IntMatrix({ dynamic_cast<ConstIntArray*>(child)->pop() });
		case BOOLARR:
			return new BoolMatrix({ dynamic_cast<ConstBoolArray*>(child)->pop() });
		case CONSTBOOLARR:
			return new BoolMatrix({ dynamic_cast<ConstBoolArray*>(child)->pop() });
		default:
			std::string errStr = "Error: Variable required, line " + std::to_string(child->getLine());
			throw std::exception(errStr.c_str());
	}
}

ConstInt* getIntValue(Node* m, Node* f, Node* s, int l) {
	auto matrix = dynamic_cast<ConstIntMatrix*>(m);
	if (matrix) {
		auto i = dynamic_cast<ConstInt*>(f);
		if (i) {
			auto j = dynamic_cast<ConstInt*>(s);
			if (j) {
				try {
					return matrix->getValue(i->getValue(), j->getValue(), l);
				}
				catch (std::exception& ex) {
					throw ex;
				}
			}
		}
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(l);
	throw std::exception(errStr.c_str());
}
ConstBool* getBoolValue(Node* m, Node* f, Node* s, int l) {
	auto matrix = dynamic_cast<ConstBoolMatrix*>(m);
	if (matrix) {
		auto i = dynamic_cast<ConstInt*>(f);
		if (i) {
			auto j = dynamic_cast<ConstInt*>(s);
			if (j) {
				try {
					return matrix->getValue(i->getValue(), j->getValue(),l);
				}
				catch (std::exception& ex) {
					throw ex;
				}
			}
		}
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(l);
	throw std::exception(errStr.c_str());
}

ConstIntArray* getIntVec(Node* m, Node* r, bool mode, int l) {
	auto matrix = dynamic_cast<ConstIntMatrix*>(m);
	auto row = dynamic_cast<ConstInt*>(r);
	if (matrix) {
		if (row) {
			try {
				return mode ? matrix->getRow(row->getValue()) : matrix->getColumn(row->getValue());
			}
			catch (std::exception& ex) {
				throw ex;
			}
		}
		else {
			std::string errStr = "Error: Index expected, line " + std::to_string(l);
			throw std::exception(errStr.c_str());
		}
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(l);
	throw std::exception(errStr.c_str());
}
ConstBoolArray* getBoolVec(Node* m, Node* r, bool mode, int l) {
	auto matrix = dynamic_cast<ConstBoolMatrix*>(m);
	auto row = dynamic_cast<ConstInt*>(r);
	if (matrix) {
		if (row) {
			try {
				return mode ? matrix->getRow(row->getValue()) : matrix->getColumn(row->getValue());
			}
			catch (std::exception& ex) {
				throw ex;
			}
		}
		else {
			std::string errStr = "Error: Index expected, line " + std::to_string(l);
			throw std::exception(errStr.c_str());
		}
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(l);
	throw std::exception(errStr.c_str());
}

Node* getVec(Node* m, Node* r, bool mode, int l) {
	try {
		return getIntVec(m, r, mode, l);
	}
	catch (std::exception& ex1) {
		try {
			return getBoolVec(m, r, mode, l);
		}
		catch (std::exception& ex2) {
			throw ex2;
		}
		throw ex1;
	}
}

ConstIntMatrix* getIntMatrix(Node* m, Node* r, bool mode, int l) {
	auto vec = dynamic_cast<ConstIntArray*>(r);
	auto mx = dynamic_cast<ConstIntMatrix*>(m);
	std::vector<std::vector<int*>> matrix;
	if (vec && mx) {
		auto val = vec->getValue();
		for (int i = 0; i < val.size(); i++) {
			Int* index = new Int(new int(*val[i]));
			try {
				auto ptr = getIntVec(m, index, mode, l);
				matrix.push_back(ptr->pop());
				delete ptr;
			}
			catch (std::exception& ex) {
				delete index;
				throw ex;
			}
			delete index;
		}
	}
	else {
		std::string errStr = "Error: Type mismatch, line " + std::to_string(l);
		throw std::exception(errStr.c_str());
	}
	if (!mode) {
		std::vector<std::vector<int*>> resMatrix(matrix.front().size(), std::vector<int*>(matrix.size(),nullptr));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.front().size(); j++) {
				resMatrix[j][i] = matrix[i][j];
			}
		}
		return dynamic_cast<IntMatrix*>(m) ? new IntMatrix(resMatrix, l) : new ConstIntMatrix(resMatrix, t::CONSTINTMATRIX, l);
	}
	return dynamic_cast<IntMatrix*>(m) ? new IntMatrix(matrix,l) : new ConstIntMatrix(matrix,t::CONSTINTMATRIX,l);
}

ConstBoolMatrix* getBoolMatrix(Node* m, Node* r, bool mode, int l) {
	auto mx = dynamic_cast<ConstBoolMatrix*>(m);
	auto vec = dynamic_cast<ConstIntArray*>(r);
	std::vector<std::vector<bool*>> matrix;
	if (vec && mx) {
		auto val = vec->getValue();
		for (int i = 0; i < val.size(); i++) {
			Int* index = new Int(new int(*val[i]));
			try {
				auto ptr = getBoolVec(m, index, mode, l);
				matrix.push_back(ptr->pop());
				delete ptr;
			}
			catch (std::exception& ex) {
				delete index;
				throw ex;
			}
			delete index;
		}
	}
	else {
		std::string errStr = "Error: Type mismatch, line " + std::to_string(l);
		throw std::exception(errStr.c_str());
	}
	if (!mode) {
		std::vector<std::vector<bool*>> resMatrix(matrix.front().size(), std::vector<bool*>(matrix.size(), nullptr));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.front().size(); j++) {
				resMatrix[j][i] = matrix[i][j];
			}
		}
		return dynamic_cast<BoolMatrix*>(m) ? new BoolMatrix(resMatrix, l) : new ConstBoolMatrix(resMatrix, t::CONSTINTMATRIX, l);
	}
	return dynamic_cast<BoolMatrix*>(m) ? new BoolMatrix(matrix,l) : new ConstBoolMatrix(matrix,t::CONSTBOOLMATRIX,l);
}

Node* getMatrix(Node* m, Node* r, bool mode, int l) {
	try {
		return getIntMatrix(m, r, mode, l);
	}
	catch (std::exception& ex1) {
		try {
			return getBoolMatrix(m, r, mode, l);
		}
		catch (std::exception& ex2) {
			throw ex2;
		}
		throw ex1;
	}
}

ConstIntMatrix* intMatrixFromLogical(Node* m, Node* r,int errline) {
	auto i = dynamic_cast<ConstIntMatrix*>(m);
	auto l = dynamic_cast<ConstBoolMatrix*>(r);
	std::vector<std::vector<int*>> res;
	if (i && l) {
		auto iMatrix = i->getMatrix();
		auto lMatrix = l->getMatrix();
		if (iMatrix.size() != lMatrix.size() || iMatrix.front().size() != lMatrix.front().size()) {
			std::string errStr = "Error: Size mismatch, line " + std::to_string(errline);
			throw std::exception(errStr.c_str());
		}
		for (int k = 0; k < lMatrix.size(); k++) {
			std::vector<int*> line;
			for (int j = 0; j < lMatrix.front().size(); j++) {
				if (*lMatrix[k][j])
					line.push_back(iMatrix[k][j]);
			}
			if (!res.empty() && line.size() != res.front().size() && line.size() != 0) {
				std::string errStr = "Error: Incorrect logical matrix, line " + std::to_string(errline);
				throw std::exception(errStr.c_str());
			}
			if(line.size())
				res.push_back(line);
		}
	}
	else {
		std::string errStr = "Error: Type mismatch, line " + std::to_string(errline);
		throw std::exception(errStr.c_str());
	}
	return dynamic_cast<IntMatrix*>(m) ? new IntMatrix(res) : new ConstIntMatrix(res);
}

ConstBoolMatrix* boolMatrixFromLogical(Node* m, Node* r, int errline) {
	auto i = dynamic_cast<ConstBoolMatrix*>(m);
	auto l = dynamic_cast<ConstBoolMatrix*>(r);
	std::vector<std::vector<bool*>> res;
	if (i && l) {
		auto iMatrix = i->getMatrix();
		auto lMatrix = l->getMatrix();
		if (iMatrix.size() != lMatrix.size() || iMatrix.front().size() != lMatrix.front().size()) {
			std::string errStr = "Error: Size mismatch, line " + std::to_string(errline);
			throw std::exception(errStr.c_str());
		}
		std::vector<bool*> line;
		for (int k = 0; k < lMatrix.size(); k++) {
			for (int j = 0; j < lMatrix.front().size(); j++) {
				if (*lMatrix[k][j])
					line.push_back(iMatrix[k][j]);
			}
			if (!res.empty() && line.size() != res.front().size() && line.size() != 0) {
				std::string errStr = "Error: Incorrect logical matrix, line " + std::to_string(errline);
				throw std::exception(errStr.c_str());
			}
			if (line.size())
				res.push_back(line);
		}
	}
	else {
		std::string errStr = "Error: Type mismatch, line " + std::to_string(errline);
		throw std::exception(errStr.c_str());
	}
	return dynamic_cast<BoolMatrix*>(m) ? new BoolMatrix(res, errline) : new ConstBoolMatrix(res,t::CONSTBOOLMATRIX, errline);
}

Node* matrixFromLogical(Node* m, Node* r, int l) {
	try {
		return intMatrixFromLogical(m, r,l);
	}
	catch (std::exception& ex1) {
		try {
			return boolMatrixFromLogical(m, r,l);
		}
		catch (std::exception& ex2) {
			throw ex2;
		}
		throw ex1;
	}
}

ConstIntArray* intArrayFromArray(Node* m, Node* r, int line) {
	auto arr = dynamic_cast<ConstIntArray*>(m);
	auto logic = dynamic_cast<ConstBoolArray*>(r);
	if (arr && logic) {
		if (arr->size() == logic->size()) {
			auto v = arr->getValue();
			auto l = logic->getValue();
			std::vector<int*> res;
			for (int i = 0; i < l.size(); i++) {
				if(*l[i])
					res.push_back(v[i]);
			}
			return dynamic_cast<IntArray*>(m) ? new IntArray(res, line) : new ConstIntArray(res, t::CONSTINTARR, line);
		}
		else {
			std::string errStr = "Error: Size mismatch, line " + std::to_string(line);
			throw std::exception(errStr.c_str());
		}
	}
	else {
		auto numbers = dynamic_cast<ConstIntArray*>(r);
		if (arr && numbers) {
			auto v = arr->getValue();
			auto num = numbers->getValue();
			std::vector<int*> res;
			for (int i = 0; i < num.size(); i++) {
				if (*num[i] > -1 && *num[i] < v.size())
					res.push_back(v[*num[i]]);
			}
			return dynamic_cast<IntArray*>(m) ? new IntArray(res, line) : new ConstIntArray(res, t::CONSTINTARR, line);
		}
		std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
}

ConstBoolArray* boolArrayFromArray(Node* m, Node* r, int line) {
	auto arr = dynamic_cast<ConstBoolArray*>(m);
	auto logic = dynamic_cast<ConstBoolArray*>(r);
	if (arr && logic) {
		if (arr->size() == logic->size()) {
			auto v = arr->getValue();
			auto l = logic->getValue();
			std::vector<bool*> res;
			for (int i = 0; i < l.size(); i++) {
				if (*l[i])
					res.push_back(v[i]);
			}
			return dynamic_cast<BoolArray*>(m) ? new BoolArray(res, line) : new ConstBoolArray(res, t::CONSTBOOLARR, line);
		}
		else {
			std::string errStr = "Error: Size mismatch, line " + std::to_string(line);
			throw std::exception(errStr.c_str());
		}
	}
	else {
		auto numbers = dynamic_cast<ConstIntArray*>(r);
		if (arr && numbers) {
			auto v = arr->getValue();
			auto num = numbers->getValue();
			std::vector<bool*> res;
			for (int i = 0; i < num.size(); i++) {
				if (*num[i] > -1 && *num[i] < v.size())
					res.push_back(v[*num[i]]);
			}
			return dynamic_cast<BoolArray*>(m) ? new BoolArray(res, line) : new ConstBoolArray(res, t::CONSTBOOLARR, line);
		}
		std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
}

Node* arrayFromArray(Node* m, Node* r, int l) {
	try {
		return intArrayFromArray(m, r, l);
	}
	catch (std::exception& ex1) {
		try {
			return boolArrayFromArray(m, r, l);
		}
		catch (std::exception& ex2) {
			throw ex2;
		}
		throw ex1;
	}
}

ConstBool* boolFromArray(Node* arr, int i, int l) {
	auto ar = dynamic_cast<ConstBoolArray*>(arr);
	if (ar) {
		bool* ptr = nullptr;
		try {
			ptr = ar->getVal(i);
		}
		catch (std::exception& ex) {
			throw ex;
		}
		return dynamic_cast<BoolArray*>(arr) ? new Bool(ptr, l) : new ConstBool(ptr, t::CONSTINT, l);
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(l);
	throw std::exception(errStr.c_str());
}

ConstInt* intFromArray(Node* arr, int i, int l) {
	auto ar = dynamic_cast<ConstIntArray*>(arr);
	if (ar) {
		int* ptr = nullptr;
		try {
			ptr = ar->getVal(i);
		}
		catch (std::exception& ex) {
			throw ex;
		}
		return dynamic_cast<IntArray*>(arr) ? new Int(ptr, l) : new ConstInt(ptr, t::CONSTINT, l);
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(l);
	throw std::exception(errStr.c_str());
}

Node* valFromArray(Node* arr, int i, int l) {
	try {
		return intFromArray(arr, i, l);
	}
	catch (std::exception& ex1) {
		try {
			return boolFromArray(arr, i, l);
		}
		catch (std::exception& ex2) {
			throw ex2;
		}
		throw ex1;
	}
}

bool isMatrix(Node* n) {
	return n->type() == CONSTBOOLMATRIX || n->type() == CONSTINTMATRIX || n->type() == INTMATRIX || n->type() == BOOLMATRIX;
}

bool isConst(Node* n) {
	if (n->type() == CONSTBOOLMATRIX || n->type() == CONSTINTMATRIX || n->type() == CONSTBOOLARR || n->type() == CONSTINTARR || n->type() == CONSTBOOL || n->type() == CONSTINT)
		return true;
	return false;
}

bool multiplicable(Node* f, Node* s) {
	return compatible(t::CONSTINTMATRIX, f, s);
}

std::vector<std::vector<char>> parseMap(const std::string& filename,int& xx, int& yy, int& dir) {
	std::ifstream in("Programs/labyrinth.txt");
	std::string l;
	if (in.is_open()) {
		int width, height;
		in >> width >> height >> xx >> yy >> dir;
		std::getline(in, l);
		auto res = std::vector<std::vector<char>>(height, std::vector<char>(width, ' '));
		for (int i = 0; i < height; i++) {
			std::getline(in, l);
			for (int j = 0; j < width; j++) {
				res[i][j] = l[j];
			}
		}
		in.close();
		return res;
	}
	else throw std::exception("Cannot open file");
}

void freeStacks(CallStack* cs, FunStack* fs) {
	for (auto& i : *cs->top()) {
		delete i.second;
	}
	cs->top()->clear();
	cs->pop();
	for (auto& i : *fs->top()) {
		delete i.second;
	}
	fs->top()->clear();
	fs->pop();
}

void printVarTable(std::map<std::string, Node*>* varTable) {
	std::cout << "Total " << varTable->size() << " variables" << std::endl;
	for (auto& i : *varTable) {
		std::cout << i.first << " : " << *i.second << std::endl;
	}
}

/*void printFunTable(std::map<std::string, Function*>& functionTable) {
	for (auto& i : functionTable) {
		std::cout << i.first << std::endl;
	}
}*/

bool isDirection(ConstIntArray* vec) {
	if (vec->size() == 2) {
		auto val = vec->getValue();
		if (*val[0] == 0 && (*val[1] == -1 || *val[1] == 1)) 
			return true;
		if (*val[1] == 0 && (*val[0] == -1 || *val[0] == 1))
			return true;
	}
	return false;
}