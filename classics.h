#ifndef CLASSICS_H_
#define CLASSICS_H_
#include "movie.h"
using namespace std;
// derived class of class Movie
class Classics : public Movie{
    public:
    // constructor
    Classics(int stock, string director, string title, string firstName, string lastName, int month, int year);
    // functions
    void print(ostream& os)const override;
    bool operator<(const Classics& other)const;
    bool operator>(const Classics& other)const;
    string getFirstName() const;
    string getLastName() const;
    int getMonth() const;
    int getYear() const; 

    private:
    string firstName; // firstname of major actor
    string lastName;  // lastname of major actor
    int month;  // release month
};
#endif // CLASSICS_H_
