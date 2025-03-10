#ifndef MOVIETABLE_H
#define MOVIETABLE_H

#include "movie.h"
#include <string>
#include <vector>

class MovieTable {
    
    public:
        MovieTable();
        ~MovieTable();
        void put(Movie* movie);
        Movie* get(const string& genre, const string& data);
    
    
    private: 
        std::vector<Movie*> table;

        size_t hash1(const string& key);
        size_t hash2(const string& key);

};

#endif // MOVIETABLE_H