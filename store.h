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
        void readInventory(ifstream &infile);
        void readCustomers(ifstream &infile);
        void readCommands(ifstream &infile);

    private:
        CustomerTable* customerTable;
        ComedyTable* comedyTable;
        DramaTable* dramaTable;
        ClassicsTable* classicsTable;
};

#endif // STORE_H