#include "comedyTable.h"
#include "comedy.h"
#include <iostream>
#include <algorithm>

// Constructor
ComedyTable::ComedyTable() {
    for (int i = 0; i < 101; ++i) {
        table[i] = nullptr;
    }
}

// Destructor
ComedyTable::~ComedyTable() {
    for (Comedy* comedy : table) {
        delete comedy;
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
    int indexTemp = index;
    while (table[index] != nullptr) {
        if (table[index]->getTitle() == title &&
            table[index]->getYear() == year) {
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
 * Add Comedy movie to inventory
 * @param movie movie to add
 */
void ComedyTable::put(Comedy* movie) {
    int index = hash(movie->getTitle(), movie->getYear());
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
    return hashVal % 101;
}

/**
 * Print all Comedy movies in inventory
 */
void ComedyTable::printAll() {
    vector<Comedy> toSort;
    for (Comedy* movie : table) {
        if (movie != nullptr) {
            toSort.push_back(*movie);
        }
    }
    sort(toSort.begin(), toSort.end());
    // Print the sorted movies
    for (Comedy& movie : toSort) {
        cout << movie << endl;
    }
}



