#include "Truck.h"

Truck::Truck() {
    this->maxCapacity = TRUCK_MAX_CAPACITY;
    this->capacity = 0;
    this->type = WASTE;
}

Truck::Truck(truckType type) {
    this->maxCapacity = TRUCK_MAX_CAPACITY;
    this->capacity = 0;
    this->type = type;
    switch (type) {
        case WASTE:
            this->pathColor = "orange";
            break;
        case RECYCLE:
            this->pathColor = "green";
            break;
    }
}

double Truck::getCapacity() const {
    return capacity;
}

void Truck::setCapacity(double capacity) {
    Truck::capacity = capacity;
}

truckType Truck::getType() const {
    return type;
}

void Truck::setType(truckType type) {
    Truck::type = type;
}

double Truck::getMaxCapacity() const {
    return maxCapacity;
}

void Truck::setMaxCapacity(double maxCapacity) {
    Truck::maxCapacity = maxCapacity;
}

void Truck::addContainer(Container &container) {
    containers.push_back(container);
    this->capacity += container.getCapacity();
}

const vector<Container> &Truck::getContainers() const {
    return containers;
}

void Truck::setContainers(const vector<Container> &containers) {
    Truck::containers = containers;

    for (Container c : containers) {
        this->capacity += c.getCapacity();
    }
}

bool Truck::canAdd(Container &container) {
    return this->capacity + container.getCapacity() <= this->maxCapacity;
}

const vector<unsigned int> &Truck::getPath() const {
    return path;
}

void Truck::setPath(const vector<unsigned int> &path) {
    Truck::path = path;
}

const string &Truck::getPathColor() const {
    return pathColor;
}

void Truck::setPathColor(const string &pathColor) {
    Truck::pathColor = pathColor;
}

