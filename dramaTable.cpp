#include "dramaTable.h"
#include "drama.h"
#include <iostream>
#include <algorithm>

// Constructor
DramaTable::DramaTable() {
    for (int i = 0; i < 101; ++i) {
        table[i] = nullptr;
    }
}

// Destructor
DramaTable::~DramaTable() {
    for (Drama* drama : table) {
        delete drama;
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
    int indexTemp = index;
    while (table[index] != nullptr) {
        if (table[index]->getTitle() == title &&
            table[index]->getDirector() == director) {
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
 * Add Drama movie to inventory
 * @param movie movie to add
 */
void DramaTable::put(Drama* movie) {
    int index = hash(movie->getTitle(), movie->getDirector());
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
    return hashVal % 101;
}

/**
 * Print all Drama movies in inventory sorted by Year, then director
 */
void DramaTable::printAll() {
    vector<Drama> toSort;
    for (Drama* movie : table) {
        if (movie != nullptr) {
            toSort.push_back(*movie);
        }
    }
    sort(toSort.begin(), toSort.end());
    for (Drama& movie : toSort) {
        cout << movie << endl;
    }
}



