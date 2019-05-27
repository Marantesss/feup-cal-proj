#include "UserInterface.h"

using namespace std;

void showTruckMenu() {
    cout << "Please choose an option:" << endl;
    cout << "1 - Unlimited capacity trucks" << endl;
    cout << "2 - Unlimited capacity recycling trucks" << endl;
    cout << "3 - Limited capacity recycling trucks" << endl;
    cout << "0 - Exit" << endl;
}

void showStartingPointMenu() {
    cout << "Please choose the truck parking lot location:" << endl;
    cout << "1 - Matosinhos (Parking Lot Node ID: 311887304\tWaste Management Station Node ID)" << endl;
    cout << "2 - Paranhos (Node ID: 432578849)" << endl;
    cout << "2 - Boavista (Node ID: 112675716)" << endl;
    cout << "0 - Exit" << endl;
}

