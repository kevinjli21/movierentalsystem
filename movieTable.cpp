#include "movieTable.h"
#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 101;

MovieTable::MovieTable() {
    table.resize(TABLE_SIZE);
}

MovieTable::~MovieTable() {
    for (list<Movie*> bucket : table) {
        for (Movie* movie : bucket) {
            delete movie;
        }
    }
}
