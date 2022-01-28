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


//bool insertVar(t type, std::string* id, Node* expr, std::map<std::string, Node*>& varTable) {
//	if (compatible(type, expr)) {
//		if (varTable.find(*id) == varTable.end()) {
//			switch (type) {
//				case VARBOOL:
//					return varTable.insert({ *id, new Bool(new bool(toInt(expr))) }).second;
//				case CONSTBOOL:
//					return varTable.insert({ *id, new ConstBool(new bool(toInt(expr))) }).second;
//				case VARINT:
//					return varTable.insert({ *id, new Int(new int(toInt(expr))) }).second;
//				case CONSTINT:
//					return varTable.insert({ *id, new ConstInt(new int(toInt(expr))) }).second;
//				case INTARR:
//					return varTable.insert({ *id, new IntArray(dynamic_cast<ConstIntArray*>(expr)->pop()) }).second;
//				case CONSTINTARR:
//					return varTable.insert({ *id, new ConstIntArray(dynamic_cast<ConstIntArray*>(expr)->pop()) }).second;
//				case BOOLARR:
//					return varTable.insert({ *id, new BoolArray(dynamic_cast<ConstBoolArray*>(expr)->pop()) }).second;
//				case CONSTBOOLARR:
//					return varTable.insert({ *id, new ConstBoolArray(dynamic_cast<ConstBoolArray*>(expr)->pop()) }).second;
//				case INTMATRIX:
//					return varTable.insert({ *id, new IntMatrix(dynamic_cast<ConstIntMatrix*>(expr)->pop()) }).second;
//				case CONSTINTMATRIX:
//					return varTable.insert({ *id, new ConstIntMatrix(dynamic_cast<ConstIntMatrix*>(expr)->pop()) }).second;
//				case BOOLMATRIX:
//					return varTable.insert({ *id, new BoolMatrix(dynamic_cast<ConstBoolMatrix*>(expr)->pop()) }).second;
//				case CONSTBOOLMATRIX:
//					return varTable.insert({ *id, new ConstBoolMatrix(dynamic_cast<ConstBoolMatrix*>(expr)->pop()) }).second;
//				default:
//					throw std::exception(std::to_string(expr->getLine()).c_str());
//			}
//		}
//	}
//	else {
//		std::string errStr = "Error: type mismatch, line " + std::to_string(expr->getLine());
//		throw std::exception(errStr.c_str());
//	}
//}

//Node* assignVar(t type, Node* expr) {
//	if (compatible(type, expr)) {
//		switch (type) {
//			case VARBOOL:
//				return new Bool(new bool(toInt(expr)));
//			/*case CONSTBOOL:
//				return  new ConstBool(new bool(toInt(expr)));*/
//			case VARINT:
//				return new Int(new int(toInt(expr)));
//			/*case CONSTINT:
//				return new ConstInt(new int(toInt(expr)));*/
//			case INTARR:
//				return new IntArray(dynamic_cast<ConstIntArray*>(expr)->pop());
//			/*case CONSTINTARR:
//				return new ConstIntArray(dynamic_cast<ConstIntArray*>(expr)->pop());*/
//			case BOOLARR:
//				return new BoolArray(dynamic_cast<ConstBoolArray*>(expr)->pop());
//			/*case CONSTBOOLARR:
//				return new ConstBoolArray(dynamic_cast<ConstBoolArray*>(expr)->pop());*/
//			case INTMATRIX:
//				return new IntMatrix(dynamic_cast<ConstIntMatrix*>(expr)->pop());
//			/*case CONSTINTMATRIX:
//				return new ConstIntMatrix(dynamic_cast<ConstIntMatrix*>(expr)->pop());*/
//			case BOOLMATRIX:
//				return new BoolMatrix(dynamic_cast<ConstBoolMatrix*>(expr)->pop());
//			/*case CONSTBOOLMATRIX:
//				return new ConstBoolMatrix(dynamic_cast<ConstBoolMatrix*>(expr)->pop());*/
//			default:
//				std::string errStr = "Error: cannot change value of constant " + std::to_string(expr->getLine());
//				throw std::exception(errStr.c_str());
//		}
//	}
//	else {
//		std::string errStr = "Error: type mismatch, line " + std::to_string(expr->getLine());
//		throw std::exception(errStr.c_str());
//	}
//}

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

