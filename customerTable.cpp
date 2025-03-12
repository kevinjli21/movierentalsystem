#include "customerTable.h"

using namespace std;

const int TABLE_SIZE = 101;

CustomerTable::CustomerTable() {
    table.resize(TABLE_SIZE);
}

CustomerTable::~CustomerTable() {
    for (list<Customer*> bucket : table) {
        for (Customer* customer : bucket) {
            delete customer;
        }
    }
}

void CustomerTable::put(Customer* customer) {
    int index = hash(customer->getCustomerID());
    table[index].push_back(customer);
}

Customer* CustomerTable::get(const int& customerID) {
    int index = hash(customerID);
    for (Customer* customer : table[index]) {
        if (customer->getCustomerID() == customerID) {
            return customer;
        }
    }
    cout << "Customer not found" << endl;
    return nullptr;
}

size_t CustomerTable::hash(const int& key) {
    return key % TABLE_SIZE;
}