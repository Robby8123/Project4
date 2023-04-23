#include "BookRecommender.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

BookRecommender::BookRecommender(const std::string& filename) {
    if (!readFile(filename)) {
        std::cerr << "Error reading file " << filename << std::endl;
    }
}

double BookRecommender::getAverageRating(const std::string& book_name) const {
    auto it = book_ratings.find(book_name);
    if (it == book_ratings.end()) {
        return -1.0;
    }
    const std::vector<double>& ratings = it->second;
    double sum = 0.0;
    for (double rating : ratings) {
        sum += rating;
    }
    return sum / ratings.size();
}

void BookRecommender::printRatings() const {
    for (auto it = book_ratings.begin(); it != book_ratings.end(); ++it) {
        const std::string& book_name = it->first;
        const std::vector<double>& ratings = it->second;
        std::cout << book_name << ": ";
        for (double rating : ratings) {
            std::cout << rating << " ";
        }
        std::cout << std::endl;
    }
}

bool BookRecommender::readFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening file " << filename << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string book_name;
        if (!(iss >> book_name)) {
            continue;
        }
        double rating;
        std::vector<double> ratings;
        while (iss >> rating) {
            ratings.push_back(rating);
        }
        book_ratings[book_name] = ratings;
    }
    return true;
}
