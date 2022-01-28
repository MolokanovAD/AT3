#include "IntArray.h"
#include "../Ints/Int.h"

void IntArray::addElement(Node* e, int line) {
	//auto i = dynamic_cast<ConstInt*>(e);
	auto i = dynamic_cast<ConstInt*>(e->execute());
	if (i)
		//value.push_back(new int(i->getValue()));
		value.push_back(i->pop());
	else {
		std::string errStr = "Error: Size mismatch, line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
}

void IntArray::setValue(std::vector<int*> v, int line) {
	if (value.size() != v.size()) {
		std::string errStr = "Error: Size mismatch, line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
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