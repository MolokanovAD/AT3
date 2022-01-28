#include "Transposition.h"

Node* Transposition::execute() {
    Node* p = nullptr;
    try {
        p = operand[0]->execute();
    }
    catch (std::exception& ex) {
        throw ex;
    }
    auto mInt = dynamic_cast<ConstIntMatrix*>(p);
    //auto mInt = dynamic_cast<ConstIntMatrix*>(operand[0]);
    if (mInt) {
        auto m = mInt->getMatrix();
        std::vector<std::vector<int*>> res(m.front().size(), std::vector<int*>(m.size(), nullptr));
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.front().size(); j++) {
                res[j][i] = new int(*m[i][j]);
            }
        }
        return new IntMatrix(res,line);
    }
    auto mBool = dynamic_cast<ConstBoolMatrix*>(p);
    //auto mBool = dynamic_cast<ConstBoolMatrix*>(operand[0]);
    if (mBool) {
        auto m = mBool->getMatrix();
        std::vector<std::vector<bool*>> res(m.front().size(), std::vector<bool*>(m.size(), nullptr));
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.front().size(); j++) {
                res[j][i] = new bool(*m[i][j]);
            }
        }
        return new BoolMatrix(res,line);
    }
    std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
    throw std::exception(errStr.c_str());
}
