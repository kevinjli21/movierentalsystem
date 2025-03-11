#ifndef CLASSICS_H_
#define CLASSICS_H_
#include "movie.h"
using namespace std;

class Classics : public Movie{
    public:
    Classics(int stock, string director, string title, string firstName, string lastName, int month, int year);
    void print(ostream& os)const override;
    bool operator<(const Classics& other)const;
    bool operator>(const Classics& other)const; 

    private:
    string firstName;
    string lastName;
    int month;
};
#endif // CLASSICS_H_