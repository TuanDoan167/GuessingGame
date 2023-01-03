#ifndef COLOUR_HH
#define COLOUR_HH
#include <vector>
#include <iostream>


class Colour
{
public:
    // Location and the input string of 4 colour series as parameters to constructor
    Colour(const std::string& series);
    // Convert the input series into a vector of characters
    std::vector<char> convertSeries();
    // Count number of correct color guessed
    unsigned int totalCorrect(Colour& secretcolor);
    // Count number of correct color guessed but not in correct position
    unsigned int wrongPosition(Colour& secretcolor);
    // Check if the series incude not valid color
    bool includeNotvalidcolor();
    void print();

private:
    // Location in the Allseries vector and a series of 4 colours.
    std::string series_;
};

#endif // COLOUR_HH
