#include <vector>
#include <list>
#include "classics.h"

class ClassicsTable {
    public:
        ClassicsTable();
        ~ClassicsTable();
        Classics* get(const string& firstName, const string& lastName, const int& year, const int& month);
        void put(Classics* movie);
        void printAll();

    protected:
        size_t hash(const string& firstName, const string& lastName, const int& year, const int& month);

    private:
        Classics* table[101];
};