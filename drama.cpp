#include "drama.h"


Drama::Drama(int stock, string director, string title, int year):Movie(stock, director, title, year){
    
}

void Drama::print(ostream& os)const{
    os << "Drama, " << title << ", Director: " << director << ", Release: " << year << ", Stock: " << stock;
}

bool Drama::operator<(const Drama& other)const{
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

bool Drama::operator>(const Drama& other)const{
    return !(*this < other);
}

string Drama::getDirector() const{
    return director;
}