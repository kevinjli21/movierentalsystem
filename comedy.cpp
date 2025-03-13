#include "comedy.h"
#include <iomanip>

// constructor
Comedy::Comedy(int stock, string director, string title, int year):Movie(stock, director, title, year){
    
}
// display information of the movie
void Comedy::print(ostream& os) const {
    os  << left << setw(10) << "Comedy" 
        << setw(35) << title 
        << setw(25) << director
        << setw(10) << year 
        << stock;
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
