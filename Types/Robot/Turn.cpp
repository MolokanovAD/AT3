#include "Turn.h"
//		0
//	3		1
//		2
Node* Turn::execute() {
	if (right) {
		if (dir == 3)
			dir = 0;
		else
			dir += 1;
	}
	else {
		if (dir == 0)
			dir = 3;
		else
			dir -= 1;
	}
	return nullptr;
}