#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utils/MapParser.h"
#include "UserInterface/UserInterface.h"

using namespace std;

int main() {
    cout << " ----- WELCOME TO ECOPONTO WASTE PICKUP ----- " << endl;
    cout << "Loading Porto Map...";

    Graph graph = Graph();
    graph = parseMap("../maps/Porto/T02_nodes_X_Y_Porto.txt", "../maps/Porto/T02_edges_Porto.txt", "../maps/Porto/T02_tags_Porto.txt");
    GraphViewer* gv = buildGraphViewer(graph);

    vector<unsigned int> matosinhosWasteContainers = getMatosinhosWasteContainers(graph);
    vector<unsigned int> matosinhosRecyclingContainers = getMatosinhosRecyclingContainers(graph);

    vector<unsigned int> boavistaWasteContainers = getBoavistaWasteContainers(graph);
    vector<unsigned int> boavistaRecyclingContainers = getBoavistaRecyclingContainers(graph);

    vector<unsigned int> paranhosWasteContainers = getParanhosWasteContainers(graph);
    vector<unsigned int> paranhosRecyclingContainers = getParanhosRecyclingContainers(graph);

    cout << endl << "Porto Map loaded!" << endl;

    showTruckMenu();

    showStartingPointMenu();

    return 0;
}
