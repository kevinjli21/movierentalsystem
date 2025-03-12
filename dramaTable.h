#include "drama.h"
#include <vector>
#include <list>

class DramaTable {
    public:
        DramaTable();
        ~DramaTable();
        Drama* get(const string& title, const string& director);
        void put(Drama* movie);
        void printAll();

    protected:
        size_t hash(const string& title, const string& director);

    private: 
        std::vector<list<Drama*>> table;
};