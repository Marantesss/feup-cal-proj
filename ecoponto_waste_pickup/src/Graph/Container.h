#ifndef ECOPONTO_WASTE_PICKUP_CONTAINER_H
#define ECOPONTO_WASTE_PICKUP_CONTAINER_H

#include "Node.h"

class Container: public Node {

private:
    double maxCapacity;

    double capacity;

public:
    Container(Node node);

    Container(Node node, double capacity);

    bool isValidPickup() const;

    double getMaxCapacity() ;

    void setMaxCapacity(double maxCapacity);

    double getCapacity() const;

    void setCapacity(double capacity);

};

struct ContainerHash {
    bool operator()(const Node &d1, const Node &d2) const {
        return d1 == d2;
    }

    unsigned int operator()(const Node &d) const {
        return d.getId();
    }
};

typedef unordered_set<Container, ContainerHash, ContainerHash> ContainerHashTable;

#endif //ECOPONTO_WASTE_PICKUP_CONTAINER_H
