#include "Node.h"


//constructors
Node::Node() {
    this->id = 0;
    this->latitude = 0;
    this->longitude = 0;
}

Node::Node(unsigned int id) : id(id) {

    this->latitude = 0;
    this->longitude = 0;
}

Node::Node(double latitude, double longitude, unsigned int id, const string &name) : latitude(latitude),
                                                                                     longitude(longitude), id(id),
                                                                                     name(name) {}


//getters and setters
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

const vector<Edge> &Node::getEdges() const {
    return edges;
}

void Node::setEdges(const vector<Edge> &edges) {
    Node::edges = edges;
}

double Node::getDistance(const Node otherNode) {
    return sqrt(pow(this->getLatitude() - otherNode.getLatitude(), 2) +
                pow(this->getLongitude() - this->getLongitude(), 2));
}


