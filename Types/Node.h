#pragma once
#include <string>
#include <memory>
#include <ostream>
#include <vector>
enum t {
	VARBOOL,
	CONSTBOOL,
	VARINT,
	CONSTINT,
	INTARR,
	CONSTINTARR,
	BOOLARR,
	CONSTBOOLARR,
	INTMATRIX,
	CONSTINTMATRIX,
	BOOLMATRIX,
	CONSTBOOLMATRIX
	
};
class Node {
protected:
	t nodeType;
public:
	Node() {};
	Node(t typ): nodeType(typ) {};
	virtual Node* execute() = 0;
	t type() { return nodeType; }
	friend std::ostream& operator<<(std::ostream& o, const Node& node);
	virtual Node* clone() const = 0;
	virtual std::ostream& print(std::ostream& o) const = 0;
};
