#include "comedy.h"
#include <vector>
#include <list>

class ComedyTable {
    public:
        ComedyTable();
        ~ComedyTable();
        Comedy* get(const string& title, const int& year);
        void* put(Comedy* movie);
        void printAll();

    protected:
        size_t hash(const string& title, const int& year);

    private: 
        std::vector<list<Comedy*>> table;
};