#ifndef ECOPONTO_WASTE_PICKUP_USERINTERFACE_H
#define ECOPONTO_WASTE_PICKUP_USERINTERFACE_H

#include <iostream>
#include "Graph/Truck.h"
#include "Graph/Graph.h"
#include "Utils/defs.h"
#include "Utils/MapParser.h"

void showStartingPointMenu();

void getUserMapOptions(unsigned int &startingPoint, unsigned int &finalPoint, string &nodeMap, string &edgeMap, string &tagsMap);

void showTruckMenu();

void getUserTruckOptions(vector<Truck> &trucks, vector<Container> &wasteContainers, vector<Container> &recyclingContainers);

void allocateTruckContainers(vector<Truck> &trucks, vector<Container> &wasteContainers, vector<Container> &recyclingContainers);

#endif //ECOPONTO_WASTE_PICKUP_USERINTERFACE_H
