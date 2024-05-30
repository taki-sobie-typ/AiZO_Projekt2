//
// Created by Patryk on 30.05.2024.
//

#include "../header/WeightedDirectedGraphList.h"

// Constructor
WeightedDirectedGraphList::WeightedDirectedGraphList(int vertices)
        : vertices(vertices),
          successors(vertices),
          predecessors(vertices) {}

// Copy constructor
WeightedDirectedGraphList::WeightedDirectedGraphList(const WeightedDirectedGraphList& other) {
    deepCopy(other);
}

// Assignment operator
WeightedDirectedGraphList& WeightedDirectedGraphList::operator=(const WeightedDirectedGraphList& other) {
    if (this != &other) {
        clear();
        deepCopy(other);
    }
    return *this;
}

// Destructor
WeightedDirectedGraphList::~WeightedDirectedGraphList() {
    clear();
}

// Add edge
void WeightedDirectedGraphList::addEdge(int src, int dest, int weight) {
    if (weight <= 0) {
        throw std::invalid_argument("Edge weight must be a positive number.");
    }
    successors[src][dest] = weight;
    predecessors[dest][src] = weight;
}

// Print graph
void WeightedDirectedGraphList::printGraph() const {
    std::cout << "Graph Representation (Successors and Predecessors):" << std::endl;

    std::cout << "Successors:" << std::endl;
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << ": ";
        for (const auto& [dest, weight] : successors[i]) {
            std::cout << "(" << dest << ", " << weight << ") ";
        }
        std::cout << std::endl;
    }

    std::cout << "Predecessors:" << std::endl;
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << ": ";
        for (const auto& [src, weight] : predecessors[i]) {
            std::cout << "(" << src << ", " << weight << ") ";
        }
        std::cout << std::endl;
    }
}

// Deep copy
void WeightedDirectedGraphList::deepCopy(const WeightedDirectedGraphList& other) {
    vertices = other.vertices;
    successors = other.successors;
    predecessors = other.predecessors;
}

// Clear memory
void WeightedDirectedGraphList::clear() {
    successors.clear();
    predecessors.clear();
}

// Get weight between two vertices
int WeightedDirectedGraphList::getWeight(int src, int dest) const {
    auto it = successors[src].find(dest);
    if (it != successors[src].end()) {
        return it->second;
    }
    return 0; // Return 0 if there is no edge between src and dest
}

// Get size of the graph
int WeightedDirectedGraphList::getSize() const {
    return vertices;
}

// Get successors of a vertex
const std::unordered_map<int, int>& WeightedDirectedGraphList::getSuccessors(int vertex) const {
    return successors[vertex];
}


// Generate random graph
void WeightedDirectedGraphList::generateRandomGraph(int density) {
    if (density < 1 || density > 100) {
        throw std::invalid_argument("Density must be between 1 and 100.");
    }

    clear();
    successors.resize(vertices);
    predecessors.resize(vertices);

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

    while (addedEdges < targetEdges) {
        int u = std::rand() % vertices;
        int v = std::rand() % vertices;
        if (u != v && successors[u].find(v) == successors[u].end()) {
            int weight = (std::rand() % 10) + 1;
            addEdge(u, v, weight);
            addedEdges++;
        }

        if (addedEdges >= maxEdges) {
            break;
        }
    }
}
