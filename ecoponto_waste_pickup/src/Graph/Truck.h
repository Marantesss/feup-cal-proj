#ifndef ECOPONTO_WASTE_PICKUP_TRUCK_H
#define ECOPONTO_WASTE_PICKUP_TRUCK_H

#include <cfloat>
#include "Utils/defs.h"

class Truck {

private:
    double capacity;

    truckType type;

public:
    Truck();

    Truck(double capacity, truckType type);

    double getCapacity() const;

    void setCapacity(double capacity);

    truckType getType() const;

    void setType(truckType type);
};


#endif //ECOPONTO_WASTE_PICKUP_TRUCK_H
