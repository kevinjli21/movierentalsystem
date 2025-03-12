#include "dramaTable.h"
#include "drama.h"
#include <iostream>
#include <algorithm>

const int TABLE_SIZE = 101;

// Constructor
DramaTable::DramaTable() {
    table.resize(TABLE_SIZE);
}

// Destructor
DramaTable::~DramaTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (Drama* movie : table[i]) {
            delete movie;
        }
    }
}

/**
 * Get Drama movie from inventory
 * @param title title of movie
 * @param director director of movie
 * @return Drama movie
 */
Drama* DramaTable::get(const string& title, const string& director) {
    int index = hash(title, director);
    for (Drama* movie : table[index]) {
        if (movie->getTitle() == title && movie->getDirector() == director) {
            return movie;
        }
    }
    return nullptr;
}

/**
 * Add Drama movie to inventory
 * @param movie movie to add
 */
void DramaTable::put(Drama* movie) {
    int index = hash(movie->getTitle(), movie->getDirector());
    table[index].push_back(movie);
}

/**
 * Hash function for Drama movie
 * @param title title of movie
 * @param director director of movie
 * @return hash value
 */
size_t DramaTable::hash(const string& title, const string& director) {
    int hashVal = 0;
    for (char ch : title) {
        hashVal += ch;
    }
    for (char ch : director) {
        hashVal += ch;
    }
    return hashVal % TABLE_SIZE;
}

/**
 * Print all Drama movies in inventory sorted by Year, then director
 */
void DramaTable::printAll() {
    vector<Drama> toSort;
    for (list<Drama*> bucket : table) {
        for (Drama* movie : bucket) {
            toSort.push_back(*movie);
        }
    }
    sort(toSort.begin(), toSort.end());
    for (Drama& movie : toSort) {
        cout << movie << endl;
    }
}



