#include "ConstIntArray.h"
std::ostream& ConstIntArray::print(std::ostream& o) const {
	o << "cvint " << name << " : ";
	for (auto i : value)
		o << i << " ";
	return o << std::endl;
}