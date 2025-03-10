#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"

class Borrow : public Transaction {
    public:
        Borrow(Customer* customer, string media, Movie* movie); // CALL CONSTRUCTOR OF TRANSACTION
        ~Borrow();
        void print() const override;
};

#endif // BORROW_H