#include "BoolArray.h"
#include "../Bools/Bool.h"
void BoolArray::addElement(Node* e, int line) {
	//auto i = dynamic_cast<ConstBool*>(e);
	auto i = dynamic_cast<ConstBool*>(e->execute());
	if (i)
		//value.push_back(new bool(i->getValue()));
		value.push_back(i->pop());
	else {
		std::string errStr = "Error: Size mismatch, line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
}

void BoolArray::setValue(std::vector<bool*> v, int line) {
	if (value.size() != v.size()) {
		std::string errStr = "Error: Size mismatch, line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
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