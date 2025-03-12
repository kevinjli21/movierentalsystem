#include "customer.h"

using namespace std;

Customer::Customer(int customerID, string firstName, string lastName) {
    this->customerID = customerID;
    this->firstName = firstName;
    this->lastName = lastName;
}

Customer::~Customer() {
    for (Transaction* transaction : transactionHistory) {
        delete transaction;
    }
}

void Customer::showTransactions() {
    for (Transaction* transaction : transactionHistory) {
        transaction->print();
    }
}

int Customer::getCustomerID() {
    return customerID;
}

string Customer::getName() {
    return firstName + " " + lastName;
}

void Customer::addTransaction(Transaction* transaction) {
    transactionHistory.push_back(transaction);
}

vector<Transaction*> Customer::getTransactionHistory() const {
    return transactionHistory;
}