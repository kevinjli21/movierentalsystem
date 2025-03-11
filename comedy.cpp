#include "comedy.h"


Comedy::Comedy(int stock, string director, string title, int year):Movie(stock, director, title, year){
    
}

void Comedy::print(ostream& os) const {
    os << "Comedy, " << title << ", Director: " << director << ", Release: " << year << ", Stock: " << stock;
}

bool Comedy::operator<(const Comedy& other) const{
    if(year < other.year){
        return true;
    }
    else if(year == other.year){
        if(director < other.director){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Comedy::operator>(const Comedy& other) const{
    return !(*this < other);
}