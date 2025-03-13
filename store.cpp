#include "store.h"
#include <fstream>
#include <sstream>
#include "borrow.h"
#include "return.h"
#include <iomanip>

using namespace std;

// Constructor
Store::Store() {
    // initialize classics hash table as empty
    classicsTable = new ClassicsTable();
    // initialize drama hash table as empty
    dramaTable = new DramaTable();
    // initialize comedy hash table as empty
    comedyTable = new ComedyTable();
    // initialize customer hash table as empty
    customerTable = new CustomerTable();
    
}

// Destructor
Store::~Store() {
    // delete all inventory
    delete classicsTable;
    delete dramaTable;
    delete comedyTable;
    // delete all customers
    delete customerTable;

}

/**
 * View inventory
 * @return void
 */
void Store::viewInventory() {
    cout << "Genre";
    cout << setw(10) << "Title";
    cout << setw(20) << "Director";
    cout << setw(15) << "Release";
    cout << setw(10) << "Stock" << endl;
    // print COMEDY movies, by title then year
    comedyTable->printAll();
    // print DRAMA movies, by director then title
    dramaTable->printAll();
    // print CLASSICS movies, by release date then major actor
    classicsTable->printAll();
}


/**
 * Print customer history
 * @param customer customer ID
 * @return void
 */
void Store::customerHistory(int customer) {
    // print customer history using customer->showTransactions()
    Customer* cust = customerTable->get(customer);
    if (cust != nullptr) {
        cout << "History for " << cust->getName() << endl;
        cust->showTransactions();
    } else {
        cout << "Customer not found" << endl;
    }
}

/**
 * Read inventory from file and add to inventory hash table
 * @param infile file to read inventory from
 * @return void
 */
void Store::readInventory(ifstream &infile) {
    string str;
    while (std::getline(infile, str)) {
        istringstream is(str);
        string genre;
        std::getline(is, genre, ',');
        if (genre == ("F")) {
            // create new comedy movie object
            string title;
            string director;
            string stockStr;
            std::getline(is, stockStr, ',');
            int stock = stoi(stockStr);
            std::getline(is, director, ',');
            // remove extra whitespace
            size_t start = director.find_first_not_of(" \t\n\r\f\v");
            size_t end = director.find_last_not_of(" \t\n\r\f\v");
            director = director.substr(start, end - start + 1);
            std::getline(is, title, ',');
            start = title.find_first_not_of(" \t\n\r\f\v");
            end = title.find_last_not_of(" \t\n\r\f\v");
            title = title.substr(start, end - start + 1);
            string yearStr;
            std::getline(is, yearStr);
            int year = stoi(yearStr);
            Comedy* toAdd = new Comedy(stock, director, title, year);
            // Add movie to inventory hash table
            comedyTable->put(toAdd);
            
        } else if (genre == "D") {
            // create new drama movie object
            string title;
            string director;
            string stockStr;
            std::getline(is, stockStr, ',');
            int stock = stoi(stockStr);
            std::getline(is, director, ',');
            size_t start = director.find_first_not_of(" \t\n\r\f\v");
            size_t end = director.find_last_not_of(" \t\n\r\f\v");
            director = director.substr(start, end - start + 1);
            std::getline(is, title, ',');
            start = title.find_first_not_of(" \t\n\r\f\v");
            end = title.find_last_not_of(" \t\n\r\f\v");
            title = title.substr(start, end - start + 1);
            string yearStr;
            std::getline(is, yearStr);
            int year = stoi(stockStr);
            Drama* toAdd = new Drama(stock, director, title, year);
            // Add movie to inventory hash table
            dramaTable->put(toAdd);
        } else if (genre == "C") {
            // create new classics movie object
            string title;
            string director;

            string stockStr;
            std::getline(is, stockStr, ',');
            int stock = stoi(stockStr);
            std::getline(is, director, ',');
            size_t start = director.find_first_not_of(" \t\n\r\f\v");
            size_t end = director.find_last_not_of(" \t\n\r\f\v");
            director = director.substr(start, end - start + 1);
            std::getline(is, title, ',');
            start = title.find_first_not_of(" \t\n\r\f\v");
            end = title.find_last_not_of(" \t\n\r\f\v");
            title = title.substr(start, end - start + 1);
            string actor;
            string firstName;
            string lastName;
            string extraSpace;
            std::getline(is, extraSpace, ' ');
            std::getline(is, firstName, ' ');
            start = firstName.find_first_not_of(" \t\n\r\f\v");
            end = firstName.find_last_not_of(" \t\n\r\f\v");
            firstName = firstName.substr(start, end - start + 1);
            std::getline(is, lastName, ' ');
            start = lastName.find_first_not_of(" \t\n\r\f\v");
            end = lastName.find_last_not_of(" \t\n\r\f\v");
            lastName = lastName.substr(start, end - start + 1);
            string monthStr;
            string yearStr;
            std::getline(is, monthStr, ' ');
            std::getline(is, yearStr);
            int month = stoi(monthStr);
            int year = stoi(yearStr);
            Classics* toAdd = new Classics(stock, director, title, firstName, lastName, month, year);
            // Add movie to inventory hash table
            classicsTable->put(toAdd);
        } else {
            cout << "ERROR: " << genre << " Invalid Genre. Try again." << endl; 
        }
    }

}

