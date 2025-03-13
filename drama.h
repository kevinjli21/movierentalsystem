#ifndef DRAMA_H_
#define DRAMA_H_
#include "movie.h"
using namespace std;
// derived class of Movie class
class Drama : public Movie{
    public:
    // constructor
    Drama(int stock, string director, string title, int year);
    // functions
    void print(ostream& os)const override;
    bool operator<(const Drama& other)const;
    bool operator>(const Drama& other)const;
    string getDirector() const;
};
#endif
