#include "store.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Store::Store() {
    // initialize inventory hash table as empty
    // initialize customer hash table as empty
}

Store::~Store() {
    // delete all customers
    // delete all inventory
}

void Store::readInventory(string filename) {
    ifstream infile1(filename);
    if (!infile1) {
        cout << "File could not be read" << endl;
        return;
    }
    string str;
    while (std::getline(infile1, str)) {
        istringstream is(str);
        string genre;
        std::getline(is, genre, ',');
        if (genre == ("F")) {
            // create new comedy movie object
            string title;
            string director;
            string stockStr;
            std::getline(is, stockStr, ',');
            int stock = stoi(stockStr);
            std::getline(is, title, ',');
            std::getline(is, director, ',');
            string yearStr;
            std::getline(is, yearStr, ',');
            int year = stoi(yearStr);
            // Comedy(stock, title, director, year);
            // Add movie to inventory hash table
            
        } else if (genre == "D") {
            // create new drama movie object
            string title;
            string director;
            string stockStr;
            std::getline(is, stockStr, ',');
            int stock = stoi(stockStr);
            std::getline(is, title, ',');
            std::getline(is, director, ',');
            string yearStr;
            std::getline(is, yearStr, ',');
            int year = stoi(stockStr);
            // Comedy(stock, title, director, year);
            // Add movie to inventory hash table
        } else if (genre == "C") {
            // create new classics movie object
        } else {
            cout << "ERROR: " << genre << " Invalid Genre. Try again.";
        }
    }

}

void Store::readCustomers(string filename) {
    ifstream infile1(filename);
    if (!infile1) {
        cout << "File could not be read" << endl;
        return;
    }
    string str;
    while (std::getline(infile1, str)) {
        istringstream is(str);
        string lastName;
        string firstName;
        string id;
        std::getline(is, id, ' ');
        std::getline(is, lastName, ' ');
        std::getline(is, firstName, ' ');
        int customerID = stoi(id);
        // create new customer object
    }
}

void Store::readCommands(string filename) {
    ifstream infile1(filename);
    if (!infile1) {
        cout << "File could not be read" << endl;
        return;
    }
    string str;
    while (std::getline(infile1, str)) {
        istringstream is(str);
        string type;
        std::getline(is, type, ' ');
        if (type == "B") {
            string IDstr;
            std::getline(is, IDstr, ' ');
            int customerID = stoi(IDstr);
            string media;
            std::getline(is, media, ' ');
            if (media == "D") {
                string genre;
                std::getline(is, genre, ' ');
                if (genre == "F") {
                    // get from comedy inventory
                } else if (genre == "D") {
                    // get from drama inventory
                } else if (genre == "C") {
                    // get from classics inventory
                } else {
                    cout << "ERROR: " << genre << " Invalid Genre. Try again.";
                }
            } else {
                cout << "ERROR: " << media << " Invalid Media Type. Try again.";
            }
        } else if (type == "R") {

        } else  if (type == "H") {
        
        } else if (type == "I") {

        }
            
        // create new customer object
    }
}