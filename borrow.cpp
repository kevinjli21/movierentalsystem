#include "borrow.h"
#include <iostream>

using namespace std;

Borrow::Borrow(string media, Movie* movie):Transaction(media, movie){
    // CALL CONSTRUCTOR OF TRANSACTION
    this->transactionType = 'B'; // 'B' for borrow
}

Borrow::~Borrow(){
    // destructor
}

void Borrow::print() const {
    cout << "Borrowed " << movie->getTitle() << "  by " << movie->getDirector() << endl; 
}

char Borrow::getTransactionType() const {
    return transactionType;
}