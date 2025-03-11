#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

class Customer {
    private:
        vector<Transaction*> transactionHistory;
        int customerID;
        string firstName;
        string lastName;

    public:
        Customer(int customerID, string firstName, string lastName);
        ~Customer();
        void showTransactions();
        int getCustomerID();
        string getName();
        void addTransaction(Transaction* transaction);
        vector<Transaction*> getTransactionHistory() const;
};
#endif // CUSTOMER_H