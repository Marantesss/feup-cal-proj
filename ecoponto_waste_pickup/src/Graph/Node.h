#ifndef ECOPONTO_WASTE_PICKUP_NODE_H
#define ECOPONTO_WASTE_PICKUP_NODE_H

#include <string>
#include <vector>
using namespace std;

class Node {
protected:
    double latitude, longitude;
    unsigned int id;
    string name;
public:
    const string &getName() const;

    void setName(const string &name);

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
};


#endif //ECOPONTO_WASTE_PICKUP_NODE_H
