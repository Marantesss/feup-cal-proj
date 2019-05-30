#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utils/MapParser.h"
#include "UserInterface/UserInterface.h"
#include "Algorithms/Dijkstra.h"
#include "Algorithms/NearestNeighbour.h"
#include "Graph/Graph.h"

using namespace std;

int main() {

    cout << " ----- WELCOME TO ECOPONTO WASTE PICKUP ----- " << endl;

    // ---- MAP OPTIONS
    unsigned int startingNode, finalNode;
    string nodeMap, edgeMap, tagsMap;
    getUserMapOptions(startingNode, finalNode, nodeMap, edgeMap, tagsMap);

    if (startingNode == 0 && finalNode == 0) {
        return 0;
    }

    cout << "Loading Map..." << endl;

    Graph graph = Graph();
    graph = parseMap(nodeMap, edgeMap, tagsMap);

    cout << "Map loaded!" << endl;

    cout << "Generating Containers..." << endl;

    vector<Container> recyclingContainers;
    vector<Container> wasteContainers;

    getContainers(startingNode, graph, wasteContainers, recyclingContainers);

    cout << "Containers generated!" << endl;

    // ---- TRUCK OPTIONS
    vector<Truck> trucks;

    getUserTruckOptions(trucks, wasteContainers, recyclingContainers);

    NearestNeighbour nearestNeighbour(graph);

    /*
    vector<unsigned  int> path = nearestNeighbour.calculatePath(startingNode, finalNode, wasteContainers);
    */

    vector<Truck>::iterator it;
    for (it = trucks.begin(); it != trucks.end(); it++) {
        it->setPath(nearestNeighbour.calculatePath(startingNode, finalNode, it->getContainers()));
    }

    cout << "Path calculated!" << endl;

    GraphViewer* gv = buildGraphViewer(graph);

    for (Truck t : trucks) {
        vector<unsigned  int> path = t.getPath();
        if (path.size() != 0)
            for(unsigned int i = 0; i< path.size() - 1; i++) {
                if (t.getType() == WASTE) {
                    gv->setEdgeThickness(graph.getNode(path.at(i)).getNodeConntected(path.at(i + 1)), 10);
                    gv->setEdgeColor(graph.getNode(path.at(i)).getNodeConntected(path.at(i + 1)), "orange");
                } else if (t.getType() == RECYCLE) {
                    gv->setEdgeThickness(graph.getNode(path.at(i)).getNodeConntected(path.at(i + 1)), 10);
                    gv->setEdgeColor(graph.getNode(path.at(i)).getNodeConntected(path.at(i + 1)), "green");
                }
            }
    }

    gv->rearrange();

    return 0;
}
