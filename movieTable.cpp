#include "movieTable.h"
#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 101;

MovieTable::MovieTable() {
    maxSize = TABLE_SIZE;
    curSize = 0;
}

size_t MovieTable::hash1(const string& key) {
    int hash = 0;
}