#include <vector>
#include <list>

class ClassicsTable {
    public:
        ClassicsTable();
        ~ClassicsTable();
        Classics* get(const string& firstName, const string& lastName, const int& year, const int& month);
        void* put(Classics* movie);
        void printAll();

    protected:
        size_t hash(const string& firstName, const string& lastName, const int& year, const int& month);

    private:
        std::vector<list<Classics*>> table;
};