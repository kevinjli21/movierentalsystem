#include "drama.h"

// constructor
Drama::Drama(int stock, string director, string title, int year):Movie(stock, director, title, year){
    
}
// display information of the movie
void Drama::print(ostream& os)const{
    os << "Drama, " << title << ", Director: " << director << ", Release: " << year << ", Stock: " << stock;
}
/** This method compares two drama movie to sort them 
  * in order to store them in a hashtable. The method 
  * will compare the release year, and if they have same 
  * release year , then compare their directure
*/
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
// same as operator>
bool Drama::operator>(const Drama& other)const{
    return !(*this < other);
}
// return director of the movie
string Drama::getDirector() const{
    return director;
}
