#include "Transposition.h"

Node* Transposition::execute() {
    //auto mInt = dynamic_cast<ConstIntMatrix*>(first->execute());
    auto mInt = dynamic_cast<ConstIntMatrix*>(first);
    if (mInt) {
        auto m = mInt->getMatrix();
        std::vector<std::vector<int*>> res(m.front().size(), std::vector<int*>(m.size(), nullptr));
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.front().size(); j++) {
                res[j][i] = new int(*m[i][j]);
            }
        }
        return new IntMatrix(res);
    }
    //auto mBool = dynamic_cast<ConstBoolMatrix*>(first->execute());
    auto mBool = dynamic_cast<ConstBoolMatrix*>(first);
    if (mBool) {
        auto m = mBool->getMatrix();
        std::vector<std::vector<bool*>> res(m.front().size(), std::vector<bool*>(m.size(), nullptr));
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.front().size(); j++) {
                res[j][i] = new bool(*m[i][j]);
            }
        }
        return new BoolMatrix(res);
    }
    throw std::exception("Wrong operand type");
}
