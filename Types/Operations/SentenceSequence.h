#pragma once
#include "../Operation.h"
class SentenceSequence : public Operation {
public:
	SentenceSequence(Node* expr, int l = 0) : Operation(expr,l) {}
	void pushSentence(Node* expr) { operand.push_back(expr); }
	Node* execute() override;
	virtual SentenceSequence* clone() const override { return new SentenceSequence(*this); }
	virtual ~SentenceSequence() {}
};

