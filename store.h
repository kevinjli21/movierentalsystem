#ifndef STORE_H
#define STORE_H

using namespace std;

#include <string>
#include <iostream>
#include "customerTable.h"

class Store {
    public:
        Store();
        ~Store();
        void viewInventory();
        void customerHistory(int customer);
        void readInventory(string filename);
        void readCustomers(string filename);
        void readCommands(string filename);

    private:
        CustomerTable* customerTable;
};

#endif // STORE_H