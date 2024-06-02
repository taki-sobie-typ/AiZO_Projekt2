//
// Created by Patryk on 31.05.2024.
//

#include "../header/DijkstraShortestPathMatrix.h"
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm> // For std::reverse
#include <limits>    // For std::numeric_limits

DijkstraShortestPathMatrix::DijkstraShortestPathMatrix(const WeightedDirectedGraphMatrix& graph)
        : graph(graph) {}

std::vector<int> DijkstraShortestPathMatrix::findShortestPath(int startVertex, int endVertex) {
    int vertices = graph.getSize();
    std::vector<int> distances(vertices, std::numeric_limits<int>::max());
    std::vector<int> previous(vertices, -1);
    std::vector<bool> visited(vertices, false);

    distances[startVertex] = 0;

    auto compare = [&](int left, int right) { return distances[left] > distances[right]; };
    std::priority_queue<int, std::vector<int>, decltype(compare)> pq(compare);
    pq.push(startVertex);

    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        for (int neighbor = 0; neighbor < vertices; ++neighbor) {
            int weight = graph.getWeight(current, neighbor);
            if (weight > 0 && !visited[neighbor]) {
                int newDist = distances[current] + weight;
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    previous[neighbor] = current;
                    pq.push(neighbor);
                }
            }
        }
    }

    return getPath(previous, startVertex, endVertex);
}

std::vector<int> DijkstraShortestPathMatrix::getPath(const std::vector<int>& previous, int startVertex, int endVertex) const {
    std::vector<int> path;
    for (int at = endVertex; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());
    if (path.size() == 1 && path[0] != startVertex) {
        path.clear(); // No path found
    }
    return path;
}

void DijkstraShortestPathMatrix::printShortestPath(const std::vector<int>& path) const {
    if (path.empty()) {
        std::cout << "No path found." << std::endl;
        return;
    }

    int totalDistance = 0;
    for (size_t i = 1; i < path.size(); ++i) {
        totalDistance += graph.getWeight(path[i - 1], path[i]);
    }

    std::cout << "Shortest path from vertex " << path.front() << " to vertex " << path.back() << ": ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
    std::cout << "Total distance: " << totalDistance << std::endl;
}
