#include "UserInterface.h"
#include "Utils/defs.h"

using namespace std;

void showTruckMenu() {
    cout << "Please choose an option:" << endl;
    cout << "1 - Unlimited capacity trucks" << endl;
    cout << "2 - Unlimited capacity recycling trucks" << endl;
    cout << "3 - Limited capacity recycling trucks" << endl;
    cout << "0 - Exit" << endl;
}

int getTruckMenuOption() {

    int menuOption;

    do {
        showTruckMenu();
        cin >> menuOption;

        switch(menuOption) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            default:
                cout << "Invalid input" << endl;
                break;
        }

    } while(1);
}

void showStartingPointMenu() {
    cout << "Please choose the truck parking lot location:" << endl;
    cout << "1 - Matosinhos (Parking Lot Node ID: " << MATOSINHOS_PARKING_NODE_ID << "\tWaste Management Station Node ID:" << MATOSINHOS_WASTE_STATION_NODE_ID << ")" << endl;
    cout << "2 - Paranhos (Parking Lot Node ID: " << PARANHOS_PARKING_NODE_ID << "\tWaste Management Station Node ID:" << PARANHOS_WASTE_STATION_NODE_ID << ")" << endl;
    cout << "3 - Boavista (Parking Lot Node ID: " << BOAVISTA_PARKING_NODE_ID << "\tWaste Management Station Node ID:" << BOAVISTA_WASTE_STATION_NODE_ID << ")" << endl;
    cout << "0 - Exit" << endl;
}

int getStartingPointMenuOption() {

    int menuOption;

    do {
        showStartingPointMenu();
        cin >> menuOption;

        switch(menuOption) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            default:
                cout << "Invalid input" << endl;
                break;
        }

    } while(1);
}

