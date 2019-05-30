#include "Edge.h"

Edge::Edge(unsigned int edgeId, unsigned int destNodeId, const double & weight) {
    this->edgeId = edgeId;
    this->weight = weight;
    this->destNodeId = destNodeId;
}

Edge::Edge() {

}