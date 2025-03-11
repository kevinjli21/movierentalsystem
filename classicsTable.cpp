#include "classicsTable.h"
#include "classics.h"
#include <iostream>
#include <algorithm>

const int TABLE_SIZE = 101;

ClassicsTable::ClassicsTable() {
    table.resize(TABLE_SIZE);
}

Classics* ClassicsTable::get(const string& firstName, const string& lastName, const int& year, const int& month) {
    int index = hash(firstName, lastName, year, month);
    for (Classics* movie : table[index]) {
        if (movie->getFirstName() == firstName && movie-> getLastName() == lastName && movie->getYear() == year && movie->getMonth() == month) {
            return movie;
        }
    }
    cout << "Movie not found" << endl;
    return nullptr;
}


void* ClassicsTable::put(Classics* movie) {
    int index = hash(movie->getFirstName(), movie->getLastName(), movie->getYear(), movie->getMonth());
    table[index].push_back(movie);
}


size_t hash(const string& firstName, const string& lastName, const int& year, const int& month) {
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

void ClassicsTable::printAll() {
    vector<Classics*> toSort;
    for (list<Classics*> bucket : table) {
        for (Classics* movie : bucket) {
            cout << *movie << endl;
        }
    }
    sort(toSort.begin(), toSort.end());
    for (Classics* movie : toSort) {
        cout << *movie << endl;
    }
}



