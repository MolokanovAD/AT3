#include "Shift.h"
Node* Shift::execute() {
	auto vInt = dynamic_cast<ConstIntArray*>(first);
	if (vInt) {
		auto v = vInt->getValue();
		std::vector<int> res;
		if (dir) {
			for (int i = 1; i < v.size(); i++) {
				res.push_back(v[i]);
			}
			res.push_back(v.front());
			return new IntArray(res);
		}
		else {
			res.push_back(v.back());
			for (int i = 0; i < (v.size()-1); i++) {
				res.push_back(v[i]);
			}
			return new IntArray(res);
		}

	}
	auto vBool = dynamic_cast<ConstBoolArray*>(first);
	if (vBool) {
		auto v = vBool->getValue();
		std::vector<bool> res;
		if (dir) {
			for (int i = 1; i < v.size(); i++) {
				res.push_back(v[i]);
			}
			res.push_back(v.front());
			return new BoolArray(res);
		}
		else {
			res.push_back(v.back());
			for (int i = 0; i < (v.size() - 1); i++) {
				res.push_back(v[i]);
			}
			return new BoolArray(res);
		}

	}
}