#include "comedyTable.h"
#include "comedy.h"
#include <iostream>
#include <algorithm>

const int TABLE_SIZE = 101;

ComedyTable::ComedyTable() {
    table.resize(TABLE_SIZE);
}

ComedyTable::~ComedyTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (Comedy* movie : table[i]) {
            delete movie;
        }
    }
}

Comedy* ComedyTable::get(const string& title, const int& year) {
    int index = hash(title, year);
    for (Comedy* movie : table[index]) {
        if (movie->getTitle() == title && movie->getYear() == year) {
            return movie;
        }
    }
    cout << "Movie not found" << endl;
    return nullptr;
}

void ComedyTable::put(Comedy* movie) {
    int index = hash(movie->getTitle(), movie->getYear());
    table[index].push_back(movie);
}

size_t ComedyTable::hash(const string& title, const int& year) {
    int hashVal = 0;
    for (char ch : title) {
        hashVal += ch;
    }
    hashVal += year;
    return hashVal % TABLE_SIZE;
}

void ComedyTable::printAll() {
    vector<Comedy*> toSort;
    for (list<Comedy*> bucket : table) {
        for (Comedy* movie : bucket) {
            toSort.push_back(movie);
        }
    }
    cout << "Movies before sorting:" << endl;
    for (Comedy* movie : toSort) {
        cout << "Title: " << movie->getTitle() << ", Year: " << movie->getYear() << endl;
    }

    // Sort the movies
    sort(toSort.begin(), toSort.end());

    // Print the sorted movies
    cout << "Movies after sorting:" << endl;
    for (Comedy* movie : toSort) {
        cout << *movie << endl;
    }
    sort(toSort.begin(), toSort.end());
    for (Comedy* movie : toSort) {
        cout << *movie << endl;
    }
}



