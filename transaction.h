#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {

    public: 
        Transaction();
        ~Transaction();
        virtual void print() = 0;

    private:
        
};

#endif // TRANSACTION_H