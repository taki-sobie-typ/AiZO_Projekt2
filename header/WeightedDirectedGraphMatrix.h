//
// Created by ogore on 29.05.2024.
//

#ifndef WEIGHTED_DIRECTED_GRAPH_MATRIX_H
#define WEIGHTED_DIRECTED_GRAPH_MATRIX_H

#include <vector>

class WeightedDirectedGraphMatrix {
private:
    int vertices;
    std::vector<std::vector<int>> incidentMatrix;

    void deepCopy(const WeightedDirectedGraphMatrix& other);
    void clear();

    void createSpanningTree();

public:
    WeightedDirectedGraphMatrix(int vertices);
    WeightedDirectedGraphMatrix(const WeightedDirectedGraphMatrix& other);
    WeightedDirectedGraphMatrix& operator=(const WeightedDirectedGraphMatrix& other);
    ~WeightedDirectedGraphMatrix();

    void addEdge(int src, int dest, int weight);
    void printGraph() const;
    int getWeight(int src, int dest) const;
    int getSize() const;
    void generateRandomGraph(int density);


    int getFirstVertex() const;
    int getLastVertex() const;
};

#endif // WEIGHTED_DIRECTED_GRAPH_MATRIX_H
