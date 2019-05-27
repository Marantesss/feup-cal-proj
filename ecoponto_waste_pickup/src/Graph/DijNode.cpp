#include "DijNode.h"

DijNode::DijNode() : Node(){
    this->lastNodeId = UINT_MAX;
    this->totalWeight = DBL_MAX;
}


DijNode::DijNode(const Node &  node, unsigned int lastNodeId , double totalWeight): Node(node) {
    this->lastNodeId = lastNodeId;
    this->totalWeight = totalWeight;
}


DijNode::DijNode(unsigned int id, unsigned int lastNodeId) {
    this->id = id;
    this->lastNodeId = lastNodeId;
}


DijNode::DijNode(const Node &node, double totalWeight) :Node(node){
    this->lastNodeId = UINT_MAX;
    this->totalWeight = totalWeight;
}


DijNode::DijNode(const Node &  node) : Node(node){
    this->lastNodeId = UINT_MAX;
    this->totalWeight = DBL_MAX;
}


DijNode::DijNode(unsigned int id) : Node(id){
    this->lastNodeId = UINT_MAX;
    this->totalWeight = DBL_MAX;
}


unsigned int DijNode::getLastNodeId() const {
    return lastNodeId;
}


double DijNode::getTotalWeight() const {
    return totalWeight;
}


bool DijNode::operator<(const DijNode& d2) const{
    if(this->totalWeight == d2.getTotalWeight()){
        return this->id < d2.id;
    } else {
        return this->totalWeight < d2.getTotalWeight();
    }
}


bool DijNode::operator==(const DijNode& d2) const{
    return this->id == d2.id;
}


bool DijNode::operator!=(const DijNode& d2) const{
    return !(this->id == d2.id);
}
