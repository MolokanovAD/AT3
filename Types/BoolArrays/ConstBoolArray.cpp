#include "ConstBoolArray.h"

ConstBoolArray::ConstBoolArray(const ConstBoolArray& cba, t typ, int l) : Variable(typ,l) {
	for (auto ptr : cba.value)
		value.push_back(new bool(*ptr));
}

bool* ConstBoolArray::getVal(int i) { 
	if (i > -1 && i < value.size())
		return value[i];
	else {
		std::string errStr = "Error: Index out of range, line" + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
}

std::ostream& ConstBoolArray::print(std::ostream& o) const {
	o << "cvint " << name << " : ";
	for (auto i : value)
		o << *i << " ";
	return o << std::endl;
}

ConstBoolArray::~ConstBoolArray() {
	for (auto i : value)
		delete i;
	value.clear();
}