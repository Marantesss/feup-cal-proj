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

    string pathColor;

    vector<Container> containers;

    vector<unsigned int> path;

public:
    Truck();

    explicit Truck(truckType type);

    double getMaxCapacity() const;

    void setMaxCapacity(double maxCapacity);

    double getCapacity() const;

    void setCapacity(double capacity);

    truckType getType() const;

    void setType(truckType type);

    const vector<Container> &getContainers() const;

    void setContainers(const vector<Container> &containers);

    void addContainer(Container &container);

    bool canAdd(Container &container);

    const vector<unsigned int> &getPath() const;

    void setPath(const vector<unsigned int> &path);

    const string &getPathColor() const;

    void setPathColor(const string &pathColor);

};


#endif //ECOPONTO_WASTE_PICKUP_TRUCK_H
