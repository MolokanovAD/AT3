#include "Wall.h"

//		0
//	3		1
//		2

Node* Wall::execute() {
	int res = 0;
	int xx = x;
	int yy = y;
	switch (dir) {
		case 0:
			while (yy > -1 && lab[yy][x] != '#') {
				res++;
				yy--;
			}
			break;
		case 1:
			while (xx < lab.front().size() && lab[y][xx] != '#') {
				res++;
				xx++;
			}
			break;
		case 2:
			while (yy < lab.size() && lab[yy][x] != '#') {
				res++;
				yy++;
			}
			break;
		case 3:
			while (xx > -1 && lab[y][xx] != '#') {
				res++;
				xx--;
			}
			break;
	}
	return new Int(new int(res), line);
}