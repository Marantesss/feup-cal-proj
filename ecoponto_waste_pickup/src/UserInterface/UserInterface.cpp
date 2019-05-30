#include "UserInterface.h"

using namespace std;

void showStartingPointMenu() {
    cout << "Please choose the truck parking lot location:" << endl;
    cout << "1 - Matosinhos (Parking Lot Node ID: " << MATOSINHOS_PARKING_NODE_ID << "\tWaste Management Station Node ID:" << MATOSINHOS_WASTE_STATION_NODE_ID << ")" << endl;
    cout << "2 - Paranhos (Parking Lot Node ID: " << PARANHOS_PARKING_NODE_ID << "\tWaste Management Station Node ID:" << PARANHOS_WASTE_STATION_NODE_ID << ")" << endl;
    cout << "3 - Boavista (Parking Lot Node ID: " << BOAVISTA_PARKING_NODE_ID << "\tWaste Management Station Node ID:" << BOAVISTA_WASTE_STATION_NODE_ID << ")" << endl;
    cout << "4 - MyMap (Parking Lot Node ID: " << MYMAP_PARKING_NODE_ID << "\tWaste Management Station Node ID:" << MYMAP_WASTE_STATION_NODE_ID << ")" << endl;
    cout << "0 - Exit" << endl;
}

void getUserMapOptions(unsigned int &startingPoint, unsigned int &finalPoint, string &nodeMap, string &edgeMap, string &tagsMap) {

    int menuOption;

    nodeMap = PORTO_NODE_MAP;
    edgeMap = PORTO_EDGE_MAP;
    tagsMap = PORTO_TAGS_MAP;

    do {
        showStartingPointMenu();
        cin >> menuOption;

        switch(menuOption) {
            case 0: // Exit
                startingPoint = 0;
                finalPoint = 0;
                return;
            case 1: // Matosinhos
                startingPoint = MATOSINHOS_PARKING_NODE_ID;
                finalPoint = MATOSINHOS_WASTE_STATION_NODE_ID;
                return;
            case 2: // Paranhos
                startingPoint = PARANHOS_PARKING_NODE_ID;
                finalPoint = PARANHOS_WASTE_STATION_NODE_ID;
                return;
            case 3: // Boavista
                startingPoint = BOAVISTA_PARKING_NODE_ID;
                finalPoint = BOAVISTA_WASTE_STATION_NODE_ID;
                return;
            case 4: // MyMap
                startingPoint = MYMAP_PARKING_NODE_ID;
                finalPoint = MYMAP_WASTE_STATION_NODE_ID;
                nodeMap = MYMAP_NODE_MAP;
                edgeMap = MYMAP_EDGE_MAP;
                tagsMap = MYMAP_TAGS_MAP;
                return;
            default:
                cout << "Invalid input" << endl;
                break;
        }

    } while(1);
}

void showTruckMenu() {
    cout << "Please choose an option:" << endl;
    cout << "1 - Unlimited capacity truck" << endl;
    cout << "2 - Unlimited capacity recycling and waste trucks" << endl;
    cout << "3 - Limited capacity recycling and waste trucks (1000 kg Max Capacity)" << endl;
    cout << "0 - Exit" << endl;
}

void getUserTruckOptions(vector<Truck> &trucks, vector<Container> &wasteContainers, vector<Container> &recyclingContainers) {

    int menuOption;

    do {
        showTruckMenu();
        cin >> menuOption;

        switch(menuOption) {
            case 0: { // Unlimited capacity truck
                return;
            }
            case 1: { // Unlimited capacity recycling and waste trucks
                Truck truck = Truck();
                truck.setMaxCapacity(UINT_MAX);
                append_containers(wasteContainers, recyclingContainers);
                truck.setContainers(wasteContainers);
                trucks.push_back(truck);
                return;
            }
            case 2: { // Limited capacity recycling and waste trucks
                Truck wasteTruck = Truck(WASTE);
                wasteTruck.setMaxCapacity(UINT_MAX);
                wasteTruck.setContainers(wasteContainers);
                trucks.push_back(wasteTruck);
                Truck recyclingTruck = Truck(RECYCLE);
                recyclingTruck.setMaxCapacity(UINT_MAX);
                recyclingTruck.setContainers(recyclingContainers);
                trucks.push_back(recyclingTruck);
                return;
            }
            case 3: {
                allocateTruckContainers(trucks, wasteContainers, recyclingContainers);
                return;
            }
            default:
                cout << "Invalid input" << endl;
                break;
        }

    } while(1);
}

void allocateTruckContainers(vector<Truck> &trucks, vector<Container> &wasteContainers, vector<Container> &recyclingContainers) {

    while (!wasteContainers.empty()) {
        Truck *truck = new Truck(WASTE);

        vector<Container>::iterator it;
        for (it = wasteContainers.begin(); it != wasteContainers.end(); it++) {
            if (truck->canAdd(*it)) {
                truck->addContainer(*it);
                wasteContainers.erase(it);
                it--;
            }
        }
        trucks.push_back(*truck);
    }

    while (!recyclingContainers.empty()) {
        Truck *truck = new Truck(RECYCLE);

        vector<Container>::iterator it;
        for (it = recyclingContainers.begin(); it != recyclingContainers.end(); it++) {
            if (truck->canAdd(*it)) {
                truck->addContainer(*it);
                recyclingContainers.erase(it);
                it--;
            }
        }
        trucks.push_back(*truck);
    }
}

