#ifndef ECOPONTO_WASTE_PICKUP_NODE_H
#define ECOPONTO_WASTE_PICKUP_NODE_H

#include <string>
#include <vector>
#include <tgmath.h>
#include "edge.h"
using namespace std;

class Node {
protected:
    double latitude, longitude;
    unsigned int id;
    string name;
    vector<Edge> edges;
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

    const vector<Edge> &getEdges() const;
    void setEdges(const vector<Edge> &edges);

    double getDistance(const Node otherNode);

};


#endif //ECOPONTO_WASTE_PICKUP_NODE_H
