
#include "BookRecommender.h"
#include <iostream>

int main() {
    BookRecommender recommender("small_ratings.dat");
    std::string book;
    std::cout << "Enter book name: ";
    std::getline(std::cin, book);
    while (book != "quit") {
        double average = recommender.getAverageRating(book);
        if (average == -1.0) {
            std::cout << "Book not found" << std::endl;
        } else {
            std::cout << "Average rating for " << book << ": " << average << std::endl;
        }
        std::cout << "Enter book name: ";
        std::getline(std::cin, book);
    }
    return 0;
}
