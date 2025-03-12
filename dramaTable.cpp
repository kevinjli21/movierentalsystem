#include "dramaTable.h"
#include "drama.h"
#include <iostream>
#include <algorithm>

const int TABLE_SIZE = 101;

DramaTable::DramaTable() {
    table.resize(TABLE_SIZE);
}

DramaTable::~DramaTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (Drama* movie : table[i]) {
            delete movie;
        }
    }
}


Drama* DramaTable::get(const string& title, const string& director) {
    int index = hash(title, director);
    for (Drama* movie : table[index]) {
        if (movie->getTitle() == title && movie->getDirector() == director) {
            return movie;
        }
    }
    cout << "Movie not found" << endl;
    return nullptr;
}

void DramaTable::put(Drama* movie) {
    int index = hash(movie->getTitle(), movie->getDirector());
    table[index].push_back(movie);
}

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



