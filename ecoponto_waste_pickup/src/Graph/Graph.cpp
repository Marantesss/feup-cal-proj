#include "Graph.h"

unsigned int Graph::getNumNodes() {
    return this->nodes.size();
}

unsigned int Graph::addNode(double latitude, double longitude, string name) {
    unsigned int id = nodes.size();
    nodes.push_back(Node(latitude, longitude, id, name));
}

unsigned int Graph::getNodeIndex(unsigned int Id) {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).getId() == Id) {
            return i;
        }
    }
    return -1;
}

Node Graph::getNode(unsigned int Id) {
    return nodes.at(getNodeIndex(Id));
}

vector<Edge> Graph::getEdges(unsigned int Id) {
    return nodes.at(getNodeIndex(Id)).getEdges();
}

Graph::Graph() {}
