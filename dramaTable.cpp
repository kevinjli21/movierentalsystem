#include "dramaTable.h"
#include "drama.h"
#include <iostream>
#include <algorithm>

const int TABLE_SIZE = 101;

DramaTable::DramaTable() : MovieTable() {

}

Movie* DramaTable::get() {
    // empty override - will never use these parameters
}

Movie* DramaTable::get(const string& title, const int& year) {
    int index = hash(title, year);
    for (Movie* movie : table[index]) {
        if (movie->getTitle() == title && movie->getYear() == year) {
            return movie;
        }
    }
    cout << "Movie not found" << endl;
    return nullptr;
}

void DramaTable::put() {
    // empty override - will never use these parameters
}

void* DramaTable::put(Movie* movie) {
    int index = hash(movie->getTitle(), movie->getYear());
    table[index].push_back(movie);
}

size_t hash() {
    // empty override - will never use these parameters
}

size_t hash(const string& title, const int& year) {
    int hashVal = 0;
    for (char ch : title) {
        hashVal += ch;
    }
    hashVal += year;
    return hashVal % TABLE_SIZE;
}

void DramaTable::printAll() {
    vector<Movie*> toSort;
    for (list<Movie*> bucket : table) {
        for (Movie* movie : bucket) {
            cout << *movie << endl;
        }
    }
    sort(toSort.begin(), toSort.end());
    for (Movie* movie : toSort) {
        cout << *movie << endl;
    }
}



