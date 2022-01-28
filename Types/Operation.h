#pragma once
#include "Node.h"
#include "Ints/Int.h"
#include "Bools/Bool.h"
#include <map>
#include <stack>

class Operation : public Node {
protected:
	std::vector<Node*> operand;
	int getInt(Node* p);
public:
	Operation(int l = 0):Node(t::OPERATION,l) {}
	Operation(Node* f, int l = 0):Node(l) { operand.push_back(f); }
	Operation(Node* f, Node* s, int l = 0):Node(l) { operand.push_back(f); operand.push_back(s); }
	Operation(const Operation& op);
	virtual Node* operator[](int index);
	virtual void dump() override { operand.clear(); }
	size_t size() { return operand.size(); }
	std::ostream& print(std::ostream& o) const override { return o; }
	virtual Operation* clone() const = 0;
	virtual ~Operation();
};
typedef std::stack<std::map<std::string, Node*>*> CallStack;
