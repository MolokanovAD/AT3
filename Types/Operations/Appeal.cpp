#include "Appeal.h"

Node* Appeal::execute() {
	auto it = (*callStack->top()).find(id);
	if (it != (*callStack->top()).end()) {
		switch (type) {
			case COORDINATES:
				if (dynamic_cast<ConstIntMatrix*>(it->second)) {
					try {
						return getIntValue(it->second, operand[0]->execute(), operand[1]->execute());
					}
					catch (std::exception& ex) {
						throw ex;
					}
				}
				else if (dynamic_cast<ConstBoolMatrix*>(it->second)) {
					try {
						return getBoolValue(it->second, operand[0]->execute(), operand[1]->execute());
					}
					catch (std::exception& ex) {
						throw ex;
					}
				}
				break;
			case COLUMNS:
				if (compatible(t::CONSTINTMATRIX, it->second) || compatible(t::CONSTBOOLMATRIX, it->second)) {
					Node* p = nullptr;
					try {
						p = operand[0]->execute();
					}
					catch (std::exception& ex) {
						throw ex;
					}
					if (compatible(t::CONSTINT, p)) {
						try {
							return getVec(it->second, p, 0);
						}
						catch (std::exception& ex) {
							throw ex;
						}
					}
					else {
						if (dynamic_cast<ConstIntArray*>(p)) {
							try {
								return getMatrix(it->second, p, 0);
							}
							catch (std::exception& ex) {
								throw ex;
							}
						}
					}
				}
				break;
			case ROWS:
				if (compatible(t::CONSTINTMATRIX, it->second) || compatible(t::CONSTBOOLMATRIX, it->second)) {
					Node* p = nullptr;
					try {
						p = operand[0]->execute();
					}
					catch (std::exception& ex) {
						throw ex;
					}
					if (compatible(t::CONSTINT, p)) {
						try {
							return getVec(it->second, p, 1);
						}
						catch (std::exception& ex) {
							throw ex;
						}
					}
					else {
						if (dynamic_cast<ConstIntArray*>(p)) {
							try {
								return getMatrix(it->second, p, 1);
							}
							catch (std::exception& ex) {
								throw ex;
							}
						}
					}
				}
				break;
			case LOGICAL:
				try {
					return matrixFromLogical(it->second, operand[0]->execute());
				}
				catch (std::exception& ex) {
					throw ex;
				}
				break;
			default:
				break;
		}
	}
}