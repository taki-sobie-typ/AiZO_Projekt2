//
// Created by ogore on 29.05.2024.
//
#include "../header/WeightedDirectedGraphMatrix.h"
#include <algorithm>
#include <queue>
#include <unordered_set>

// Custom hash function for std::pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

// Konstruktor
WeightedDirectedGraphMatrix::WeightedDirectedGraphMatrix(int vertices, int edges)
        : vertices(vertices), edges(edges) {
    incidentMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        incidentMatrix[i] = new int[edges]();
    }
}

// Konstruktor kopiujący
WeightedDirectedGraphMatrix::WeightedDirectedGraphMatrix(const WeightedDirectedGraphMatrix& other) {
    deepCopy(other);
}

// Operator przypisania
WeightedDirectedGraphMatrix& WeightedDirectedGraphMatrix::operator=(const WeightedDirectedGraphMatrix& other) {
    if (this != &other) {
        clear();
        deepCopy(other);
    }
    return *this;
}

// Destruktor
WeightedDirectedGraphMatrix::~WeightedDirectedGraphMatrix() {
    clear();
}

// Dodawanie krawędzi
void WeightedDirectedGraphMatrix::addEdge(int src, int dest, int weight) {
    if (weight <= 0) {
        throw std::invalid_argument("Edge weight must be a positive number.");
    }

    // Szukamy wolnej kolumny (krawędzi) w macierzy incydencji
    for (int i = 0; i < edges; ++i) {
        if (incidentMatrix[src][i] == 0 && incidentMatrix[dest][i] == 0) {
            incidentMatrix[src][i] = weight;
            incidentMatrix[dest][i] = -weight;
            return;
        }
    }

    throw std::runtime_error("No available edge slot for the given vertices.");
}

// Wyświetlanie grafu
void WeightedDirectedGraphMatrix::printGraph() const {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < edges; ++j) {
            std::cout << incidentMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Głębokie kopiowanie
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

// Usuwanie dynamicznie alokowanej pamięci
void WeightedDirectedGraphMatrix::clear() {
    for (int i = 0; i < vertices; ++i) {
        delete[] incidentMatrix[i];
    }
    delete[] incidentMatrix;
    incidentMatrix = nullptr;
}

// Generowanie losowego grafu
void WeightedDirectedGraphMatrix::generateRandomGraph(int density) {
    if (density < 1 || density > 100) {
        throw std::invalid_argument("Density must be between 1 and 100.");
    }

    // Resetowanie grafu
    clear();
    incidentMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        incidentMatrix[i] = new int[edges]();
    }

    std::srand(std::time(nullptr));

    // Generowanie minimalnego drzewa rozpinającego
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
        int weight = (std::rand() % 10) + 1; // Random weight between 1 and 10
        addEdge(u, v, weight);
        inMST[v] = true;
        addedEdges++;
    }

    // Dodawanie dodatkowych krawędzi do osiągnięcia żądanej gęstości
    int maxEdges = vertices * (vertices - 1);
    int targetEdges = (maxEdges * density) / 100;

    std::unordered_set<std::pair<int, int>, pair_hash> existingEdges;

    // Collecting existing edges
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

    // Generate additional edges
    while (addedEdges < targetEdges) {
        int u = std::rand() % vertices;
        int v = std::rand() % vertices;
        if (u != v && existingEdges.find({u, v}) == existingEdges.end()) {
            int weight = (std::rand() % 10) + 1; // Random weight between 1 and 10
            addEdge(u, v, weight);
            existingEdges.emplace(u, v);
            addedEdges++;
        }

        // Break if no more unique edges can be added to avoid endless loop
        if (existingEdges.size() == maxEdges) {
            break;
        }
    }
}

