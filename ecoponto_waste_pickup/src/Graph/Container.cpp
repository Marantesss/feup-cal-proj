#include "Container.h"

Container::Container() {

}

Container::Container(Node node, double maxCapacity, double capacity): Node(node) {
    this->maxCapacity = maxCapacity;
    this->capacity = capacity;
}

double Container::getMaxCapacity() const {
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

