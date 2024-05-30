//
// Created by ogore on 29.05.2024.
//

#ifndef AIZO_PROJEKT2_WEIGHTEDDIRECTEDGRAPHMATRIX_H
#define AIZO_PROJEKT2_WEIGHTEDDIRECTEDGRAPHMATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
#include <ctime>

class WeightedDirectedGraphMatrix {
public:
    WeightedDirectedGraphMatrix(int vertices, int edges);
    WeightedDirectedGraphMatrix(const WeightedDirectedGraphMatrix& other);  // Konstruktor kopiujący
    WeightedDirectedGraphMatrix& operator=(const WeightedDirectedGraphMatrix& other);  // Operator przypisania
    ~WeightedDirectedGraphMatrix();  // Destruktor

    void addEdge(int src, int dest, int weight);
    void printGraph() const;
    void generateRandomGraph(int density);

private:
    int vertices;  // Liczba wierzchołków
    int edges;  // Liczba krawędzi
    int** incidentMatrix;  // Macierz incydencji

    void deepCopy(const WeightedDirectedGraphMatrix& other);
    void clear();
};

#endif //AIZO_PROJEKT2_WEIGHTEDDIRECTEDGRAPHMATRIX_H
