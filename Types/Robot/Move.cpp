#include "Move.h"

//		0
//	3		1
//		2
Node* Move::execute() {
	Node* expr = nullptr;
	try {
		expr = operand[0]->execute();
	}
	catch (std::exception& ex) {
		throw ex;
	}
	ConstIntArray* arr = dynamic_cast<ConstIntArray*>(expr);
	if (arr && isDirection(arr)) {
		if ((*arr)[1])
			dir = 1 + (*arr)[1];
		else if ((*arr)[0])
			dir = 2 - (*arr)[0];
		int newX = x + (*arr)[0];
		int newY = y + (*arr)[1];
		if (newX < lab.front().size() && newX > -1 && newY < lab.size() && newY > -1) {
			if (lab[newY][newX] != '#') {
				x = newX;
				y = newY;
				std::cout << "New position: (" << x << ", " << y << ")" << std::endl;
				return new Bool(new bool(true),line);
			}
			else {
				std::cout << "Looking on a wall at (" << x << ", " << y << "), direction: " << dir << std::endl;
				return new Bool(new bool(false), line);
			}
		}
		return new Bool(new bool(false), line);
	}
	std::string errStr = "Error: Direction expected, line " + std::to_string(line);
	throw std::exception(errStr.c_str());
}