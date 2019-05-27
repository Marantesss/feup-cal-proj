#include "Node.h"

Node::Node() {
    this->id = 0;
    this->x = 0;
    this->y = 0;
    this->type = REGULAR;
}

Node::Node(unsigned int id) : id(id) {
    this->x = 0;
    this->y = 0;
    this->type = REGULAR;
}

Node::Node(double x, double y, unsigned int id) :
    x(x),
    y(y),
    id(id),
    type(REGULAR) {}

unsigned int Node::getConnectionIndex(unsigned int destNodeId) const {
    // Checks if destNodeId is already connected to this node
    for (unsigned int i = 0; i < edges.size(); i++) {
        if (edges.at(i).destNodeId == destNodeId) {
            return i;
        }
    }

    // destNodeId is not connected to this node
    return -1;
}


//getters and setters
double Node::getX() const {
    return x;
}

void Node::setX(double x) {
    Node::x = x;
}

double Node::getY() const {
    return y;
}

void Node::setY(double y) {
    Node::y = y;
}

unsigned int Node::getId() const {
    return id;
}

void Node::setId(unsigned int id) {
    Node::id = id;
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
    return sqrt(pow(this->getX() - otherNode.getX(), 2) +
                pow(this->getY() - this->getY(), 2));
}

bool Node::isDeadEnd() const {
    return edges.empty();
}

unsigned int Node::getNumEdges() {
    return edges.size();
}

bool Node::operator==(const Node& d2) const{
    return this->id == d2.id;
}


bool Node::operator!=(const Node& d2) const{
    return !(this->id == d2.id);
}

