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


bool insertVar(t type, std::string* id, Node* expr, std::map<std::string, Node*>& varTable) {
	if (compatible(type, expr)) {
		if (varTable.find(*id) == varTable.end()) {
			switch (type) {
				case VARBOOL:
					return varTable.insert({ *id, new Bool(new bool(toInt(expr))) }).second;
				case CONSTBOOL:
					return varTable.insert({ *id, new ConstBool(new bool(toInt(expr))) }).second;
				case VARINT:
					return varTable.insert({ *id, new Int(new int(toInt(expr))) }).second;
				case CONSTINT:
					return varTable.insert({ *id, new ConstInt(new int(toInt(expr))) }).second;
				case INTARR:
					return varTable.insert({ *id, new IntArray(dynamic_cast<ConstIntArray*>(expr)->pop()) }).second;
				case CONSTINTARR:
					return varTable.insert({ *id, new ConstIntArray(dynamic_cast<ConstIntArray*>(expr)->pop()) }).second;
				case BOOLARR:
					return varTable.insert({ *id, new BoolArray(dynamic_cast<ConstBoolArray*>(expr)->pop()) }).second;
				case CONSTBOOLARR:
					return varTable.insert({ *id, new ConstBoolArray(dynamic_cast<ConstBoolArray*>(expr)->pop()) }).second;
				case INTMATRIX:
					return varTable.insert({ *id, new IntMatrix(dynamic_cast<ConstIntMatrix*>(expr)->pop()) }).second;
				case CONSTINTMATRIX:
					return varTable.insert({ *id, new ConstIntMatrix(dynamic_cast<ConstIntMatrix*>(expr)->pop()) }).second;
				case BOOLMATRIX:
					return varTable.insert({ *id, new BoolMatrix(dynamic_cast<ConstBoolMatrix*>(expr)->pop()) }).second;
				case CONSTBOOLMATRIX:
					return varTable.insert({ *id, new ConstBoolMatrix(dynamic_cast<ConstBoolMatrix*>(expr)->pop()) }).second;
				default:
					throw std::exception("Unknown type");
			}
		}
	}
	else
		throw std::exception("Wrong type");
}

Node* assignVar(t type, Node* expr) {
	if (compatible(type, expr)) {
		switch (type) {
			case VARBOOL:
				return new Bool(new bool(toInt(expr)));
			/*case CONSTBOOL:
				return  new ConstBool(new bool(toInt(expr)));*/
			case VARINT:
				return new Int(new int(toInt(expr)));
			/*case CONSTINT:
				return new ConstInt(new int(toInt(expr)));*/
			case INTARR:
				return new IntArray(dynamic_cast<ConstIntArray*>(expr)->pop());
			/*case CONSTINTARR:
				return new ConstIntArray(dynamic_cast<ConstIntArray*>(expr)->pop());*/
			case BOOLARR:
				return new BoolArray(dynamic_cast<ConstBoolArray*>(expr)->pop());
			/*case CONSTBOOLARR:
				return new ConstBoolArray(dynamic_cast<ConstBoolArray*>(expr)->pop());*/
			case INTMATRIX:
				return new IntMatrix(dynamic_cast<ConstIntMatrix*>(expr)->pop());
			/*case CONSTINTMATRIX:
				return new ConstIntMatrix(dynamic_cast<ConstIntMatrix*>(expr)->pop());*/
			case BOOLMATRIX:
				return new BoolMatrix(dynamic_cast<ConstBoolMatrix*>(expr)->pop());
			/*case CONSTBOOLMATRIX:
				return new ConstBoolMatrix(dynamic_cast<ConstBoolMatrix*>(expr)->pop());*/
			default:
				throw std::exception("Cannot change value of constant");
		}
	}
	else
		throw std::exception("Wrong type");
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
			throw std::exception("Wrong type");
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
				throw std::exception("Wrong type");
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
	throw std::exception("Wrong parameters");
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
	throw std::exception("Wrong parameters");
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
		else throw std::exception("Not an index");
	}
	throw std::exception("Wrong parameters");
}
ConstBoolArray* getBoolVec(Node* m, Node* r, bool mode) {
	auto matrix = dynamic_cast<ConstBoolMatrix*>(m);
	auto row = dynamic_cast<ConstInt*>(r);
	if (matrix && row) {
		if (row) {
			try {
				return mode ? matrix->getRow(row->getValue()) : matrix->getColumn(row->getValue());
			}
			catch (std::exception& ex) {
				throw ex;
			}
		}
		else throw std::exception("Not an index");
	}
	throw std::exception("Wrong parameters");
}

