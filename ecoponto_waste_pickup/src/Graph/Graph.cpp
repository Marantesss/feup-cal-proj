#include "Graph.h"

Graph::Graph() {}

// ---- Nodes
unsigned int Graph::getNumNodes() {
    return this->nodes.size();
}


unsigned int Graph::addNode(unsigned int id, double latitude, double longitude, string name) {
    nodes.push_back(Node(latitude, longitude, id, name));
}

unsigned int Graph::getNodeIndex(unsigned int id) {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).getId() == id) {
            return i;
        }
    }
    return -1;
}

Node &Graph::getNode(unsigned int id) {
    return nodes.at(getNodeIndex(id));
}

Node Graph::getNodeByIndex(int index) {
    return nodes.at(index);
}

// ---- Edges

bool Graph::addEdge(unsigned int nodeId1, unsigned int nodeId2, const double &weight) {
    if (nodeId1 == nodeId2) {
        return false;
    }

    int node1index = getNodeIndex(nodeId1);
    if (node1index == -1) {    // Node 1 not found
        return false;
    }

    int node2index = getNodeIndex(nodeId2);
    if (node2index == -1) {    // Node 2 not found
        return false;
    }

    // Add the node connections
    return nodes.at(node1index).addNodeConnection(node2index, weight);
}

vector<Edge> Graph::getEdges(unsigned int Id) {
    return nodes.at(getNodeIndex(Id)).getEdges();
}
