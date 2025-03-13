#include "classics.h"
#include <iomanip>

// constructor
Classics::Classics(int stock, string director, string title, string firstName, string lastName, int month, int year):Movie(stock, director, title, year){
    this->firstName = firstName;
    this->lastName = lastName;
    this->month = month;
}
// display information of the movie
void Classics::print(ostream& os)const{
    cout << left << setw(10) << "Classics";
    cout << setw(35) << title;
    cout << setw(25) << director;
    cout << setw(25) << firstName + " " + lastName;
    cout << setw(1) << month << " " << setw(9) << year;
    cout << stock << endl;
}
/** This method compare the data of classics movie to
  * sort them in order to store them in a hashtable
  * The method compares the year of movie, and if they
  * have same release year, then compare the month, 
  * firstname, and lastname.
*/
bool Classics::operator<(const Classics& other)const{
    if (year == other.year) {
        if (month == other.month) {
            if (firstName == other.firstName) {
                return lastName < other.lastName;
            } else {
                return firstName < other.firstName;
            }
        }
        return month < other.month;
    } else {
        return year < other.year;
    }
}
// same as operator>
bool Classics::operator>(const Classics& other)const{
    return !(*this < other);
}
// return firstname of major actor
string Classics::getFirstName() const{
    return firstName;
}
// return lastname of major actor
string Classics::getLastName() const{
    return lastName;
}
// return release month
int Classics::getMonth() const{
    return month;
}
// return release year
int Classics::getYear() const{
    return year;
}
