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

    cout << "Generating Containers..." << endl;

    vector<Container> recyclingContainers;
    vector<Container> wasteContainers;

    getContainers(startingNode, graph, wasteContainers, recyclingContainers);

    cout << "Containers generated!" << endl;

    cout << "Calculating path..." << endl;

    NearestNeighbour nearestNeighbour(graph);
    vector<unsigned  int> path2 = nearestNeighbour.calculatePath(startingNode, finalNode, recyclingContainers);
    vector<unsigned  int> path = nearestNeighbour.calculatePath(startingNode, finalNode, wasteContainers);

    cout << "Path calculated!" << endl;

    GraphViewer* gv = buildGraphViewer(graph);

    append_vector(path, path2);

    for (Container c : wasteContainers) {
        gv->setVertexColor(c.getId(), "pink");
    }

    if (path.size() != 0)
        for(unsigned int j=0;j<path.size() - 1;j++) {
            gv->setEdgeThickness(graph.getNode(path.at(j)).getNodeConntected(path.at(j+1)), 10);
            gv->setEdgeColor(graph.getNode(path.at(j)).getNodeConntected(path.at(j+1)), "red");

        }

    gv->rearrange();

    return 0;
}
