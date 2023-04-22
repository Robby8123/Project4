#ifndef BOOK_RECOMMENDER_H
#define BOOK_RECOMMENDER_H

#include <vector>
#include <string>
#include <map>

class BookRecommender {
public:
    BookRecommender();
    BookRecommender(std::string fileName);
    void printRecommend(std::string userName);
    void printAverages();
    double getAverage(std::string bookTitle);
    double getSimilarity(std::string userName1, std::string userName2);
    int getBookCount();
    int getUserCount();
    double getUserBookRating(std::string userName, std::string bookTitle);

private:
    std::vector<std::string> books;
    std::vector<std::string> users;
    std::map<std::string, std::vector<double>> ratedBooks;
    std::map<std::string, double> averages;
};

#endif /* BOOK_RECOMMENDER_H */
