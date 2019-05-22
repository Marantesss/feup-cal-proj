#ifndef ECOPONTO_WASTE_PICKUP_GRAPH_H
#define ECOPONTO_WASTE_PICKUP_GRAPH_H

#include "Node.h"

using namespace std;

class Graph {
private:
    vector<Node> nodes;

public:
    Graph();

    unsigned int addNode(double latitude, double longitude, string name);
    unsigned int getNumNodes();
    unsigned int getNodeIndex(unsigned int Id);
    Node getNode(unsigned int Id);
    vector<Edge> getEdges(unsigned int Id);

};


#endif //ECOPONTO_WASTE_PICKUP_GRAPH_H
