#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "movie.h"
#include "customer.h"

class Transaction {

    public: 
        Transaction(Customer* customer, string media, Movie* movie);
        ~Transaction();
        virtual void print() const;

    private:
        string media;
        Movie* movie;
        Customer* customer;
};

#endif // TRANSACTION_H