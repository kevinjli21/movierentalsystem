#include "classicsTable.h"
#include "classics.h"
#include <iostream>
#include <algorithm>

// Constructor
ClassicsTable::ClassicsTable() {
    for (int i = 0; i < 101; ++i) {
        table[i] = nullptr;
    }
}

// Destructor
ClassicsTable::~ClassicsTable() {
    for (int i = 0; i < 101; ++i) {
        delete table[i];
    }
}

/**
 * Get Classics movie from inventory
 * @param firstName first name of major actor
 * @param lastName last name of major actor
 * @param year year of movie
 * @param month month of movie
 * @return Classics movie
 */
Classics* ClassicsTable::get(const string& firstName, const string& lastName, const int& year, const int& month) {
    int index = hash(firstName, lastName, year, month);
    int indexTemp = index;
    while (table[index] != nullptr) {
        if (table[index]->getFirstName() == firstName &&
            table[index]->getLastName() == lastName &&
            table[index]->getYear() == year &&
            table[index]->getMonth() == month) {
            return table[index];
        }
        index = (index + 1) % 101;
        if (index == indexTemp) {
            break;
        }
    }
    return nullptr;
}


/**
 * Add Classics movie to inventory
 * @param movie movie to add
 */
void ClassicsTable::put(Classics* movie) {
    int index = hash(movie->getFirstName(), movie->getLastName(), movie->getYear(), movie->getMonth());
    int indexTemp = index;
    while (table[index] != nullptr) {
        index = (index + 1) % 101;
        if (index == indexTemp) {
            cout << "ERROR: Hash table is full." << endl;
            return;
        }
    }
    table[index] = movie;
}

/**
 * Hash function for Classics movie
 * @param firstName first name of major actor
 * @param lastName last name of major actor
 * @param year year of movie
 * @param month month of movie
 * @return hash value
 */
size_t ClassicsTable::hash(const string& firstName, const string& lastName, const int& year, const int& month) {
    int hashVal = 0;
    for (char ch : firstName) {
        hashVal += ch;
    }
    for (char ch : lastName) {
        hashVal += ch;
    }
    hashVal += year;
    hashVal += month;
    return hashVal % 101;
}

/**
 * Print all Classics movies in inventory
 */
void ClassicsTable::printAll() {
    vector<Classics> toSort;
    for (Classics* movie : table) {
        if (movie != nullptr) {
            toSort.push_back(*movie);
        }
    }
    sort(toSort.begin(), toSort.end());
    for (Classics& movie : toSort) {
        cout << movie << endl;
    }
}



