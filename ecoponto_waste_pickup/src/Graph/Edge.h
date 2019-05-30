#ifndef ECOPONTO_WASTE_PICKUP_EDGE_H
#define ECOPONTO_WASTE_PICKUP_EDGE_H


#include <string>

struct Edge {
    unsigned int edgeId;
    unsigned int destNodeId;
    double weight;

    // Constructors
    Edge();
    Edge(unsigned int edgeId, unsigned int destNodeId, const double & weight);
};


#endif //ECOPONTO_WASTE_PICKUP_EDGE_H
