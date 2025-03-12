#include "classics.h"


Classics::Classics(int stock, string director, string title, string firstName, string lastName, int month, int year):Movie(stock, director, title, year){
    this->firstName = firstName;
    this->lastName = lastName;
    this->month = month;
}

void Classics::print(ostream& os)const{
    os << "Classics " << title << ", Director: " << director << ", Major Actor: " << firstName << " " << lastName << ", Release: " << month << " " << year << ", Stock: " << stock;
}

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

bool Classics::operator>(const Classics& other)const{
    return !(*this < other);
}

string Classics::getFirstName() const{
    return firstName;
}

string Classics::getLastName() const{
    return lastName;
}

int Classics::getMonth() const{
    return month;
}

int Classics::getYear() const{
    return year;
}