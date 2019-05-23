#include "Edge.h"

Edge::Edge(unsigned int destNodeId, const double & weight) {
    this->weight = weight;
    this->destNodeId = destNodeId;
}

Edge::Edge() {

}