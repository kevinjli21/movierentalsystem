#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "movie.h"
#include "customer.h"

class Transaction {

    public: 
        Transaction(string media, Movie* movie);
        virtual ~Transaction();
        virtual void print() const = 0;
        Movie* getMovie() const;
        string getMedia() const;
        virtual char getTransactionType() const = 0; 

    protected:
        string media;
        Movie* movie;
};

#endif // TRANSACTION_H