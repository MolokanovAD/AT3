#include "ConstIntArray.h"

ConstIntArray::ConstIntArray(const ConstIntArray& cia, t typ, int l) : Variable(typ,l) {
	for (auto ptr : cia.value)
		value.push_back(new int(*ptr));
}

int ConstIntArray::operator[](int index) const {
	if (index > -1 && index < value.size())
		return *value[index];
	throw std::exception("Index out of range");
}

int* ConstIntArray::getVal(int i) {
	if (i > -1 && i < value.size())
		return value[i];
	else {
		std::string errStr = "Error: Index out of range, line" + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
}

std::vector<int*> ConstIntArray::negativeValue() const{
	std::vector<int*> res;
	for (auto i : value) {
		res.push_back(new int(-(*i)));
	}
	return res;
}

std::ostream& ConstIntArray::print(std::ostream& o) const {
	o << "cvint " << name << " : ";
	for (auto i : value)
		o << *i << " ";
	return o << std::endl;
}

ConstIntArray::~ConstIntArray() {
	for (auto i : value)
		delete i;
	value.clear();
}