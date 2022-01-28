#pragma once
#include <string>
#include <memory>
#include <iostream>
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
	CONSTBOOLMATRIX,
	OPERATION
};
class Node {
protected:
	int line;
	t nodeType;
public:
	Node(int l = 0): line(l) {};
	Node(t typ, int l = 0): nodeType(typ),line(l) {};
	virtual Node* execute() = 0;
	int getLine() const { return line; }
	t type() { return nodeType; }
	friend std::ostream& operator<<(std::ostream& o, const Node& node);
	virtual void dump() {}
	virtual Node* clone() const = 0;
	virtual std::ostream& print(std::ostream& o) const = 0;
	virtual ~Node() {}
};
