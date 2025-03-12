#include "comedy.h"


Comedy::Comedy(int stock, string director, string title, int year):Movie(stock, director, title, year){
    
}

void Comedy::print(ostream& os) const {
    os << "Comedy, " << title << ", Director: " << director << ", Release: " << year << ", Stock: " << stock;
}

bool Comedy::operator<(const Comedy& other) const{
    if (title == other.title) {
        return year < other.year;
    } else {
        return title < other.title;
    }
}

bool Comedy::operator>(const Comedy& other) const{
    return !(*this < other);
}