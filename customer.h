#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "transaction.h"
#include <string>
#include <vector>


using namespace std;

class Customer {
    public:
        Customer(int customerID, string firstName, string lastName);
        ~Customer();
        void showTransactions();
        int getCustomerID();
        string getName();
        void addTransaction(Transaction* transaction);
        vector<Transaction*> getTransactionHistory() const;

    private:
        vector<Transaction*> transactionHistory;
        int customerID;
        string firstName;
        string lastName;

};
#endif // CUSTOMER_H