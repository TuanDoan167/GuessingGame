#include "colour.hh"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Number of colors in a series
const unsigned int SIZE = 4;
const std::vector<char>& colors = {'B', 'R', 'Y', 'G', 'O','V','b', 'r', 'y', 'g', 'o','v'};

Colour::Colour(const std::string& series):
   series_(series)   { }


// Return a vector of characters from the string series input.
std::vector<char> Colour::convertSeries() {std::vector<char> vectorofcolor;
                                   std::string::size_type i = 0;
                                   while ( i < series_.length()){
                                       char c = series_.at(i);
                                       vectorofcolor.push_back(c);
                                       ++i;
                                   }
                                   return vectorofcolor;
}

// First, the function compares each color from the two series at the same index,
// At each index, if there is a similar pair, push 1 to the vector same otherwise 0 to the vector same.
// The function returns the sum of vector same.
unsigned int Colour::totalCorrect(Colour& secretcolor){
    std::vector<unsigned int> same;
    for (unsigned int i=0;i<SIZE;++i)
    {
        if(tolower(secretcolor.convertSeries().at(i))==(tolower(convertSeries().at(i))))
        {
            same.push_back(1);
        }
    }
    return accumulate(same.begin(),same.end(),0);
}

// First, the function compare each color in the series at the same index,
// The unmatched one will be push to vector a for seret series and vector b for guess series
// Vector c inlude the intersection of vector a and vector b
// The function return the size of vector c.
unsigned int Colour::wrongPosition(Colour& secretcolor) {
    std::vector<unsigned int> a;
    std::vector<unsigned int> b;
    std::vector<unsigned int> c;
    for (unsigned int i=0;i<SIZE;++i)
    {
        if(tolower(secretcolor.convertSeries().at(i))!=(tolower(convertSeries().at(i))))
        {
            a.push_back(tolower(secretcolor.convertSeries().at(i)));
            b.push_back(tolower(convertSeries().at(i)));
        }
    }
            std::sort(a.begin(), a.end());
            std::sort(b.begin(), b.end());
            std::set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
                return c.size();
}

// Function starts looking at each character in the color series and check if it belongs to the given vector of character;
// the function returns false if the series include only allowed colours, true otherwise.
bool Colour::includeNotvalidcolor() {
    bool notvalid=false;
    unsigned int i=0;
    while (i<SIZE and notvalid==false)
    {
        if(std::find(colors.begin(), colors.end(), convertSeries().at(i))!=colors.end())
            {++i;}
        else
            { notvalid=true;}
    }
    return notvalid;
}

void Colour::print() {
    std::cout<<"| ";
    for (char i : convertSeries())
    {
       std::cout <<(char)toupper(i)<<" ";
    }
    std::cout<<"| ";
}



