#ifndef MOVIETABLE_H
#define MOVIETABLE_H

#include "movie.h"
#include <vector>
#include <list>

class MovieTable {
    public:
        MovieTable();
        virtual ~MovieTable();
        virtual void put() = 0;
        virtual Movie* get() = 0;
        virtual void printAll() = 0;

    protected:
        virtual size_t hash() = 0;
        std::vector<list<Movie*>> table;
        
};

#endif // MOVIETABLE_H