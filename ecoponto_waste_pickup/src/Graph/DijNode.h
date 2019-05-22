#ifndef ECOPONTO_WASTE_PICKUP_DIJNODE_H
#define ECOPONTO_WASTE_PICKUP_DIJNODE_H

#include <climits>
#include <cfloat>
#include "Node.h"

class DijNode: public Node {
private:
    unsigned int lastNodeId;
    double totalWeight;

public:
    // Constructors
    DijNode();
    DijNode(const Node & node , unsigned int lastNodeId , double totalWeight);
    DijNode(const Node &  node, double totalWeight);
    DijNode(const Node &  node);
    DijNode(unsigned int id);
    DijNode(unsigned int id , unsigned int lastNodeId);

    // ---- lastNodeId getter
    unsigned int getLastNodeId() const;

    // ---- totalWeight getter
    double getTotalWeight() const;

    // ---- 'Less than' operator
    virtual bool operator<(const DijNode& d2) const;

    // ---- Equality operator
    bool operator==(const DijNode& d2) const;

    // ---- Not equal Operator
    bool operator!=(const DijNode& d2) const;
};


#endif //ECOPONTO_WASTE_PICKUP_DIJNODE_H
