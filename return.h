#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"


class Return : public Transaction {
    public:
        Return(string media, Movie* movie); // CALL CONSTRUCTOR OF TRANSACTION
        ~Return();
        void print() const override;
        char getTransactionType() const;

    private:
        char transactionType; // 'R' for return
};

#endif // RETURN_H