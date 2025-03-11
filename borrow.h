#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"

class Borrow : public Transaction {
    public:
        Borrow(string media, Movie* movie); // CALL CONSTRUCTOR OF TRANSACTION
        ~Borrow();
        void print() const override;
        char getTransactionType() const;

    private:
        char transactionType; // 'B' for borrow
};

#endif // BORROW_H