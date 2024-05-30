//
// Created by Patryk on 30.05.2024.
//

#ifndef PRIMLISTMST_H
#define PRIMLISTMST_H

#include <vector>
#include <iostream>
#include <limits>
#include "WeightedDirectedGraphList.h"

class PrimListMST {
public:
    PrimListMST(const WeightedDirectedGraphList& graph);
    void findMST();
    void printMST() const;

private:
    int vertices;  // Number of vertices
    const WeightedDirectedGraphList& graph;  // Weighted Directed Graph
    std::vector<int> parent;  // Array to store the MST
    std::vector<int> key;  // Key values used to pick minimum weight edge in cut
    std::vector<bool> inMST;  // To represent set of vertices not yet included in MST

    int minKey();
};

#endif // PRIMLISTMST_H

