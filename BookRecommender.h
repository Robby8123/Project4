/* Charles Young
    4/16/2023
    2 hours
    Project 4
 */
#ifndef BOOK_RECOMMENDER_H
#define BOOK_RECOMMENDER_H

#include <string>
#include <vector>
#include <unordered_map>

class BookRecommender {
public:
    BookRecommender(const std::string& filename);
    double getAverageRating(const std::string& book_name) const;
    void printRatings() const;

private:
    std::unordered_map<std::string, std::vector<double>> book_ratings;
    bool readFile(const std::string& filename);
};

#endif // BOOK_RECOMMENDER_H
