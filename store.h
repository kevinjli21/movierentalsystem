#ifndef STORE_H
#define STORE_H

using namespace std;

#include <string>
#include <iostream>
#include "customerTable.h"
#include "comedyTable.h"
#include "dramaTable.h"
#include "classicsTable.h"

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
        ComedyTable* comedyTable;
        DramaTable* dramaTable;
        ClassicsTable* classicsTable;
};

#endif // STORE_H