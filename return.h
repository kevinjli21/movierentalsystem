#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction {
    public:
        Return(Customer* customer, string media, Movie* movie); // CALL CONSTRUCTOR OF TRANSACTION
        ~Return();
        void print() const override;

};

#endif // RETURN_H