/**
 * Read customers from file and add to customer hash table
 * @param infile file to read customers from
 * @return void
 */
void Store::readCustomers(ifstream &infile) {
    string str;
    while (std::getline(infile, str)) {
        istringstream is(str);
        string lastName;
        string firstName;
        string id;
        std::getline(is, id, ' ');
        std::getline(is, lastName, ' ');
        std::getline(is, firstName, ' ');
        int customerID = stoi(id);
        Customer* toAdd = new Customer(customerID, firstName, lastName);
        customerTable->put(toAdd);
    }
}

/**
 * Read commands from file and execute them
 * @param infile file to read commands from
 * @return void
 */
void Store::readCommands(ifstream &infile) {
    string str;
    while (std::getline(infile, str)) {
        istringstream is(str);
        string type;
        std::getline(is, type, ' ');
        if (type == "B") {
            string IDstr;
            std::getline(is, IDstr, ' ');
            int customerID = stoi(IDstr);
            string media;
            std::getline(is, media, ' ');
            if (media == "D") {
                string genre;
                std::getline(is, genre, ' ');
                if (genre == "F") {
                    string title;
                    std::getline(is, title, ',');
                    string yearStr;
                    std::getline(is, yearStr);
                    int year = stoi(yearStr);
                    Movie* movie = comedyTable->get(title, year);
                    if (movie != nullptr) {
                        if (movie->getStock() > 0) {
                            movie->changeStock(-1);
                            Customer* customer = customerTable->get(customerID);
                            if (customer != nullptr) {
                                Transaction* transaction = new Borrow(media, movie);
                                customer->addTransaction(transaction);
                                cout << "Borrowed " << genre << " " << movie->getTitle() 
                                     << "  by " << movie->getDirector() << endl;
                            } else {
                                cout << "ERROR: Customer not found." << endl;
                            }
                        } else {
                            cout << "ERROR: Movie out of stock." << endl;
                        }
                        // add to customer history
                    } else {
                        cout << "ERROR: Movie not found in inventory." << endl;
                    }
                } else if (genre == "D") {
                    // get from drama inventory
                    string director;
                    std::getline(is, director, ',');
                    size_t start = director.find_first_not_of(" \t\n\r\f\v");
                    size_t end = director.find_last_not_of(" \t\n\r\f\v");
                    director = director.substr(start, end - start + 1);
                    string title;
                    std::getline(is, title, ',');
                    start = title.find_first_not_of(" \t\n\r\f\v");
                    end = title.find_last_not_of(" \t\n\r\f\v");
                    title = title.substr(start, end - start + 1);
                    Movie* movie = dramaTable->get(title, director);
                    if (movie != nullptr) {
                        // create new borrow transaction
                        if (movie->getStock() > 0) {
                            movie->changeStock(-1);
                            Customer* customer = customerTable->get(customerID);
                            if (customer != nullptr) {
                                Transaction* transaction = new Borrow(media, movie);
                                customer->addTransaction(transaction);
                                cout << "Borrowed " << genre << " " << movie->getTitle() 
                                     << "  by " << movie->getDirector() << endl;
                            } else {
                                cout << "ERROR: Customer not found." << endl;
                            }
                        } else {
                            cout << "ERROR: Movie out of stock." << endl;
                        }
                        // add to customer history
                    } else {
                        cout << "ERROR: Movie not found in inventory." << endl;
                    }


                } else if (genre == "C") {
                    string monthStr;
                    std::getline(is, monthStr, ' ');
                    int month = stoi(monthStr);
                    string yearStr;
                    std::getline(is, yearStr, ' ');
                    int year = stoi(yearStr);
                    string firstName;
                    std::getline(is, firstName, ' ');
                    // remove extra whitespace
                    size_t start = firstName.find_first_not_of(" \t\n\r\f\v");
                    size_t end = firstName.find_last_not_of(" \t\n\r\f\v");
                    firstName = firstName.substr(start, end - start + 1);
                    string lastName;
                    std::getline(is, lastName);
                    start = lastName.find_first_not_of(" \t\n\r\f\v");
                    end = lastName.find_last_not_of(" \t\n\r\f\v");
                    lastName = lastName.substr(start, end - start + 1);
                    Movie* movie = classicsTable->get(firstName, lastName, year, month);
                    if (movie != nullptr) {
                        if (movie->getStock() > 0) {
                            movie->changeStock(-1);
                            Customer* customer = customerTable->get(customerID);
                            if (customer != nullptr) {
                                Transaction* transaction = new Borrow(media, movie);
                                customer->addTransaction(transaction);
                                customer->addToBorrowed(movie);
                                cout << "Borrowed " << genre << " " << movie->getTitle() 
                                     << "  by " << movie->getDirector() << "(" << firstName 
                                     << " " << lastName << ")" << endl;
                            } else {
                                cout << "ERROR: Customer not found." << endl;
                            }
                        } else {
                            cout << "ERROR: Movie out of stock." << endl;
                        }
                    } else {
                        cout << "ERROR: Movie not found in inventory." << endl;
                    }
                } else {
                    cout << "ERROR: " << genre << " Invalid Genre. Try again." << endl;
                }
            } else {
                cout << "ERROR: " << media << " Invalid Media Type. Try again." << endl;
            }
        } else if (type == "R") {
            string IDstr;
            std::getline(is, IDstr, ' ');
            int customerID = stoi(IDstr);
            string media;
            std::getline(is, media, ' ');
            if (media == "D") {
                string genre;
                std::getline(is, genre, ' ');
                if (genre == "F") {
                    string title;
                    std::getline(is, title, ',');
                    size_t start = title.find_first_not_of(" \t\n\r\f\v");
                    size_t end = title.find_last_not_of(" \t\n\r\f\v");
                    title = title.substr(start, end - start + 1);
                    string yearStr;
                    std::getline(is, yearStr);
                    int year = stoi(yearStr);
                    Movie* movie = comedyTable->get(title, year);
                    if (movie != nullptr) {
                        vector<Transaction*> transactions = customerTable->
                            get(customerID)->getTransactionHistory();
                        for (Transaction* transaction : transactions) {
                            if (transaction->getMedia() == media && transaction->
                                getMovie()->getTitle() == title
                                && transaction->getMovie()->getYear() == year 
                                && transaction->getTransactionType() == 'B') {
                                // create new return transaction
                                movie->changeStock(1);
                                Transaction* returnTransaction = new Return(media, movie);
                                customerTable->get(customerID)->addTransaction(returnTransaction);
                                cout << "Returned " << genre << " " 
                                     << movie->getTitle() << "  by " 
                                     << movie->getDirector() << endl;
                            } else {
                                cout << "ERROR: Customer never borrowed movie." << endl;
                            }
                        }
                        // add to customer history
                    } else {
                        cout << "ERROR: Movie not found in inventory." << endl;
                    }
                } else if (genre == "D") {
                    // get from drama inventory
                    string director;
                    std::getline(is, director, ',');
                    // remove extra whitespace
                    size_t start = director.find_first_not_of(" \t\n\r\f\v");
                    size_t end = director.find_last_not_of(" \t\n\r\f\v");
                    director = director.substr(start, end - start + 1);
                    string title;
                    std::getline(is, title, ',');
                    start = title.find_first_not_of(" \t\n\r\f\v");
                    end = title.find_last_not_of(" \t\n\r\f\v");
                    title = title.substr(start, end - start + 1);
                    Movie* movie = dramaTable->get(title, director);
                    if (movie != nullptr) {
                        vector<Transaction*> transactions = customerTable->
                            get(customerID)->getTransactionHistory();
                        for (Transaction* transaction : transactions) {
                            if (transaction->getMedia() == media && 
                                transaction->getMovie()->getTitle() == title
                                && transaction->getMovie()
                                    ->getDirector() == director 
                                && transaction->getTransactionType() == 'B') {
                                // create new return transaction
                                movie->changeStock(1);
                                Transaction* returnTransaction = new Return(media, movie);
                                customerTable->get(customerID)->
                                addTransaction(returnTransaction);
                                cout << "Returned " << genre << " " << movie->getTitle() 
                                     << "  by " << movie->getDirector() << endl;
                            } else {
                                cout << "ERROR: Customer never borrowed movie." << endl;
                            }
                        }
                        // add to customer history
                    } else {
                        cout << "ERROR: Movie not found in inventory." << endl;
                    }
                } else if (genre == "C") {
                    // get from classics inventory
                    string monthStr;
                    std::getline(is, monthStr, ' ');
                    int month = stoi(monthStr);
                    string yearStr;
                    std::getline(is, yearStr, ' ');
                    int year = stoi(yearStr);
                    string firstName;
                    std::getline(is, firstName, ' ');
                    // remove extra whitespace
                    size_t start = firstName.find_first_not_of(" \t\n\r\f\v");
                    size_t end = firstName.find_last_not_of(" \t\n\r\f\v");
                    firstName = firstName.substr(start, end - start + 1);
                    string lastName;
                    std::getline(is, lastName);
                    start = lastName.find_first_not_of(" \t\n\r\f\v");
                    end = lastName.find_last_not_of(" \t\n\r\f\v");
                    lastName = lastName.substr(start, end - start + 1);

                    Movie* movie = classicsTable->get(firstName, lastName, year, month);
                    if (movie != nullptr) {
                        Customer* customer = customerTable->get(customerID);
                        if (customer->isBorrowed(movie)) {
                            customer->removeFromBorrowed(movie);
                            movie->changeStock(1);
                            Transaction* returnTransaction = new Return(media, movie);
                            customer->addTransaction(returnTransaction);
                            cout << "Returned " << genre << " " 
                                 << movie->getTitle() << "  by " 
                                 << movie->getDirector() << " (" 
                                 << firstName << " " << lastName << ")" << endl;
                        } else {
                            cout << "ERROR: Customer never borrowed movie." 
                                 << endl;
                        }
                    } else {
                        cout << "ERROR: Movie not found in inventory." << endl;
                    }
                } else {
                    cout << "ERROR: " << genre << " Invalid Genre. Try again.";
                }
            }
        } else if (type == "H") {
            string IDstr;
            std::getline(is, IDstr, ' ');
            int customerID = stoi(IDstr);
            customerHistory(customerID);
        } else if (type == "I") {
            viewInventory();
        } else {
            cout << "ERROR: " << type << " Invalid Command. Try again." << endl;
        }
        
    }
}