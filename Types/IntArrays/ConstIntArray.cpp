#include "ConstIntArray.h"

ConstIntArray::ConstIntArray(const ConstIntArray& cia, t typ = t::CONSTINTARR) : Variable(typ) {
	for (auto ptr : cia.value)
		value.push_back(new int(*ptr));
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