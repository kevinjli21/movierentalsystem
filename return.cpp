#include "return.h"
#include <iostream>

using namespace std;

Return::Return(string media, Movie* movie):Transaction(media, movie){
    // CALL CONSTRUCTOR OF TRANSACTION
    this->transactionType = 'R'; // 'R' for return
}

Return::~Return(){
    // destructor
}

void Return::print() const {
    cout << "Returned " << movie->getTitle() << "  by " << movie->getDirector() << endl; 
}

char Return::getTransactionType() const {
    return transactionType;
}