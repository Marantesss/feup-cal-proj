#ifndef ECOPONTO_WASTE_PICKUP_DIJNODE_H
#define ECOPONTO_WASTE_PICKUP_DIJNODE_H

#include <climits>
#include <cfloat>
#include <unordered_set>
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

struct DNodeHash {
    bool operator()(const DijNode &d1, const DijNode &d2) const {
        return d1 == d2;
    }

    int operator()(const DijNode &d) const {
        return d.getId();
    }
};

typedef unordered_set<DijNode, DNodeHash, DNodeHash> DijNodeHashTable;

#endif //ECOPONTO_WASTE_PICKUP_DIJNODE_H
