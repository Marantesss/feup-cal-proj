#include "Graph.h"

Graph::Graph() {}

// ---- Nodes
unsigned int Graph::getNumNodes() const {
    return this->nodes.size();
}


unsigned int Graph::addNode(unsigned int id, double x, double y) {
    nodes.push_back(Node(x, y, id));
}

unsigned int Graph::getNodeIndex(unsigned int id) const {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).getId() == id) {
            return i;
        }
    }
    return -1;
}

Node & Graph::getNode(unsigned int id) const {
    return const_cast<Node &>(nodes.at(getNodeIndex(id)));
}

Node Graph::getNodeByIndex(int index) {
    return nodes.at(index);
}

// ---- Edges
bool Graph::addEdge(unsigned int originNodeID, unsigned int destNodeID) {

    int node1index = getNodeIndex(originNodeID);
    if (node1index == -1) {    // Node 1 not found
        return false;
    }

    int node2index = getNodeIndex(destNodeID);
    if (node2index == -1) {    // Node 2 not found
        return false;
    }

    double weight = getNode(originNodeID).getDistanceToNode(getNode(destNodeID));

    // Add the node connections
    return nodes.at(node1index).addNodeConnection(destNodeID, weight);
}

vector<Edge> Graph::getEdges(unsigned int id) {
    return nodes.at(getNodeIndex(id)).getEdges();
}

unsigned int Graph::getNumEdges() {
    unsigned int numEdges = 0;

    for (Node n : nodes){
        numEdges += n.getNumEdges();
    }

    return numEdges;
}