#include "Appeal.h"

Node* Appeal::execute() {
	auto it = varTable.find(*id);
	if (it != varTable.end()) {
		switch (type) {
			case COORDINATES:
				if (dynamic_cast<ConstIntMatrix*>(it->second)) {
					try {
						return getIntValue(it->second, first->execute(), second->execute());
					}
					catch (std::exception& ex) {
						//...
					}
				}
				else if (dynamic_cast<ConstBoolMatrix*>(it->second)) {
					try {
						return getBoolValue(it->second, first->execute(), second->execute());
					}
					catch (std::exception& ex) {
						//...
					}
				}
				break;
			case COLUMNS:
				if (compatible(t::CONSTINTMATRIX, it->second) || compatible(t::CONSTBOOLMATRIX, it->second)) {
					Node* p = first->execute();
					if (compatible(t::CONSTINT, p)) {
						try {
							return getVec(it->second, p, 0);
						}
						catch (std::exception& ex) {
							//...
						}
					}
					else {
						if (dynamic_cast<ConstIntArray*>(p)) {
							try {
								return getMatrix(it->second, p, 0);
							}
							catch (...) {
								//... error!
							}
						}
					}
				}
				break;
			case ROWS:
				if (compatible(t::CONSTINTMATRIX, it->second) || compatible(t::CONSTBOOLMATRIX, it->second)) {
					Node* p = first->execute();
					if (compatible(t::CONSTINT, p)) {
						try {
							return getVec(it->second, p, 1);
						}
						catch (std::exception& ex) {
							//...
						}
					}
					else {
						if (dynamic_cast<ConstIntArray*>(p)) {
							try {
								return getMatrix(it->second, p, 1);
							}
							catch (...) {
								//... error!
							}
						}
					}
				}
				break;
			case LOGICAL:
				try {
					return matrixFromLogical(it->second,first->execute());
				}
				catch (...) {
					//...
				}
				break;
			default:
				break;
		}
	}
}