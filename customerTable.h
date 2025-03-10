#ifndef CUSTOMERTABLE_H
#define CUSTOMERTABLE_H

#include "customer.h"
#include <string>
#include <vector>

class CustomerTable {
    
    public:
        CustomerTable();
        CustomerTable();
        void put(Customer* movie);
        Customer* get(const int& customerID);
    
    
    private: 
        std::vector<Customer*> table;

        size_t hash1(const string& key);
        size_t hash2(const string& key);

};

#endif // CUSTOMERTABLE_H