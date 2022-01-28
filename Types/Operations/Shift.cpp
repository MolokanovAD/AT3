#include "Shift.h"
Node* Shift::execute() {
	Node* p = nullptr;
	try {
		p = operand[0]->execute();
	}
	catch (std::exception& ex) {
		throw ex;
	}
	auto vInt = dynamic_cast<ConstIntArray*>(p);
	//auto vInt = dynamic_cast<ConstIntArray*>(operand[0]);
	if (vInt) {
		auto v = vInt->getValue();
		std::vector<int*> res;
		if (dir) {
			for (int i = 1; i < v.size(); i++) {
				res.push_back(new int(*v[i]));
			}
			res.push_back(new int(*v.front()));
			return new IntArray(res,line);
		}
		else {
			res.push_back(new int(*v.back()));
			for (int i = 0; i < (v.size()-1); i++) {
				res.push_back(new int(*v[i]));
			}
			return new IntArray(res,line);
		}

	}
	auto vBool = dynamic_cast<ConstBoolArray*>(p);
	//auto vBool = dynamic_cast<ConstBoolArray*>(operand[0]);
	if (vBool) {
		auto v = vBool->getValue();
		std::vector<bool*> res;
		if (dir) {
			for (int i = 1; i < v.size(); i++) {
				res.push_back(new bool(*v[i]));
			}
			res.push_back(new bool(*v.front()));
			return new BoolArray(res,line);
		}
		else {
			res.push_back(new bool(*v.back()));
			for (int i = 0; i < (v.size() - 1); i++) {
				res.push_back(new bool(*v[i]));
			}
			return new BoolArray(res,line);
		}
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
	throw std::exception(errStr.c_str());
}