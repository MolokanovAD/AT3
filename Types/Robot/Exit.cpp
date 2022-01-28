#include "Exit.h"
//		0
//	3		1
//		2
Node* Exit::execute() {
	std::cout << "Looking for exit in (" << x << ", " << y << "), direction " << dir;
	int xx = x;
	int yy = y;
	switch (dir) {
		case 0:
			yy--;
			while (yy > -1 && lab[yy][x] != '#') {
				if (lab[yy][x] == 'o')
					return new Bool(new bool(true), line);
				yy--;
			}
			break;
		case 1:
			xx++;
			while (xx < lab.front().size() && lab[y][xx] != '#') {
				if (lab[y][xx] == 'o')
					return new Bool(new bool(true), line);
				xx++;
			}
			break;
		case 2:
			yy++;
			while (yy < lab.size() && lab[yy][x] != '#') {
				if (lab[yy][x] == 'o')
					return new Bool(new bool(true), line);
				yy++;
			}
			break;
		case 3:
			xx--;
			while (xx > -1 && lab[y][xx] != '#') {
				if (lab[y][xx] == 'o')
					return new Bool(new bool(true), line);
				xx--;
			}
			break;
	}
	std::cout << ", can't see exit" << std::endl;
	return new Bool(new bool(false),line);
}