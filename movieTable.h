#ifndef MOVIETABLE_H
#define MOVIETABLE_H

#include "movie.h"
#include <vector>
#include <list>

class MovieTable {
    public:
        MovieTable();
        virtual ~MovieTable();
        virtual void put(Movie* movie) = 0;
        virtual Movie* get(const string& key) = 0;
        virtual void printAll() = 0;

    protected:
        virtual size_t hash(const string& key) = 0;
        
    private: 
        std::vector<list<Movie*>> table;
};

#endif // MOVIETABLE_H