void addElementToContainer(Node* cnt, Node* e) {
	try {
		switch (cnt->type()) {
			case INTARR:
				dynamic_cast<IntArray*>(cnt)->addElement(e);
				break;
			case BOOLARR:
				dynamic_cast<BoolArray*>(cnt)->addElement(e);
				break;
			case INTMATRIX:
				dynamic_cast<IntMatrix*>(cnt)->addElement(e);
				break;
			case BOOLMATRIX:
				dynamic_cast<BoolMatrix*>(cnt)->addElement(e);
				break;
			default:
				std::string errStr = "Error: Cannot change value of this type, line " + std::to_string(e->getLine());
				throw std::exception(errStr.c_str());
		}
	}
	catch (std::exception& ex) {
		throw ex;
	}
}

ConstInt* getIntValue(Node* m, Node* f, Node* s) {
	auto matrix = dynamic_cast<ConstIntMatrix*>(m);
	if (matrix) {
		auto i = dynamic_cast<ConstInt*>(f);
		if (i) {
			auto j = dynamic_cast<ConstInt*>(s);
			if (j) {
				try {
					return matrix->getValue(i->getValue(), j->getValue());
				}
				catch (std::exception& ex) {
					throw ex;
				}
			}
		}
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(m->getLine());
	throw std::exception(errStr.c_str());
}
ConstBool* getBoolValue(Node* m, Node* f, Node* s) {
	auto matrix = dynamic_cast<ConstBoolMatrix*>(m);
	if (matrix) {
		auto i = dynamic_cast<ConstInt*>(f);
		if (i) {
			auto j = dynamic_cast<ConstInt*>(s);
			if (j) {
				try {
					return matrix->getValue(i->getValue(), j->getValue());
				}
				catch (std::exception& ex) {
					throw ex;
				}
			}
		}
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(m->getLine());
	throw std::exception(errStr.c_str());
}

ConstIntArray* getIntVec(Node* m, Node* r, bool mode) {
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
			std::string errStr = "Error: Index expected, line " + std::to_string(r->getLine());
			throw std::exception(errStr.c_str());
		}
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(m->getLine());
	throw std::exception(errStr.c_str());
}
ConstBoolArray* getBoolVec(Node* m, Node* r, bool mode) {
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
			std::string errStr = "Error: Index expected, line " + std::to_string(r->getLine());
			throw std::exception(errStr.c_str());
		}
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(m->getLine());
	throw std::exception(errStr.c_str());
}

Node* getVec(Node* m, Node* r, bool mode) {
	try {
		return getIntVec(m, r, mode);
	}
	catch (std::exception& ex1) {
		try {
			return getBoolVec(m, r, mode);
		}
		catch (std::exception& ex2) {
			throw ex2;
		}
		throw ex1;
	}
}

