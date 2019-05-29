#include "Truck.h"

Truck::Truck() {
    this->maxCapacity = TRUCK_MAX_CAPACITY;
    this->capacity = 0;
    this->type = WASTE;
}

Truck::Truck(double capacity, truckType type) {
    this->maxCapacity = TRUCK_MAX_CAPACITY;
    this->capacity = capacity;
    this->type = type;
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

