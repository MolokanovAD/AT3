#include "Subtract.h"

Node* Subtract::execute() {
    Node* f = first->execute();
    Node* s = second->execute();
    if (compatible(t::CONSTINT, f, s))
        return new Int(getInt(first) - getInt(second));
    if (compatible(t::CONSTINTARR, f, s)) {
        auto v1 = dynamic_cast<ConstIntArray*>(f)->getValue();
        auto v2 = dynamic_cast<ConstIntArray*>(s)->getValue();
        int maxSize = v1.size() > v2.size() ? v1.size() : v2.size();
        auto res = std::vector<int>(maxSize, 0);
        for (int i = 0; i < maxSize; i++) {
            if (i < v1.size())
                res[i] += v1[i];
            if (i < v2.size())
                res[i] -= v2[i];
        }
        return new IntArray(res);
    }

    if (compatible(t::CONSTINTMATRIX, f, s)) {
        auto v1 = dynamic_cast<ConstIntMatrix*>(f)->getMatrix();
        auto v2 = dynamic_cast<ConstIntMatrix*>(s)->getMatrix();
        int maxH = v1.size() > v2.size() ? v1.size() : v2.size();
        int maxL = v1.front().size() > v2.front().size() ? v1.front().size() : v2.front().size();
        auto res = std::vector<std::vector<int>>(maxH, std::vector<int>(maxL, 0));
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v1.front().size(); j++) {
                res[i][j] = v1[i][j];
            }
        }
        for (int i = 0; i < v2.size(); i++) {
            for (int j = 0; j < v2.front().size(); j++) {
                res[i][j] -= v2[i][j];
            }
        }
        /*if (v1.size() != v2.size() || v1.front().size() != v2.front().size())
            throw std::exception("Incompatible matrix sizes");
        auto res = std::vector<std::vector<int>>(v1.size(), std::vector<int>(v1.front().size(), 0));
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v1.front().size(); j++) {
                res[i][j] = v1[i][j] - v2[i][j];
            }
        }*/

        return new IntMatrix(res);
    }
    throw std::exception("Wrong parameters");
}
