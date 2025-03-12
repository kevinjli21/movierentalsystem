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

void Customer::addToBorrowed(Movie* movie) {
    borrowedMovies.push_back(movie);
}

void Customer::removeFromBorrowed(Movie* toRemove) {
    for (auto movie = borrowedMovies.end() - 1; movie != borrowedMovies.end(); ++movie) {
        if (toRemove == *movie) {
            borrowedMovies.erase(movie);
            return;
        }
    }
}

bool Customer::isBorrowed(Movie* movie) const {
    for (Movie* borrowedMovie : borrowedMovies) {
        if (borrowedMovie->getTitle() == movie->getTitle() && borrowedMovie->getDirector() == movie->getDirector() && movie->getYear() == borrowedMovie->getYear()) {
            return true;
        }
    }
    return false;
}
    

vector<Transaction*> Customer::getTransactionHistory() const {
    return transactionHistory;
}