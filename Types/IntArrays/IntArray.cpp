#include "IntArray.h"
#include "../Ints/Int.h"

void IntArray::addElement(Node* e) {
	//auto i = dynamic_cast<ConstInt*>(e);
	auto i = dynamic_cast<ConstInt*>(e->execute());
	if (i)
		//value.push_back(new int(i->getValue()));
		value.push_back(i->pop());
	else
		throw std::exception("Wrong type");
}

void IntArray::setValue(std::vector<int*> v) {
	if (value.size() != v.size())
		throw std::exception("Wrong size");
	for (int i = 0; i < value.size(); i++) {
		*value[i] = *v[i];
	}
}

std::ostream& IntArray::print(std::ostream& o) const {
	o << "vint " << name << " : ";
	for (auto i : value)
		o << *i << " ";
	return o << std::endl;
}