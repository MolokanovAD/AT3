#pragma once
#include "../Variable.h"
#include "../Bools/Bool.h"
#include "../BoolArrays/BoolArray.h"
class ConstBoolMatrix : public Variable {
protected:
	std::vector<std::vector<bool*>> matrix;
	std::vector<bool*> formColumn(int i) const;
public:
	ConstBoolMatrix(std::vector<std::vector<bool*>> m, t typ = CONSTBOOLMATRIX, int l = 0) : Variable(typ,l), matrix(m) {}
	ConstBoolMatrix(const ConstBoolMatrix& cbm, t typ = t::CONSTBOOLMATRIX, int l = 0);
	virtual ConstBool* getValue(int i, int j, int l) const;
	virtual ConstBoolArray* getRow(int i) const;
	virtual ConstBoolArray* getColumn(int i) const;
	std::vector<std::vector<bool*>> getMatrix() { return matrix; }
	std::vector<std::vector<bool*>> pop() { std::vector<std::vector<bool*>> m = matrix; matrix.clear(); return m; }
	virtual void dump() override { matrix.clear(); }
	ConstBoolMatrix* clone() const override { return new ConstBoolMatrix(*this,nodeType,line); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~ConstBoolMatrix();
};

