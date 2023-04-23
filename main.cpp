#include "BookRecommender.h"
#include <iostream>
#include <iomanip>

int main() {
    BookRecommender recommender("ratings.txt");
    std::string book;
    while (true) {
        std::cout << "Enter book name: ";
        std::cin >> book;
        if (book == "quit") {
           
