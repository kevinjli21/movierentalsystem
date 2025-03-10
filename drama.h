#ifndef DRAMA_H_
#define DRAMA_H_
#include "movie.h"
using namespace std;

class Drama : public Movie{
    public:
    Drama(int stock, string director, string title, int year);
    void print(ostream& os)const override;
    bool operator<(const Drama& other)const;
    bool operator>(const Drama& other)const;
};
#endif