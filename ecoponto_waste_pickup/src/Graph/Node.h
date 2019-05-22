#ifndef ECOPONTO_WASTE_PICKUP_NODE_H
#define ECOPONTO_WASTE_PICKUP_NODE_H

#include <string>
#include <vector>
#include <tgmath.h>
#include "Edge.h"
#include "../Utils/defs.h"

using namespace std;

class Node {
protected:
    double latitude, longitude;
    unsigned int id;
    string name;
    nodeType type;
    vector<Edge> edges;
    int getConnectionIndex(unsigned int destNodeId) const;
public:
    Node(double latitude, double longitude, unsigned int id, const string &name);
    Node(unsigned int id);
    Node();

    unsigned int getId() const;
    void setId(unsigned int id);

    double getLatitude() const;
    void setLatitude(double latitude);

    double getLongitude() const;
    void setLongitude(double longitude);

    const string &getName() const;
    void setName(const string &name);

    const nodeType getType() const;
    void setType(const nodeType type);

    const vector<Edge> &getEdges() const;
    void setEdges(const vector<Edge> &edges);
    bool addNodeConnection(unsigned int destNodeId, const double & weight);

    double getDistanceToNode(const Node otherNode);

};


#endif //ECOPONTO_WASTE_PICKUP_NODE_H
