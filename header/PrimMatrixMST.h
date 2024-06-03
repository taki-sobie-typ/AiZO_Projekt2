//
// Created by Patryk on 30.05.2024.
//

#ifndef PRIMMATRIXMST_H
#define PRIMMATRIXMST_H

#include "WeightedDirectedGraphMatrix.h"
#include <vector>
#include <limits>
#include <iostream>

class PrimMatrixMST {
public:
    PrimMatrixMST(const WeightedDirectedGraphMatrix& graph);
    void findMST();
    void printMST() const;

private:
    int minKey();
    const WeightedDirectedGraphMatrix& graph;
    int vertices;
    std::vector<int> parent;
    std::vector<int> key;
    std::vector<bool> inMST;
};

#endif // PRIMMATRIXMST_H
