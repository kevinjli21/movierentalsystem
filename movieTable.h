#ifndef MOVIETABLE_H
#define MOVIETABLE_H

#include "movie.h"
#include <string>
#include <vector>
#include <list>

class MovieTable {
    public:
        MovieTable();
        virtual ~MovieTable();
        virtual void put(Movie* movie) = 0;

    protected:
        size_t hash(const string& key);
        
    private: 
        std::vector<list<Movie*>> table;
};

#endif // MOVIETABLE_H