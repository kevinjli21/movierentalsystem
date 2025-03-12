#include "return.h"
#include <iostream>

using namespace std;

/**
 * Constructor
 * @param media media type
 * @param movie movie to be returned
 */
Return::Return(string media, Movie* movie):Transaction(media, movie){
    // CALL CONSTRUCTOR OF TRANSACTION
    this->transactionType = 'R'; // 'R' for return
}

// Destructor
Return::~Return(){
    // destructor
}

/**
 * Print transaction
 * @return void
 */
void Return::print() const {
    cout << "Returned " << movie->getTitle() << "  by " << movie->getDirector() << endl; 
}

/**
 * Get transaction type
 * @return transaction type (R)
 */
char Return::getTransactionType() const {
    return transactionType;
}