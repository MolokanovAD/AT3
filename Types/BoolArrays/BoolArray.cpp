#include "BoolArray.h"
#include "../Bools/Bool.h"
void BoolArray::addElement(Node* e) {
	//auto i = dynamic_cast<ConstBool*>(e);
	auto i = dynamic_cast<ConstBool*>(e->execute());
	if (i)
		//value.push_back(new bool(i->getValue()));
		value.push_back(i->pop());
	else
		throw std::exception("Wrong type");
}

BoolArray* BoolArray::clone() const {
	std::vector<bool*> v;
	for (auto ptr : value)
		v.push_back(new bool(*ptr));
	return new BoolArray(v);
}

void BoolArray::setValue(std::vector<bool*> v) {
	if (value.size() != v.size())
		throw std::exception("Wrong size");
	for (int i = 0; i < value.size(); i++) {
		*value[i] = *v[i];
	}
}

std::ostream& BoolArray::print(std::ostream& o) const {
	o << "vint " << name << " : ";
	for (auto i : value)
		o << *i << " ";
	return o << std::endl;
}