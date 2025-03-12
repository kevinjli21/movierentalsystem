#include "customer.h"

using namespace std;

// Constructor
Customer::Customer(int customerID, string firstName, string lastName) {
    this->customerID = customerID;
    this->firstName = firstName;
    this->lastName = lastName;
}

// Destructor
Customer::~Customer() {
    for (Transaction* transaction : transactionHistory) {
        delete transaction;
    }
}

// Print customer transaction history
void Customer::showTransactions() {
    for (Transaction* transaction : transactionHistory) {
        transaction->print();
    }
}

/**
 * Get customer ID
 * @return customer ID
 */
int Customer::getCustomerID() {
    return customerID;
}

/**
 * Get customer name
 * @return customer name
 */
string Customer::getName() {
    return firstName + " " + lastName;
}

/**
 * Add transaction to customer history
 * @param transaction transaction to add
 */
void Customer::addTransaction(Transaction* transaction) {
    transactionHistory.push_back(transaction);
}

/**
 * Add movie to borrowed movies
 * @param movie movie to add
 */
void Customer::addToBorrowed(Movie* movie) {
    borrowedMovies.push_back(movie);
}

/**
 * Remove movie from borrowed movies
 * @param movie movie to remove (return)
 */
void Customer::removeFromBorrowed(Movie* toRemove) {
    for (auto movie = borrowedMovies.end() - 1; movie != borrowedMovies.end(); ++movie) {
        if (toRemove == *movie) {
            borrowedMovies.erase(movie);
            return;
        }
    }
}

/**
 * Check if movie is borrowed
 * @param movie movie to check
 * @return true if movie is borrowed, false otherwise
 */
bool Customer::isBorrowed(Movie* movie) const {
    for (Movie* borrowedMovie : borrowedMovies) {
        if (borrowedMovie->getTitle() == movie->getTitle() && borrowedMovie->getDirector() == movie->getDirector() && movie->getYear() == borrowedMovie->getYear()) {
            return true;
        }
    }
    return false;
}
    
/**
 * Get transaction history as vector
 * @return transaction history
 */
vector<Transaction*> Customer::getTransactionHistory() const {
    return transactionHistory;
}