//
// Created by Patryk on 30.05.2024.
//

#ifndef WEIGHTEDDIRECTEDGRAPHLIST_H
#define WEIGHTEDDIRECTEDGRAPHLIST_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <random>
#include <ctime>
#include <utility>

class WeightedDirectedGraphList {
public:
    WeightedDirectedGraphList(int vertices);
    WeightedDirectedGraphList(const WeightedDirectedGraphList& other);  // Copy constructor
    WeightedDirectedGraphList& operator=(const WeightedDirectedGraphList& other);  // Assignment operator
    ~WeightedDirectedGraphList();  // Destructor

    void addEdge(int src, int dest, int weight);
    void printGraph() const;
    void generateRandomGraph(int density);
    int getWeight(int src, int dest) const;
    int getSize() const;
    const std::unordered_map<int, int>& getSuccessors(int vertex) const;

private:
    int vertices;  // Number of vertices
    std::vector<std::unordered_map<int, int>> successors;  // Adjacency list for successors
    std::vector<std::unordered_map<int, int>> predecessors;  // Adjacency list for predecessors

    void deepCopy(const WeightedDirectedGraphList& other);
    void clear();
};

#endif // WEIGHTEDDIRECTEDGRAPHLIST_H
