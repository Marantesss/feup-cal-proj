#ifndef ECOPONTO_WASTE_PICKUP_GRAPH_H
#define ECOPONTO_WASTE_PICKUP_GRAPH_H

#include "Node.h"

using namespace std;

class Graph {
private:
    vector<Node> nodes;

public:
    // ---- constructor
    Graph();
    // ---- Nodes
    unsigned int addNode(unsigned int id, double x, double y);
    unsigned int getNumNodes() const;
    unsigned int getNodeIndex(unsigned int id) const;
    Node & getNode(unsigned int id) const; // we need to return the reference so we can set the node type when parsing
    Node getNodeByIndex(int index);

    // ---- Edges
    bool addEdge(unsigned int originNodeID, unsigned int destNodeID);
    vector<Edge> getEdges(unsigned int id);
    unsigned int getNumEdges();
};


#endif //ECOPONTO_WASTE_PICKUP_GRAPH_H
