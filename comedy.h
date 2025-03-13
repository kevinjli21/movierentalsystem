#ifndef COMEDY_H_
#define COMEDY_H_
#include "movie.h"

using namespace std;
// derived classs of Movie class
class Comedy : public Movie{
    public:
    // Constructor
    Comedy(int stock, string director, string title, int year);
    // functions
    void print(ostream& os)const override;
    bool operator<(const Comedy& other) const;
    bool operator>(const Comedy& other) const;
};
#endif
