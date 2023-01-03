# GuessingGame
 This program implements a simple guessing game. 
      First a secret series of four colors is either given or drawn. The series can have several identical colors, but none of the four positions can be empty.
      Then, The user tries to guess which colors the secret series has and in which order they occur there. For this purpose, the user gives their own series of four colors, and the program tells how many colors in the guess was totally correct (correct color in correct position) and how many of them were correct in color (but incorrect in position). After that the user guesses again and so on.
      At first, the user is asked, if the game board will be filled with randomly drawn colors, or with user-given ones. (The latter way is not very sensible, but it is useful in testing purposes.) In the first option, a seed value for the random number generator will be asked next. In the latter option, the user is asked to input four colors (the first letters of the colors, i.e. a string consisting of four characters).
      On each round, the user is asked for a new guess. The player wins if all colors in the guess are totally correct. The player loses if they have used the maximum
 number (10) of guesses without the right one.
      The program checks if the user-given colors are among accepted ones. When the game ends, the program tells if the player won or lost.

