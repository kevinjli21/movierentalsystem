#include "transaction.h"

Transaction::Transaction(string media, Movie* movie) {
    this->media = media;
    this->movie = movie;
}

Transaction::~Transaction() {
    delete movie;
}

Movie* Transaction::getMovie() const {
    return movie;
}

string Transaction::getMedia() const {
    return media;
}