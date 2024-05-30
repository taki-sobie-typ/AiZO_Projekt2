//
// Created by ogore on 29.05.2024.
//

#ifndef WEIGHTEDDIRECTEDGRAPHMATRIX_H
#define WEIGHTEDDIRECTEDGRAPHMATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

// Custom hash function for std::pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class WeightedDirectedGraphMatrix {
public:
    WeightedDirectedGraphMatrix(int vertices, int edges);
    WeightedDirectedGraphMatrix(const WeightedDirectedGraphMatrix& other);
    WeightedDirectedGraphMatrix& operator=(const WeightedDirectedGraphMatrix& other);
    ~WeightedDirectedGraphMatrix();

    void addEdge(int src, int dest, int weight);
    void printGraph() const;
    void generateRandomGraph(int density);
    int getSize() const; // New method to return size value
    int getWeight(int src, int dest) const;


private:
    int vertices;
    int edges;
    int** incidentMatrix;

    void deepCopy(const WeightedDirectedGraphMatrix& other);
    void clear();
};

#endif // WEIGHTEDDIRECTEDGRAPHMATRIX_H