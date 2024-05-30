//
// Created by ogore on 29.05.2024.
//
#include "../header/WeightedDirectedGraphMatrix.h"
#include <iomanip> // For std::setw

// Constructor
WeightedDirectedGraphMatrix::WeightedDirectedGraphMatrix(int vertices, int edges)
        : vertices(vertices), edges(edges) {
    incidentMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        incidentMatrix[i] = new int[edges]();
    }
}

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

    for (int i = 0; i < edges; ++i) {
        if (incidentMatrix[src][i] == 0 && incidentMatrix[dest][i] == 0) {
            incidentMatrix[src][i] = weight;
            incidentMatrix[dest][i] = -weight;
            return;
        }
    }

    throw std::runtime_error("No available edge slot for the given vertices.");
}

// Print graph
void WeightedDirectedGraphMatrix::printGraph() const {
    std::cout << "Incident Matrix:" << std::endl;
    std::cout << "   ";
    for (int j = 0; j < vertices; ++j) {
        std::cout << std::setw(3) << j << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < vertices; ++i) {
        std::cout << std::setw(2) << i << ": ";
        for (int j = 0; j < vertices; ++j) {
            std::cout << std::setw(3) << incidentMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


// Deep copy
void WeightedDirectedGraphMatrix::deepCopy(const WeightedDirectedGraphMatrix& other) {
    vertices = other.vertices;
    edges = other.edges;
    incidentMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        incidentMatrix[i] = new int[edges];
        for (int j = 0; j < edges; ++j) {
            incidentMatrix[i][j] = other.incidentMatrix[i][j];
        }
    }
}

// Clear memory
void WeightedDirectedGraphMatrix::clear() {
    for (int i = 0; i < vertices; ++i) {
        delete[] incidentMatrix[i];
    }
    delete[] incidentMatrix;
    incidentMatrix = nullptr;
}

// Get weight between two vertices
int WeightedDirectedGraphMatrix::getWeight(int src, int dest) const {
    for (int i = 0; i < edges; ++i) {
        if (incidentMatrix[src][i] != 0 && incidentMatrix[dest][i] != 0) {
            return incidentMatrix[src][i];
        }
    }
    return 0; // Return 0 if there is no edge between src and dest
}

// Get size of the graph
int WeightedDirectedGraphMatrix::getSize() const {
    return vertices;
}

// Generate random graph
void WeightedDirectedGraphMatrix::generateRandomGraph(int density) {
    if (density < 1 || density > 100) {
        throw std::invalid_argument("Density must be between 1 and 100.");
    }

    clear();
    incidentMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        incidentMatrix[i] = new int[edges]();
    }

    std::srand(std::time(nullptr));

    std::vector<bool> inMST(vertices, false);
    inMST[0] = true;
    int addedEdges = 0;

    for (int i = 1; i < vertices; ++i) {
        int u = std::rand() % vertices;
        while (!inMST[u]) {
            u = std::rand() % vertices;
        }
        int v = std::rand() % vertices;
        while (inMST[v]) {
            v = std::rand() % vertices;
        }
        int weight = (std::rand() % 10) + 1;
        addEdge(u, v, weight);
        inMST[v] = true;
        addedEdges++;
    }

    int maxEdges = vertices * (vertices - 1);
    int targetEdges = (maxEdges * density) / 100;

    std::unordered_set<std::pair<int, int>, pair_hash> existingEdges;

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < edges; ++j) {
            if (incidentMatrix[i][j] != 0) {
                int src = i;
                int dest = -1;
                for (int k = 0; k < vertices; ++k) {
                    if (incidentMatrix[k][j] == -incidentMatrix[i][j]) {
                        dest = k;
                        break;
                    }
                }
                if (dest != -1) {
                    existingEdges.emplace(src, dest);
                }
            }
        }
    }

    while (addedEdges < targetEdges) {
        int u = std::rand() % vertices;
        int v = std::rand() % vertices;
        if (u != v && existingEdges.find({u, v}) == existingEdges.end()) {
            int weight = (std::rand() % 10) + 1;
            addEdge(u, v, weight);
            existingEdges.emplace(u, v);
            addedEdges++;
        }

        if (existingEdges.size() == maxEdges) {
            break;
        }
    }
}
