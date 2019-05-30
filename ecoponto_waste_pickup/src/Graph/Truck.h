#ifndef ECOPONTO_WASTE_PICKUP_TRUCK_H
#define ECOPONTO_WASTE_PICKUP_TRUCK_H

#include <cfloat>
#include "Utils/defs.h"
#include "Container.h"

class Truck {

private:
    double maxCapacity;

    double capacity;

    truckType type;

    vector<Container> containers;

public:
    Truck();

    Truck(double capacity, truckType type);

    double getMaxCapacity() const;

    void setMaxCapacity(double maxCapacity);

    double getCapacity() const;

    void setCapacity(double capacity);

    truckType getType() const;

    void setType(truckType type);

    const vector<Container> &getContainers() const;

    void setContainers(const vector<Container> &containers);
};


#endif //ECOPONTO_WASTE_PICKUP_TRUCK_H
