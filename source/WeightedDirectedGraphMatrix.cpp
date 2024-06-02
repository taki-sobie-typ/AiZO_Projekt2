#include "../header/WeightedDirectedGraphMatrix.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_set>

// Constructor
WeightedDirectedGraphMatrix::WeightedDirectedGraphMatrix(int vertices)
        : vertices(vertices), incidentMatrix(vertices, std::vector<int>()) {}

// Copy constructor
WeightedDirectedGraphMatrix::WeightedDirectedGraphMatrix(const WeightedDirectedGraphMatrix& other) {
    deepCopy(other);
}

// Assignment operator
WeightedDirectedGraphMatrix& WeightedDirectedGraphMatrix::operator=(const WeightedDirectedGraphMatrix& other) {
    if (this != &other) {
        clear();
        deepCopy(other);
    }
    return *this;
}

// Destructor
WeightedDirectedGraphMatrix::~WeightedDirectedGraphMatrix() {
    clear();
}

// Add edge
void WeightedDirectedGraphMatrix::addEdge(int src, int dest, int weight) {
    if (weight <= 0) {
        throw std::invalid_argument("Edge weight must be a positive number.");
    }

    int edgeIndex = incidentMatrix[0].size();
    for (auto& row : incidentMatrix) {
        row.push_back(0); // Add a new column for the new edge
    }
    incidentMatrix[src][edgeIndex] = weight;
    incidentMatrix[dest][edgeIndex] = -weight;
}

// Print graph
void WeightedDirectedGraphMatrix::printGraph() const {
    std::cout << "Incident Matrix:" << std::endl;

    // Determine the maximum number of columns in the incident matrix
    int maxColumns = incidentMatrix[0].size();

    // Print column headers
    std::cout << "   ";
    for (int j = 0; j < maxColumns; ++j) {
        std::cout << std::setw(3) << j << " ";
    }
    std::cout << std::endl;

    // Print each row of the matrix
    for (int i = 0; i < vertices; ++i) {
        std::cout << std::setw(2) << i << ": ";
        for (int j = 0; j < maxColumns; ++j) {
            if (j < incidentMatrix[i].size()) {
                std::cout << std::setw(3) << incidentMatrix[i][j] << " ";
            } else {
                std::cout << std::setw(3) << 0 << " ";
            }
        }
        std::cout << std::endl;
    }
}

// Deep copy
void WeightedDirectedGraphMatrix::deepCopy(const WeightedDirectedGraphMatrix& other) {
    vertices = other.vertices;
    incidentMatrix = other.incidentMatrix;
}

// Clear memory
void WeightedDirectedGraphMatrix::clear() {
    incidentMatrix.clear();
    incidentMatrix.resize(vertices);
}

// Get weight between two vertices
int WeightedDirectedGraphMatrix::getWeight(int src, int dest) const {
    for (int i = 0; i < incidentMatrix[src].size(); ++i) {
        if (incidentMatrix[src][i] > 0 && incidentMatrix[dest][i] < 0) {
            return incidentMatrix[src][i];
        }
    }
    return 0; // Return 0 if there is no edge between src and dest
}

// Get size of the graph
int WeightedDirectedGraphMatrix::getSize() const {
    return vertices;
}

// Helper function to generate hash for a pair of integers
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

// Generate random graph
void WeightedDirectedGraphMatrix::generateRandomGraph(int density) {
    if (density < 1 || density > 100) {
        throw std::invalid_argument("Density must be between 1 and 100.");
    }

    clear();
    incidentMatrix.resize(vertices);

    std::srand(std::time(nullptr));

    int maxEdges = vertices * (vertices - 1);
    int targetEdges = (maxEdges * density) / 100;

    // Create a spanning tree to ensure connectivity
    createSpanningTree();

    // Add additional edges to meet the density
    std::unordered_set<std::pair<int, int>, pair_hash> addedEdges;
    while (targetEdges > 0) {
        int u = std::rand() % vertices;
        int v = std::rand() % vertices;
        if (u != v && addedEdges.count({u, v}) == 0) {
            int weight = (std::rand() % 10) + 1;
            addEdge(u, v, weight);
            addedEdges.insert({u, v});
            targetEdges--;
        }
    }
}

// Create a spanning tree using depth-first search
void WeightedDirectedGraphMatrix::createSpanningTree() {
    std::vector<bool> visited(vertices, false);
    std::stack<int> stack;
    int edgesAdded = 0;

    int startVertex = std::rand() % vertices;
    stack.push(startVertex);
    visited[startVertex] = true;

    while (edgesAdded < vertices - 1) {
        int currentVertex = stack.top();
        stack.pop();

        for (int neighbor = 0; neighbor < vertices; ++neighbor) {
            if (getWeight(currentVertex, neighbor) == 0 && !visited[neighbor] && currentVertex != neighbor) {
                int weight = (std::rand() % 10) + 1;
                addEdge(currentVertex, neighbor, weight);
                stack.push(neighbor);
                visited[neighbor] = true;
                edgesAdded++;
                if (edgesAdded >= vertices - 1) {
                    break;
                }
            }
        }
    }
}

// Get the first vertex index
int WeightedDirectedGraphMatrix::getFirstVertex() const {
    return 0;
}

// Get the last vertex index
int WeightedDirectedGraphMatrix::getLastVertex() const {
    return vertices - 1;
}
