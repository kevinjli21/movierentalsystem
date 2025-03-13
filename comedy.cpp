#include "comedy.h"

// constructor
Comedy::Comedy(int stock, string director, string title, int year):Movie(stock, director, title, year){
    
}
// display information of the movie
void Comedy::print(ostream& os) const {
    os << "Comedy, " << title << ", Director: " << director << ", Release: " << year << ", Stock: " << stock;
}
/** Compare the Comedy movie to sort them and to store 
  * them in a hash table. The method will compare their
  * title and if they have same title, then compare the
  * release year
*/
bool Comedy::operator<(const Comedy& other) const{
    if (title == other.title) {
        return year < other.year;
    } else {
        return title < other.title;
    }
}
// same as operator>
bool Comedy::operator>(const Comedy& other) const{
    return !(*this < other);
}
