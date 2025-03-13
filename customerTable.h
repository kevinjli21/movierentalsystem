#ifndef CUSTOMERTABLE_H
#define CUSTOMERTABLE_H

#include "customer.h"
#include <vector>
#include <list>

class CustomerTable {
    
    public:
        CustomerTable();
        ~CustomerTable();
        void put(Customer* customer);
        Customer* get(const int& customerID);
    
    private: 
        Customer* table[101];
        size_t hash(const int& key);

};

#endif // CUSTOMERTABLE_H