#include "BookRecommender.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>

// Constructor that initializes the object with empty books, users, and ratings
BookRecommender::BookRecommender() {}

// Constructor that reads from the specified file to initialize the object
BookRecommender::BookRecommender(std::string fileName) {
    std::ifstream inFile(fileName);
    if (inFile.good()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string title;
            ss >> title;
            books.push_back(title);
            double rating;
            std::vector<double> ratings;
            while (ss >> rating) {
                ratings.push_back(rating);
            }
            if (!ratings.empty()) {
                std::string user = ratedBooks.size() > 0 ? ratedBooks.begin()->first : "";
                ratedBooks[user] = ratings;
            }
        }
        inFile.close();
    }
}

// Prints book recommendations for the specified user
void BookRecommender::printRecommend(std::string userName) {
    // Implementation for recommending books to a user
}

// Prints the average rating for each book
void BookRecommender::printAverages() {
    // Implementation for printing book rating averages
}

// Returns the average rating for the specified book
double BookRecommender::getAverage(std::string bookTitle) {
    // Implementation for getting average rating of a book
    return 0.0;
}

// Returns the similarity between two users based on their book ratings
double BookRecommender::getSimilarity(std::string userName1, std::string userName2) {
    // Implementation for getting similarity between two users
    return 0.0;
}

// Returns the number of books in the BookRecommender object
int BookRecommender::getBookCount() {
    return books.size();
}

// Returns the number of users in the BookRecommender object
int BookRecommender::getUserCount() {
    return ratedBooks.size();
}

// Returns the rating of a specified book by a specified user
double BookRecommender::getUserBookRating(std::string userName, std::string bookTitle) {
    // Implementation for getting user's rating for a book
    return 0.0;
}
