#ifndef CUSTOMERTABLE_H
#define CUSTOMERTABLE_H

#include "customer.h"
#include <string>
#include <vector>
#include <list>

class CustomerTable {
    
    public:
        CustomerTable();
        ~CustomerTable();
        void put(Customer* customer);
        Customer* get(const int& customerID);
    
    private: 
        std::vector<list<Customer*>> table;
        size_t hash(const int& key);

};

#endif // CUSTOMERTABLE_H