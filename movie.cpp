#include "movie.h"
// default constructor
Movie::Movie(){
    stock = 0;
    year = 0;
    title = "";
    director = "";
}
// constructor
Movie::Movie(int stock, string director, string title, int year){
    this->stock = stock;
    this->title = title;
    this->director = director;
    this->year = year;
}
// destructor
Movie::~Movie(){

}
// This method takes an integer as parameter and modifiy the value of stock
void Movie::changeStock(int input){
    stock += input;
}
// calls print() function to display the information of the movie
ostream& operator<<(ostream& os, const Movie& movie){
    movie.print(os);
    return os;
}
// return year
int Movie::getYear() const{
    return year;
}
// return title
string Movie::getTitle() const{
    return title;
}
// return director
string Movie::getDirector() const{
    return director;
}
// return stock
int Movie::getStock() const{
    return stock;
}
