// Mastermind

#include "colour.hh"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Number of colors in a series
const unsigned int SIZE = 4;
// Maximum number of guesses
const unsigned int GUESS_MAX = 10;
std::vector<char> color = {'B', 'R', 'Y', 'G', 'O','V','b', 'r', 'y', 'g', 'o','v'};

// Length of the suffix part when printing a row.
// The suffix consists of three vertical lines ('|') and two digits, where one
// tells the amount of totally correct colors and the other tells the amount
// of correct colors in incorrect positions.
const unsigned int SUFFIX_LENGTH_IN_PRINT = 5;

// Text printed at the beginning of the program
const string INFO_TEXT = "Colors in use: \
B = Blue, R = Red, Y = Yellow, G = Green, O = Orange, V = Violet";

// Reads the input way, either random or listing way,
// and fills the color series in the user-desired way.
// Repeats the question until the user enters either R or L.

void get_input(Colour& SECRETSERIES)
{
    cout << "Enter an input way (R = random, L = list): ";
    string input_str = "";
    cin >> input_str;
    if(input_str == "R" or input_str == "r")
    {
        cout << "Enter a seed value: ";
        int seed = 0;
        cin >> seed;
        //Fill color series randomly based on the seed value
        std::vector<char> input;
        std::default_random_engine rand_gen;
        rand_gen.seed(seed);
        std::uniform_int_distribution<int> distribution(0, 5);
        for(unsigned int i = 0; i < SIZE; ++i)
        {
            input.push_back(color.at(distribution(rand_gen)));
        }
        std::string series(input.begin(), input.end());
        Colour secretColor(series);
        SECRETSERIES=secretColor;
    }

    else if(input_str == "L" or input_str == "l")
    {
        bool accepted = false;
        while(not accepted)
        {
            cout << "Enter four colors (four letters without spaces): ";
            string colors = "";
            cin >> colors;
            if (colors.length()==4)
            {
                Colour inputcolor(colors);
                if (inputcolor.includeNotvalidcolor()==true)
                {
                    cout<<"Unknown color"<<endl;
                }
                else
                {
                    Colour secretColor(colors);
                    SECRETSERIES=secretColor;
                    accepted =true;
                }
            }
            else
                {cout<< "Wrong size"<<endl;}
        }
    }

    else
    {
        cout << "Bad input" << endl;
        get_input(SECRETSERIES);
    }
}

// Prints a line consisting of the given character c.
// The length of the line is given in the parameter line_length.
void print_line_with_char(char c, unsigned int line_length)
{
    for(unsigned int i = 0; i < line_length; ++i)
    {
        cout << c;
    }
    cout << endl;
}

// Prints all color series.
void print_all(std::vector<Colour> VectorofGuess, Colour SECRETSERIES)
{
    print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);
    for(auto series : VectorofGuess)
    {
        // Print each guess series along with its numbers of total correct and correct but wrong position characters.
        series.print();
        cout<<series.totalCorrect(SECRETSERIES)<<" | "<<series.wrongPosition(SECRETSERIES)<<" |"<<endl;
    }
    print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);
}

// Implements the actual game loop, where user-given guesses are read
// and compared to the secret row.
// On each round, all rows given so far are printed.

void playthegame(Colour SECRETSERIES) {
    // Create a vector whose elements are  Colour objects, this vector represent the player's guess
    std::vector<Colour> VectorofGuess;
    unsigned int turn = 1;
    bool out_of_turn=false;
    unsigned int correctColorguessed=0;
    // while loop runs on the condition that the guess has not been correct and not out of guesses yet)
    while(correctColorguessed!=4 and !out_of_turn)
    {   // Get the input guess and make sure it has the correct size and include only allowed colors, exit if enter q or Q.
        cout << "ROW> ";
        string guess = "";
        cin >> guess;

        if (guess=="q" or guess=="Q")
        {
            return;
        }

        if (guess.length()!=4) {
            cout<< "Wrong size"<<endl;
        }

        else
        {
            Colour inputcolor(guess);
            if (inputcolor.includeNotvalidcolor()==true)
            {
                cout<<"Unknown color"<<endl;
            }
            else
            {
                // If the guess series is valid, take it as input to create a colour object,
                // Count the number of total correct colors guess,
                // add the object to the Vector of guess.
                Colour guessColor(guess);
                correctColorguessed = guessColor.totalCorrect(SECRETSERIES);
                VectorofGuess.push_back(guessColor);
                // Print all the guess color so far,
                print_all(VectorofGuess,SECRETSERIES);
                // if increment turn by 1 if not out of guess yet, return to the while loop.
                if(turn<GUESS_MAX)
                {
                    ++turn;
                }
                else
                {
                    out_of_turn=true;
                }

            }
        }
    }
    // If while loop exit because of out of run print:
    if (out_of_turn==true)
    {
        cout<<"You lost: Maximum number of guesses done"<<endl;
    }

    // Printing if while loop exit because the variable correctColorguessed==4.
    else
    {
        cout<<"You won: Congratulations!"<<endl;
    }
}


int main()
{
    // Create a object colour for the secretseries
    Colour secretColours("");
    cout << INFO_TEXT << endl;
    print_line_with_char('*', INFO_TEXT.size());
    get_input(secretColours);
    playthegame(secretColours);
    return 0;
}

