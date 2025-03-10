#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
using namespace std;

class Customer {
    private :
        // vector<Transaction*> transactionHistory;
        int customerID;
        string firstName;
        string lastName;

    public:
        void showTransactions();
};
#endif // CUSTOMER_H