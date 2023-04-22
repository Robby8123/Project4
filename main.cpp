#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include "BookRecommender.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <data file 1> [<data file 2> ...]\n";
        return 1;
    }
    
    std::vector<BookRecommender> recommenders;
    
    // Read in the files and create a BookRecommender object for each file
    for (int i = 1; i < argc; i++) {
        BookRecommender recommender(argv[i]);
        recommenders.push_back(recommender);
    }
    
    // Calculate the average rating for each book across all files
    std::map<std::string, std::vector<double>> allRatings;
    for (auto recommender : recommenders) {
        for (auto book : recommender.books) {
            if (allRatings.count(book) == 0) {
                allRatings[book] = std::vector<double>(recommenders.size(), 0.0);
            }
            int index = std::distance(recommenders.begin(), std::find(recommenders.begin(), recommenders.end(), recommender));
            allRatings[book][index] = recommender.getAverage(book);
        }
    }
    std::map<std::string, double> bookAverages;
    for (auto entry : allRatings) {
        double avg = std::accumulate(entry.second.begin(), entry.second.end(), 0.0) / entry.second.size();
        bookAverages[entry.first] = avg;
    }
    
    // Write the average ratings to a file
    std::ofstream outFile("averages.txt");
    if (!outFile.is_open()) {
        std::cout << "Error: unable to open output file.\n";
        return 1;
    }
    for (auto entry : bookAverages) {
        outFile << entry.first << "," << entry.second << "\n";
    }
    outFile.close();
    
    std::cout << "Average Ratings for Books:\n";
    for (auto entry : bookAverages) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }
    
    return 0;
}
