#include "Container.h"

Container::Container(Node node): Node(node) {
    this->capacity = rand() % 101;
    this->maxCapacity = CONTAINER_MAX_CAPACITY;
}

Container::Container(Node node, double capacity): Node(node) {
    this->capacity = capacity;
    this->maxCapacity = CONTAINER_MAX_CAPACITY;
}

double Container::getMaxCapacity() {
    return maxCapacity;
}

void Container::setMaxCapacity(double maxCapacity) {
    Container::maxCapacity = maxCapacity;
}

double Container::getCapacity() const {
    return capacity;
}

void Container::setCapacity(double capacity) {
    Container::capacity = capacity;
}

bool Container::isValidPickup() const {
    return capacity/maxCapacity >= CONTAINER_PICKUP_VALID;
}

