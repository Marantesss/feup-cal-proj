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

    unsigned int startingNode, finalNode;
    string nodeMap, edgeMap, tagsMap;
    getUserOptions(startingNode, finalNode, nodeMap, edgeMap, tagsMap);

    if (startingNode == 0 && finalNode == 0) {
        return 0;
    }

    cout << "Loading Map..." << endl;

    Graph graph = Graph();
    graph = parseMap(nodeMap, edgeMap, tagsMap);

    cout << "Map loaded!" << endl;

    vector<Container> recyclingContainers = getRecyclingContainers(startingNode, graph);
    vector<Container> wasteContainers = getWasteContainers(startingNode, graph);

    NearestNeighbour nearestNeighbour(graph);
    vector<unsigned  int> path = nearestNeighbour.calculatePath(startingNode, finalNode, recyclingContainers);
    vector<unsigned  int> path2 = nearestNeighbour.calculatePath(startingNode, finalNode, wasteContainers);

    GraphViewer* gv = buildGraphViewer(graph);

    for(unsigned int j=0;j<path.size();j++) {
        cout<<path.at(j)<<"-->";
        gv->setVertexColor(path.at(j), "red");
    }

    for(unsigned int j=0;j<path2.size();j++) {
        cout<<path2.at(j)<<"-->";
        gv->setVertexColor(path2.at(j), "yellow");
    }


    gv->rearrange();

    return 0;
}
