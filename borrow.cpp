#include "borrow.h"
#include <iostream>

using namespace std;

// Constructor
Borrow::Borrow(string media, Movie* movie):Transaction(media, movie){
    // CALL CONSTRUCTOR OF TRANSACTION
    this->transactionType = 'B'; // 'B' for borrow
}

// Destructor
Borrow::~Borrow(){
    // destructor
}

/**
 * Print transaction
 * @return void
 */
void Borrow::print() const {
    cout << "Borrowed " << movie->getTitle() << "  by " << movie->getDirector() << endl; 
}

/**
 * Get transaction type
 * @return transaction type (B)
 */
char Borrow::getTransactionType() const {
    return transactionType;
}