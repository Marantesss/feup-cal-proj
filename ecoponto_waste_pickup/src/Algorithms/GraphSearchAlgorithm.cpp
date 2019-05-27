#include "GraphSearchAlgorithm.h"

bool GraphSearchAlgorithm::isVisited(const Node &node) const {
    return (nodeHashTable.find(node) != nodeHashTable.end());
}

GraphSearchAlgorithm::GraphSearchAlgorithm(const Graph &graph) : graph(graph) {}
