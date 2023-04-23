#include "BookRecommender.h"
#include <fstream>
#include <sstream>
#include <iostream>

BookRecommender::BookRecommender(const std::string& filename) {
    if (!readFile(filename)) {
        std::cout << "Error reading file " << filename << std::endl;
    }
}

double BookRecommender::getAverageRating(const std::string& book_name) const {
    auto it = this->book_ratings.find(book_name);
    if (it == this->book_ratings.end()) {
        return -1.0;
    }
    const std::vector<double>& ratings = it->second;
    double total = 0;
    for (double rating : ratings) {
        total += rating;
    }
    return total / ratings.size();
}

void BookRecommender::printRatings() const {
    for (auto it = this->book_ratings.begin(); it != this->book_ratings.end(); ++it) {
        std::cout << it->first << ": ";
        const std::vector<double>& ratings = it->second;
        for (double rating : ratings) {
            std::cout << rating << " ";
        }
        std::cout << std::endl;
    }
}

bool BookRecommender::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file " << filename << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string user, book;
        double rating;
        if (ss >> user >> book >> rating) {
            this->book_ratings[book].push_back(rating);
        }
    }
    file.close();
    return true;
}
