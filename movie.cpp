#include "movie.h"

Movie::Movie(){
    stock = 0;
    year = 0;
    title = "";
    director = "";
}

Movie::Movie(int stock, string director, string title, int year){
    this->stock = stock;
    this->title = title;
    this->director = director;
    this->year = year;
}

Movie::~Movie(){

}

void Movie::changeStock(int input){
    stock += input;
}

ostream& operator<<(ostream& os, const Movie& movie){
    movie.print(os);
    return os;
}
