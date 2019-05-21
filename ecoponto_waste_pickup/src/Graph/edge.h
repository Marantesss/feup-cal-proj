#ifndef ECOPONTO_WASTE_PICKUP_EDGE_H
#define ECOPONTO_WASTE_PICKUP_EDGE_H


#include <string>

struct Edge {
    unsigned int destNodeId;
    double weight;
    std::string name;

    // Constructors
    Edge();
    Edge(unsigned int destNodeId, const double & weight);
    Edge(unsigned int destNodeId, const double & weight, const std::string & name);
};


#endif //ECOPONTO_WASTE_PICKUP_EDGE_H
