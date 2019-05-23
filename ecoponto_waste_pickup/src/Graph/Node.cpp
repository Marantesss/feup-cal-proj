#include "Node.h"

Node::Node() {
    this->id = 0;
    this->latitude = 0;
    this->longitude = 0;
    this->type = REGULAR;
}

Node::Node(unsigned int id) : id(id) {
    this->latitude = 0;
    this->longitude = 0;
    this->type = REGULAR;
}

Node::Node(double latitude, double longitude, unsigned int id, const string &name) :
    latitude(latitude),
    longitude(longitude),
    id(id),
    name(name),
    type(REGULAR) {}

int Node::getConnectionIndex(unsigned int destNodeId) const {
    // Checks if destNodeId is already connected to this node
    for (int i = 0; i < edges.size(); i++) {
        if (edges.at(i).destNodeId == destNodeId) {
            return i;
        }
    }

    // destNodeId is not connected to this node
    return -1;
}


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

const nodeType Node::getType() const {
    return type;
}

void Node::setType(const nodeType type) {
    Node::type = type;
}

const vector<Edge> &Node::getEdges() const {
    return edges;
}

void Node::setEdges(const vector<Edge> &edges) {
    Node::edges = edges;
}

bool Node::addNodeConnection(unsigned int destNodeId , const double & weight) {
    // if destNodeId already is connected to this node, we cant add it again
    if (getConnectionIndex(destNodeId) != -1){
        return false;
    }

    // Add the new node connection
    edges.push_back( Edge(destNodeId, weight) );
    return true;
}

double Node::getDistanceToNode(const Node otherNode) {
    return sqrt(pow(this->getLatitude() - otherNode.getLatitude(), 2) +
                pow(this->getLongitude() - this->getLongitude(), 2));
}

bool Node::isDeadEnd() const {
    return edges.empty();
}

unsigned int Node::getNumEdges() {
    return edges.size();
}


