#include "DFS.h"

void DFS::visitNode(const Node &node) {
    if (!isVisited(node)) {
        nodeHashTable.insert(node);

        for (Edge e : node.getEdges())
            visitNode(graph.getNode(e.destNodeId));
    }
}

bool DFS::visitNodeCondition(const Node &node, const Node &end) {
    if (node == end)
        return true;
    if (!isVisited(node)) {
        nodeHashTable.insert(node);

        for (Edge e : node.getEdges()) {
            visitNodeCondition(graph.getNode(e.destNodeId), end);
            return true;
        }
    }
    return false;
}

DFS::DFS(const Graph &graph) : GraphSearchAlgorithm(graph){}

NodeHashTable DFS::performSearch(unsigned int start) {
    Node startNode;

    startNode=graph.getNode(start);

    nodeHashTable.clear();
    visitNode(startNode);

    return nodeHashTable;
}

bool DFS::isPossible(unsigned int start, unsigned int end) {
    Node startNode;
    Node endNode;

    startNode = graph.getNode(start);
    endNode = graph.getNode(end);

    nodeHashTable.clear();
    return visitNodeCondition(startNode,endNode);
}
