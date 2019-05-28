#ifndef ECOPONTO_WASTE_PICKUP_CONTAINER_H
#define ECOPONTO_WASTE_PICKUP_CONTAINER_H

#include "Node.h"

class Container: public Node {

private:
    double maxCapacity;

    double capacity;

public:
    Container();

    Container(Node node, double maxCapacity, double capacity);

    bool isValidPickup() const;

    double getMaxCapacity() const;

    void setMaxCapacity(double maxCapacity);

    double getCapacity() const;

    void setCapacity(double capacity);

};


#endif //ECOPONTO_WASTE_PICKUP_CONTAINER_H
