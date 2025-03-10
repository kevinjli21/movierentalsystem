#ifndef COMEDY_H_
#define COMEDY_H_
#include "movie.h"

using namespace std;
class Comedy : public Movie{
    public:
    Comedy(int stock, string director, string title, int year);
    void print(ostream& os)const override;
    bool operator<(const Comedy& other)const;
    bool operator>(const Comedy& other)const;
};
#endif