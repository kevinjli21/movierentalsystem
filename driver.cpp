#include "store.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream infile("data4movies.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    Store newStore;
    cout << "Reading movies from a file..." << endl;
    newStore.readInventory(infile);
    cout << endl;
    cout << "Printing Inventory before commands" << endl;
    newStore.viewInventory();
    ifstream infile1("data4customers.txt");
    if (!infile1) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    cout << "Reading customers from a file..." << endl;
    newStore.readCustomers(infile1);
    ifstream infile2("data4commands.txt");
    if (!infile2) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    cout << endl;
    cout << "Reading commands from a file..." << endl;
    newStore.readCommands(infile2);

    cout << endl;

    cout << "Printing Inventory after commands" << endl;
    newStore.viewInventory();
    cout << "wat" << endl;
    
    return 0;
}