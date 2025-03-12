#include "comedyTable.h"
#include "comedy.h"
#include <iostream>
#include <algorithm>

const int TABLE_SIZE = 101;

// Constructor
ComedyTable::ComedyTable() {
    table.resize(TABLE_SIZE);
}

// Destructor
ComedyTable::~ComedyTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (Comedy* movie : table[i]) {
            delete movie;
        }
    }
}

/**
 * Get Comedy movie from inventory
 * @param title title of movie
 * @param year year of movie
 * @return Comedy movie
 */
Comedy* ComedyTable::get(const string& title, const int& year) {
    int index = hash(title, year);
    for (Comedy* movie : table[index]) {
        if (movie->getTitle() == title && movie->getYear() == year) {
            return movie;
        }
    }
    return nullptr;
}

/**
 * Add Comedy movie to inventory
 * @param movie movie to add
 */
void ComedyTable::put(Comedy* movie) {
    int index = hash(movie->getTitle(), movie->getYear());
    table[index].push_back(movie);
}

/**
 * Hash function for Comedy movie
 * @param title title of movie
 * @param year year of movie
 * @return hash value
 */
size_t ComedyTable::hash(const string& title, const int& year) {
    int hashVal = 0;
    for (char ch : title) {
        hashVal += ch;
    }
    hashVal += year;
    return hashVal % TABLE_SIZE;
}

/**
 * Print all Comedy movies in inventory
 */
void ComedyTable::printAll() {
    vector<Comedy> toSort;
    for (list<Comedy*> bucket : table) {
        for (Comedy* movie : bucket) {
            toSort.push_back(*movie);
        }
    }
    sort(toSort.begin(), toSort.end());
    // Print the sorted movies
    for (Comedy& movie : toSort) {
        cout << movie << endl;
    }
}



