#include "classicsTable.h"
#include "classics.h"
#include <iostream>
#include <algorithm>

const int TABLE_SIZE = 101;

// Constructor
ClassicsTable::ClassicsTable() {
    table.resize(TABLE_SIZE);
}

// Destructor
ClassicsTable::~ClassicsTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (Classics* movie : table[i]) {
            delete movie;
        }
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
    for (Classics* movie : table[index]) {
        if (movie->getFirstName() == firstName && movie-> getLastName() == lastName && movie->getYear() == year && movie->getMonth() == month) {
            return movie;
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
    table[index].push_back(movie);
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
    return hashVal % TABLE_SIZE;
}

/**
 * Print all Classics movies in inventory
 */
void ClassicsTable::printAll() {
    vector<Classics> toSort;
    for (list<Classics*> bucket : table) {
        for (Classics* movie : bucket) {
            toSort.push_back(*movie);
        }
    }
    sort(toSort.begin(), toSort.end());
    for (Classics& movie : toSort) {
        cout << movie << endl;
    }
    cout << "done!" << endl;
}



