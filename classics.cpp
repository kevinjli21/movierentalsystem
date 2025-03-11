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
    if(year < other.year){
        return true;
    }
    else if(year == other.year){
        if(month < other.month){
            return true;
        }
        else if(month == other.month){
            if(firstName < other.firstName){
                return true;
            }
            else if(firstName == other.firstName){
                return lastName < other.lastName;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Classics::operator>(const Classics& other)const{
    return !(*this < other);
}