Node* getVec(Node* m, Node* r, bool mode) {
	try {
		return getIntVec(m, r, mode);
	}
	catch (...) {
		try {
			return getBoolVec(m, r, mode);
		}
		catch (...) {
			throw std::exception("Wrong parameters");
		}
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
	else
		throw std::exception("Wrong parameters");
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
	else
		throw std::exception("Wrong parameters");
	return dynamic_cast<BoolMatrix*>(m) ? new BoolMatrix(matrix) : new ConstBoolMatrix(matrix);
}

Node* getMatrix(Node* m, Node* r, bool mode) {
	try {
		return getIntMatrix(m, r, mode);
	}
	catch (...) {
		try {
			return getBoolMatrix(m, r, mode);
		}
		catch (...) {
			throw std::exception("Wrong parameters");
		}
	}
}

//bool correctLogicalMatrix(ConstBoolMatrix* lm, int l, int h) {
//	auto m = lm->getMatrix();
//	if (m.size() != h || m.front().size() != l)
//		return false;
//	for (auto i = m.begin(); i < m.end(); i++) {
//		for()
//	}
//}

ConstIntMatrix* intMatrixFromLogical(Node* m, Node* r) {
	auto i = dynamic_cast<ConstIntMatrix*>(m);
	auto l = dynamic_cast<ConstBoolMatrix*>(r);
	std::vector<std::vector<int*>> res;
	if (i && l) {
		auto iMatrix = i->getMatrix();
		auto lMatrix = l->getMatrix();
		if (iMatrix.size() != lMatrix.size() || iMatrix.front().size() != lMatrix.front().size())
			throw std::exception("Different sizes");
		for (int k = 0; k < lMatrix.size(); k++) {
			std::vector<int*> line;
			for (int j = 0; j < lMatrix.front().size(); j++) {
				if (*lMatrix[k][j])
					line.push_back(iMatrix[k][j]);
			}
			if (!res.empty() && line.size() != res.front().size() && line.size() != 0)
				throw std::exception("Incorrect logical matrix");
			if(line.size())
				res.push_back(line);
		}
	}
	else
		throw std::exception("Wrong operands");
	return dynamic_cast<IntMatrix*>(m) ? new IntMatrix(res) : new ConstIntMatrix(res);
}

ConstBoolMatrix* boolMatrixFromLogical(Node* m, Node* r) {
	auto i = dynamic_cast<ConstBoolMatrix*>(m);
	auto l = dynamic_cast<ConstBoolMatrix*>(r);
	std::vector<std::vector<bool*>> res;
	if (i && l) {
		auto iMatrix = i->getMatrix();
		auto lMatrix = l->getMatrix();
		if (iMatrix.size() != lMatrix.size() || iMatrix.front().size() != lMatrix.front().size())
			throw std::exception("Different sizes");
		std::vector<bool*> line;
		for (int k = 0; k < lMatrix.size(); k++) {
			for (int j = 0; j < lMatrix.front().size(); j++) {
				if (*lMatrix[k][j])
					line.push_back(iMatrix[k][j]);
			}
			if (!res.empty() && line.size() != res.front().size() && line.size() != 0)
				throw std::exception("Incorrect logical matrix");
			res.push_back(line);
		}
	}
	else
		throw std::exception("Wrong operands");
	return dynamic_cast<BoolMatrix*>(m) ? new BoolMatrix(res) : new ConstBoolMatrix(res);
}

Node* matrixFromLogical(Node* m, Node* r) {
	try {
		return intMatrixFromLogical(m, r);
	}
	catch (...) {
		try {
			return boolMatrixFromLogical(m, r);
		}
		catch (...) {
			throw std::exception("Wrong parameters");
		}
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

Int* minus(Node* node) {
	auto i = dynamic_cast<ConstInt*>(node);
	if (i)
		return new Int(new int(-i->getValue()));
	auto b = dynamic_cast<ConstBool*>(node);
	if (b)
		return new Int(new int(-b->getValue()));
	throw std::exception("Wrong operand");
}























void printVarTable(std::map<std::string, Node*>& varTable) {
	for (auto& i : varTable) {
		std::cout << i.first << " : " << *i.second << std::endl;
	}
}