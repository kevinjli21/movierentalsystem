#include "transaction.h"
/**
 * Constructor
 * @param media media type
 * @param movie movie to be borrowed or returned
 */
Transaction::Transaction(string media, Movie* movie) {
    this->media = media;
    this->movie = movie;
}

// Destructor
Transaction::~Transaction() {
    delete movie;
}

/**
 * Get movie involved in transaction
 * @return movie item
 */
Movie* Transaction::getMovie() const {
    return movie;
}

/**
 * Get media type of transaction (DVD only)
 * @return media type
 */
string Transaction::getMedia() const {
    return media;
}