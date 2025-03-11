#include "comedyTable.h"
#include "comedy.h"

ComedyTable::ComedyTable() : MovieTable() {

}

void ComedyTable::put(Movie* movie) {
    int index = 0;
    table[index].push_back(movie);
}