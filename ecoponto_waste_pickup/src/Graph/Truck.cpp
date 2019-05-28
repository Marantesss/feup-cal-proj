#include "Truck.h"

Truck::Truck() {
    this->capacity = DBL_MAX;
    this->type = WASTE;
}

Truck::Truck(double capacity, truckType type) {
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

