#include "Node.h"

double Node::getLatitude() const {
    return latitude;
}

void Node::setLatitude(double latitude) {
    Node::latitude = latitude;
}

double Node::getLongitude() const {
    return longitude;
}

void Node::setLongitude(double longitude) {
    Node::longitude = longitude;
}

unsigned int Node::getId() const {
    return id;
}

void Node::setId(unsigned int id) {
    Node::id = id;
}

const string &Node::getName() const {
    return name;
}

void Node::setName(const string &name) {
    Node::name = name;
}

Node::Node() {}

Node::Node(unsigned int id) : id(id) {}

Node::Node(double latitude, double longitude, unsigned int id, const string &name) : latitude(latitude),
                                                                                     longitude(longitude), id(id),
                                                                                     name(name) {}


