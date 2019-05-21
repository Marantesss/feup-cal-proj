#include "edge.h"

Edge::Edge(unsigned int destNodeId, const double & weight, const std::string & name) {
    this->weight = weight;
    this->destNodeId = destNodeId;
    this->name =name;
}

Edge::Edge(unsigned int destNodeId, const double & weight) {

}

Edge::Edge() {

}