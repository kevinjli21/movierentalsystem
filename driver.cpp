#include <iostream>
#include <fstream>
#include "store.h"

int main() {
    ifstream infile("data4movies.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    Store store;
    store.readInventory(infile);
    ifstream infile("data4customers.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    store.readCustomers(infile);
    ifstream infile("data4commands.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    store.readCommands(infile);
}