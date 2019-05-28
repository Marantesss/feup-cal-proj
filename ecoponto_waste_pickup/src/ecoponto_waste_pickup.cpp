#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utils/MapParser.h"
#include "UserInterface/UserInterface.h"
#include "Algorithms/Dijkstra.h"

using namespace std;

int main() {

    cout << " ----- WELCOME TO ECOPONTO WASTE PICKUP ----- " << endl;
    cout << "Loading Porto Map...";

    Graph graph = Graph();
    graph = parseMap("../maps/Porto/T02_nodes_X_Y_Porto.txt", "../maps/Porto/T02_edges_Porto.txt", "../maps/Porto/T02_tags_Porto.txt");
    GraphViewer* gv = buildGraphViewer(graph);

    vector<unsigned int> wasteContainers;
    vector<unsigned int> recyclingContainers;

    cout << endl << "Porto Map loaded!" << endl;

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

    Dijkstra dijkstra(graph);
    vector<unsigned int> path = dijkstra.calcOptimalPath(90379759,311887142);

    cout<<"Fuck Here"<<endl;
    for(unsigned int j=0;j<path.size()-1;j++){
        cout<<path.at(j)<<"-->"<<endl;
    }

    return 0;
}
