#include "SentenceSequence.h"

Node* SentenceSequence::execute() {
	for (auto i : operand) {
		try {
			i->execute();
		}
		catch (std::exception& ex) {
			throw ex;
		}
	}
	return nullptr;
}