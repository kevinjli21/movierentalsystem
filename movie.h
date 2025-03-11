#ifndef MOVIE_H_
#define MOVIE_H_
#include<iostream>
#include<string>

using namespace std;

class Movie{
    public:
    Movie();
    Movie(int stock, string director, string title, int year);
    virtual ~Movie();
    void changeStock(int input);
    virtual void print(ostream& os)const = 0;
    friend ostream& operator<<(ostream& os, const Movie& movie);
    int getYear() const;
    string getTitle() const;
    string getDirector() const;
    int getStock() const;

    protected:
    string title;
    string director;
    int stock;
    int year;

};
#endif
