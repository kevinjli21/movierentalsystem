#include "customerTable.h"

using namespace std;

// Constructor
CustomerTable::CustomerTable() {
    for (int i = 0; i < 101; ++i) {
        table[i] = nullptr;
    }
}

// Destructor
CustomerTable::~CustomerTable() {
    for (Customer* customer : table) {
        delete customer;
    }
}

/**
 * Add customer to hash table
 * @param customer customer to add
 */
void CustomerTable::put(Customer* customer) {
    int index = hash(customer->getCustomerID());
    int indexTemp = index;
    while (table[index] != nullptr) {
        index = (index + 1) % 101;
        if (index == indexTemp) {
            cout << "ERROR: Hash table is full." << endl;
            return;
        }
    }
    table[index] = customer;
}

/**
 * Get customer from hash table
 * @param customerID customer ID
 * @return customer
 */
Customer* CustomerTable::get(const int& customerID) {
    int index = hash(customerID);
    int indexTemp = index;
    while (table[index] != nullptr) {
        if (table[index]->getCustomerID() == customerID) {
            return table[index];
        }
        index = (index + 1) % 101;
        if (index == indexTemp) {
            break;
        }
    }
    return nullptr;
}

/**
 * Hash function for customer
 * @param key customer ID
 * @return hash value
 */
size_t CustomerTable::hash(const int& key) {
    return key % 101;
}