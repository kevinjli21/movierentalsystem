#include "customerTable.h"

using namespace std;

const int TABLE_SIZE = 101;

// Constructor
CustomerTable::CustomerTable() {
    table.resize(TABLE_SIZE);
}

// Destructor
CustomerTable::~CustomerTable() {
    for (list<Customer*> bucket : table) {
        for (Customer* customer : bucket) {
            delete customer;
        }
    }
}

/**
 * Add customer to hash table
 * @param customer customer to add
 */
void CustomerTable::put(Customer* customer) {
    int index = hash(customer->getCustomerID());
    table[index].push_back(customer);
}

/**
 * Get customer from hash table
 * @param customerID customer ID
 * @return customer
 */
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

/**
 * Hash function for customer
 * @param key customer ID
 * @return hash value
 */
size_t CustomerTable::hash(const int& key) {
    return key % TABLE_SIZE;
}