ConstIntMatrix* getIntMatrix(Node* m, Node* r, bool mode) {
	auto vec = dynamic_cast<ConstIntArray*>(r);
	auto mx = dynamic_cast<ConstIntMatrix*>(m);
	std::vector<std::vector<int*>> matrix;
	if (vec && mx) {
		auto val = vec->getValue();
		for (int i = 0; i < val.size(); i++) {
			Int* index = new Int(new int(*val[i]));
			try {
				auto ptr = getIntVec(m, index, mode);
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
		std::string errStr = "Error: Type mismatch, line " + std::to_string(m->getLine());
		throw std::exception(errStr.c_str());
	}
	return dynamic_cast<IntMatrix*>(m) ? new IntMatrix(matrix) : new ConstIntMatrix(matrix);
}

ConstBoolMatrix* getBoolMatrix(Node* m, Node* r, bool mode) {
	auto mx = dynamic_cast<ConstBoolMatrix*>(m);
	auto vec = dynamic_cast<ConstIntArray*>(r);
	std::vector<std::vector<bool*>> matrix;
	if (vec && mx) {
		auto val = vec->getValue();
		for (int i = 0; i < val.size(); i++) {
			Int* index = new Int(new int(*val[i]));
			try {
				auto ptr = getBoolVec(m, index, mode);
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
		std::string errStr = "Error: Type mismatch, line " + std::to_string(m->getLine());
		throw std::exception(errStr.c_str());
	}
	return dynamic_cast<BoolMatrix*>(m) ? new BoolMatrix(matrix) : new ConstBoolMatrix(matrix);
}

Node* getMatrix(Node* m, Node* r, bool mode) {
	try {
		return getIntMatrix(m, r, mode);
	}
	catch (std::exception& ex1) {
		try {
			return getBoolMatrix(m, r, mode);
		}
		catch (std::exception& ex2) {
			throw ex2;
		}
		throw ex1;
	}
}

ConstIntMatrix* intMatrixFromLogical(Node* m, Node* r) {
	auto i = dynamic_cast<ConstIntMatrix*>(m);
	auto l = dynamic_cast<ConstBoolMatrix*>(r);
	std::vector<std::vector<int*>> res;
	if (i && l) {
		auto iMatrix = i->getMatrix();
		auto lMatrix = l->getMatrix();
		if (iMatrix.size() != lMatrix.size() || iMatrix.front().size() != lMatrix.front().size()) {
			std::string errStr = "Error: Size mismatch, line " + std::to_string(m->getLine());
			throw std::exception(errStr.c_str());
		}
		for (int k = 0; k < lMatrix.size(); k++) {
			std::vector<int*> line;
			for (int j = 0; j < lMatrix.front().size(); j++) {
				if (*lMatrix[k][j])
					line.push_back(iMatrix[k][j]);
			}
			if (!res.empty() && line.size() != res.front().size() && line.size() != 0) {
				std::string errStr = "Error: Incorrect logical matrix, line " + std::to_string(r->getLine());
				throw std::exception(errStr.c_str());
			}
			if(line.size())
				res.push_back(line);
		}
	}
	else {
		std::string errStr = "Error: Type mismatch, line " + std::to_string(m->getLine());
		throw std::exception(errStr.c_str());
	}
	return dynamic_cast<IntMatrix*>(m) ? new IntMatrix(res) : new ConstIntMatrix(res);
}

ConstBoolMatrix* boolMatrixFromLogical(Node* m, Node* r) {
	auto i = dynamic_cast<ConstBoolMatrix*>(m);
	auto l = dynamic_cast<ConstBoolMatrix*>(r);
	std::vector<std::vector<bool*>> res;
	if (i && l) {
		auto iMatrix = i->getMatrix();
		auto lMatrix = l->getMatrix();
		if (iMatrix.size() != lMatrix.size() || iMatrix.front().size() != lMatrix.front().size()) {
			std::string errStr = "Error: Size mismatch, line " + std::to_string(m->getLine());
			throw std::exception(errStr.c_str());
		}
		std::vector<bool*> line;
		for (int k = 0; k < lMatrix.size(); k++) {
			for (int j = 0; j < lMatrix.front().size(); j++) {
				if (*lMatrix[k][j])
					line.push_back(iMatrix[k][j]);
			}
			if (!res.empty() && line.size() != res.front().size() && line.size() != 0) {
				std::string errStr = "Error: Incorrect logical matrix, line " + std::to_string(r->getLine());
				throw std::exception(errStr.c_str());
			}
			if (line.size())
				res.push_back(line);
		}
	}
	else {
		std::string errStr = "Error: Type mismatch, line " + std::to_string(m->getLine());
		throw std::exception(errStr.c_str());
	}
	return dynamic_cast<BoolMatrix*>(m) ? new BoolMatrix(res) : new ConstBoolMatrix(res);
}

Node* matrixFromLogical(Node* m, Node* r) {
	try {
		return intMatrixFromLogical(m, r);
	}
	catch (std::exception& ex1) {
		try {
			return boolMatrixFromLogical(m, r);
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

/*Node* minus(Node* node) {
	Node* n;
	try {
		n = node->execute();
	}
	catch (std::exception& ex) {
		throw ex;
	}
	auto i = dynamic_cast<ConstInt*>(n);
	if (i)
		return new Int(new int(-i->getValue()),i->getLine());
	auto b = dynamic_cast<ConstBool*>(n);
	if (b)
		return new Int(new int(-b->getValue()), b->getLine());
	auto ia = dynamic_cast<ConstIntArray*>(n);
	if(ia)
		return new IntArray(ia->negativeValue(),ia->getLine());
	auto im = dynamic_cast<ConstIntMatrix*>(n);
	if (im)
		return new IntMatrix(im->negativeValue(), im->getLine());
	throw std::exception("Wrong operand");
}*/

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