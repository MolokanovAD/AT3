#include "Add.h"

Node* Add::execute() {
    Node* f = nullptr, * s = nullptr;
    try {
        f = operand[0]->execute();
        s = operand[1]->execute();
    }
    catch (std::exception& ex) {
        throw ex;
    }
    if (compatible(t::CONSTINT, f, s))
        return new Int(new int(getInt(f) + getInt(s)), line);
    if (compatible(t::CONSTINTARR, f, s)) {
        auto v1 = dynamic_cast<ConstIntArray*>(f)->getValue();
        auto v2 = dynamic_cast<ConstIntArray*>(s)->getValue();
        int maxSize = v1.size() > v2.size() ? v1.size() : v2.size();
        auto res = std::vector<int*>(maxSize,nullptr);
        for (int i = 0; i < maxSize; i++) {
            res[i] = new int(0);
            if (i < v1.size())
                *res[i] += *v1[i];
            if (i < v2.size())
                *res[i] += *v2[i];
        }
        return new IntArray(res,line);
    }
    if (compatible(t::CONSTINTMATRIX, f, s)) {
        auto v1 = dynamic_cast<ConstIntMatrix*>(f)->getMatrix();
        auto v2 = dynamic_cast<ConstIntMatrix*>(s)->getMatrix();
        int maxH = v1.size() > v2.size() ? v1.size() : v2.size();
        int maxL = v1.front().size() > v2.front().size() ? v1.front().size() : v2.front().size();
        auto res = std::vector<std::vector<int*>>(maxH, std::vector<int*>(maxL, nullptr));
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v1.front().size(); j++) {
                res[i][j] = new int(*v1[i][j]);
            }
        }
        for (int i = 0; i < v2.size(); i++) {
            for (int j = 0; j < v2.front().size(); j++) {
                if (res[i][j])
                    *res[i][j] += *v2[i][j];
                else
                    res[i][j] = new int(*v2[i][j]);
            }
        }
        return new IntMatrix(res,line);
    }
    std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
    throw std::exception(errStr.c_str());
}
