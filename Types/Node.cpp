#include "Node.h"

std::ostream& operator<<(std::ostream& o, const Node& node) {
	return node.print(o);
}
