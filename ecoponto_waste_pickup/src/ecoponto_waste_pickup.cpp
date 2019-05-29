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
    vector<unsigned int> path = dijkstra.calcOptimalPath(BOAVISTA_PARKING_NODE_ID, BOAVISTA_WASTE_STATION_NODE_ID);

    for(unsigned int j=0;j<path.size();j++) {
        cout<<path.at(j)<<"-->";
        gv->setVertexColor(path.at(j), "pink");
    }
     */

    DFS dfs = DFS(graph);
    NodeHashTable accessNodes = dfs.performSearch(BOAVISTA_PARKING_NODE_ID);
    NodeHashTable::iterator it;

    vector<Container> wasteContainers;

    for (it = accessNodes.begin(); it != accessNodes.end(); it++) {
        if (it->getType() == RECYCLING_CONTAINER && isBoavista(*it)) {
            Container newContainer = Container(*it);
            if (newContainer.isValidPickup())
                wasteContainers.push_back(newContainer);
        }
    }

    if(dfs.isPossible(BOAVISTA_PARKING_NODE_ID, BOAVISTA_WASTE_STATION_NODE_ID))
        cout << "is possible" << endl;

    //Nearest Neighbour testing DOES NOT WORK SOMETIMES :( SAD LIFE
    NearestNeighbour nearestNeighbour(graph);
    vector<unsigned  int> path2 = nearestNeighbour.calculatePath(BOAVISTA_PARKING_NODE_ID, BOAVISTA_WASTE_STATION_NODE_ID, wasteContainers );
    for(unsigned int j=0;j<path2.size();j++) {
        cout<<path2.at(j)<<"-->";
        gv->setVertexColor(path2.at(j), "pink");
    }

    gv->rearrange();

    return 0;
}
