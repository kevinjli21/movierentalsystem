#include <vector>
#include <list>

class ClassicsTable {
    public:
        ClassicsTable();
        ~ClassicsTable();
        Classics* get(const string& firstName, const string& lastName, const int& year, const int& month);
        void* put(Classics* movie);

    protected:
        size_t hash(const string& firstName, const string& lastName, const int& year, const int& month);
        void printAll();

    private:
        std::vector<list<Classics*>> table;
};