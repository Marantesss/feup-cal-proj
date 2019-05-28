#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utils/MapParser.h"
#include "UserInterface/UserInterface.h"
#include "Algorithms/Dijkstra.h"
#include "Algorithms/NearestNeighbour.h"

using namespace std;

int main() {

    cout << " ----- WELCOME TO ECOPONTO WASTE PICKUP ----- " << endl;
    cout << "Loading Porto Map...";

    Graph graph = Graph();
    graph = parseMap("../maps/Porto/T02_nodes_X_Y_Porto.txt", "../maps/Porto/T02_edges_Porto.txt", "../maps/Porto/T02_tags_Porto.txt");
    GraphViewer* gv = buildGraphViewer(graph);

    //vector<unsigned int> wasteContainers = getBoavistaWasteContainers(graph);
    vector<unsigned int> recyclingContainers;

    cout << endl << "Porto Map loaded!" << endl;

    /*
    switch (getTruckMenuOption()) {
        case 0:
            return 0; // exit
        case 1:
            break; // unlimited capacity trucks
        case 2:
            break; // unlimited capacity recycling trucks
        case 3:
            break; // limited capacity recycling trucks
    }

    switch(getStartingPointMenuOption()) {
        case 0:
            return 0;
        case 1:
            wasteContainers = getMatosinhosWasteContainers(graph);
            recyclingContainers = getMatosinhosRecyclingContainers(graph);
            break;
        case 2:
            wasteContainers = getParanhosWasteContainers(graph);
            recyclingContainers = getParanhosRecyclingContainers(graph);
            break;
        case 3:
            wasteContainers = getBoavistaWasteContainers(graph);
            recyclingContainers = getBoavistaRecyclingContainers(graph);
            break;
    }
    */
//Dijkstra testing
/*
    Dijkstra dijkstra(graph);
    vector<unsigned int> path = dijkstra.calcOptimalPath(428214944, 428214907);

    for(unsigned int j=0;j<path.size();j++) {
        cout<<path.at(j)<<"-->";
        gv->setVertexColor(path.at(j), "red");
    }
*/

//Nearest Neighbour testing
/*
    vector<unsigned int> wasteContainers;
    wasteContainers.push_back(428216347);
    wasteContainers.push_back(428214952);
    NearestNeighbour nearestNeighbour(graph);
    vector<unsigned  int> path2 = nearestNeighbour.calculatePath(428214944, 428214907, wasteContainers );
    for(unsigned int j=0;j<path2.size();j++) {
        cout<<path2.at(j)<<"-->";
        gv->setVertexColor(path2.at(j), "pink");
    }
*/

    return 0;
}
