#include "BoolArray.h"
#include "../Bools/Bool.h"
void BoolArray::addElement(Node* e) {
	auto i = dynamic_cast<ConstBool*>(e);
	if (i)
		value.push_back(i->getValue());
	else
		throw std::exception("Wrong type");
}
std::ostream& BoolArray::print(std::ostream& o) const {
	o << "vint " << name << " : ";
	for (auto i : value)
		o << i << " ";
	return o << std::endl;
}