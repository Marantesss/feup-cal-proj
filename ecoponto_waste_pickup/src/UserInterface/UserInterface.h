#ifndef ECOPONTO_WASTE_PICKUP_USERINTERFACE_H
#define ECOPONTO_WASTE_PICKUP_USERINTERFACE_H

#include <iostream>
#include "Graph/Graph.h"

void showTruckMenu();

int getTruckMenuOption();

void showStartingPointMenu();

void getUserOptions(unsigned int &startingPoint, unsigned int &finalPoint, string &nodeMap, string &edgeMap, string &tagsMap);

#endif //ECOPONTO_WASTE_PICKUP_USERINTERFACE_H
