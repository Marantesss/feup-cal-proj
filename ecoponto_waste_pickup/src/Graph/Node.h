#ifndef ECOPONTO_WASTE_PICKUP_NODE_H
#define ECOPONTO_WASTE_PICKUP_NODE_H

#include <string>
#include <vector>
#include <tgmath.h>
#include <climits>
#include <cfloat>
#include <unordered_set>
#include "Edge.h"
#include "../Utils/defs.h"

using namespace std;

class Node {
protected:

    double x, y;

    unsigned int id;

    nodeType type;

    vector<Edge> edges;

    // Checks if destNodeId can be reached with the edges vector starting in this node
    unsigned int getConnectionIndex(unsigned int destNodeId) const;

public:
    // ---- Constructors
    Node(double x, double y, unsigned int id);
    Node(unsigned int id);
    Node();

    // ---- ID getter and setter
    unsigned int getId() const;
    void setId(unsigned int id);

    // ---- Latitude getter and setter
    double getX() const;
    void setX(double latitude);

    // ---- Longitude getter and setter
    double getY() const;
    void setY(double longitude);

    // ---- Type getter and setter
    const nodeType getType() const;
    void setType(const nodeType type);

    // ---- Edges getter, setter and adder
    const vector<Edge> &getEdges() const;
    void setEdges(const vector<Edge> &edges);
    bool addNodeConnection(unsigned int destNodeId, const double & weight);
    unsigned int getNumEdges();

    // ---- Calculate the distance between this node and otherNode in a straight line
    double getDistanceToNode(const Node otherNode);

    // ---- Cheks if node has no connections
    bool isDeadEnd() const;

    // ---- Equality operator
    bool operator==(const Node &d2) const;

    // ---- Not equal Operator
    bool operator!=(const Node &d2) const;
};

struct NodeHash {
    bool operator()(const Node &d1, const Node &d2) const {
        return d1 == d2;
    }

    unsigned int operator()(const Node &d) const {
        return d.getId();
    }
};

typedef unordered_set<Node, NodeHash, NodeHash> NodeHashTable;

#endif //ECOPONTO_WASTE_PICKUP_NODE_H
