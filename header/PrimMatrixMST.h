//
// Created by Patryk on 30.05.2024.
//

#ifndef AIZO_PROJEKT2_PRIMMATRIXMST_H
#define AIZO_PROJEKT2_PRIMMATRIXMST_H

#include <vector>
#include <iostream>
#include <limits>
#include "WeightedDirectedGraphMatrix.h"

class PrimMatrixMST {
public:
    PrimMatrixMST(const WeightedDirectedGraphMatrix& graph);
    void findMST();
    void printMST() const;

private:
    int vertices;  // Number of vertices
    const WeightedDirectedGraphMatrix& graph;  // Weighted Directed Graph
    std::vector<int> parent;  // Array to store the MST
    std::vector<int> key;  // Key values used to pick minimum weight edge in cut
    std::vector<bool> inMST;  // To represent set of vertices not yet included in MST

    int minKey();
};

#endif //AIZO_PROJEKT2_PRIMMATRIXMST_H
