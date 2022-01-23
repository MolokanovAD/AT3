#include "IntArray.h"
#include "../Ints/Int.h"

void IntArray::addElement(Node* e) {
	auto i = dynamic_cast<ConstInt*>(e);
	if (i)
		value.push_back(i->getValue());
	else
		throw std::exception("Wrong type");
}
std::ostream& IntArray::print(std::ostream& o) const {
	o << "vint " << name << " : ";
	for (auto i : value)
		o << i << " ";
	return o << std::endl;
}