//
// Created by Patryk on 30.05.2024.
//

#include "../header/PrimMatrixMST.h"

// Constructor
PrimMatrixMST::PrimMatrixMST(const WeightedDirectedGraphMatrix& graph)
        : graph(graph), vertices(graph.getSize()), parent(vertices), key(vertices, std::numeric_limits<int>::max()), inMST(vertices, false) {}

// Function to find the vertex with the minimum key value that is not yet included in the MST
int PrimMatrixMST::minKey() {
    int min = std::numeric_limits<int>::max(), minIndex = -1;
    for (int v = 0; v < vertices; ++v) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to find and print the MST using Prim's algorithm
void PrimMatrixMST::findMST() {
    // Initialize the key value of the first vertex to 0 so it is picked first
    key[0] = 0;
    parent[0] = -1; // First node is always the root of the MST

    // MST will have vertices number of edges
    for (int count = 0; count < vertices - 1; ++count) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey();
        inMST[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; ++v) {
            int weight = graph.getWeight(u, v);
            if (weight > 0 && !inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
}

// Function to print the constructed MST
void PrimMatrixMST::printMST() const {
    std::cout << "Edge   Weight" << std::endl;
    for (int i = 1; i < vertices; ++i) {
        if (parent[i] != -1) {
            std::cout << parent[i] << " - " << i << "    " << graph.getWeight(parent[i], i) << std::endl;
        }
    }
}



