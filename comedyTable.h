#include "movieTable.h"

class ComedyTable : public MovieTable {
    public:
        ComedyTable();
        ~ComedyTable() override = default;
        void put(Movie* movie) override;
        Movie* get(const string& key) override;
        void printAll() override;

    protected:
        size_t hash(const string& key) override;
};