#ifndef STORE_H
#define STORE_H

using namespace std;

#include <string>
#include <iostream>

class Store {
    public:
        Store();
        ~Store();
        void addCustomer();
        void addItem(int stock, string title, string director, string date);
        void viewInventory();
        void customerHistory(int customer);
        void readCustomers(string filename);
        void readInventory(string filename);
        void readTransactions(string filename);
};

#endif // STORE_H