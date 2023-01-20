# Overview
I wrote a TicTacToe console game in C++. Tic-tac-toe is played on a three-by-three grid by two players, who alternately place the marks X and O in one of the nine spaces in the grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner. My program takes the user's input and fills the board according to the coordinates that the user types. It has 6 options for the user to choose from. If user types ?. . .Display this options, e. . .Edit a square, d. . .Display the current board, s. . .Save a board, c. . .Clear the board, q. . .Quit the game. The game follows tic-tac-toe rules and checks for possible user errors like wrong coordinates or wrong file format.

I chose this project in order to practice the concepts that I learned in C++. Such as Variables, Expressions, Conditionals, Loops, Functions, Classes, Data structures.

[TicTacToe Console Game C++](https://youtu.be/k5ByNlxN2JY)

# Development Environment

I used Visual Studio as my development environment.

I used C++ for this project and multiple libraries. STL library <vector>, library <fstream> for using files, library <string> to use string class, and library <iostream> which is responsible for input and output of the data.

# Useful Websites
- [C++ Classes and Objects](https://www.w3schools.com/cpp/cpp_classes.asp#:~:text=C%2B%2B%20is%20an%20object%2Doriented,such%20as%20drive%20and%20brake.)
- [C++ Stack Overflow](https://stackoverflow.com/questions/tagged/c%2B%2B)
- [C++ Essential Training](https://www.linkedin.com/learning/c-plus-plus-essential-training-15106801)

# Future Work
- Change the winner function. Use loops to check if the user won instead of hardcoded version that I have now.
- Add Try, Catch, and Throw exceptions to catch all possible errors. Add assert functions to terminate the program in case of logical error.
- Add more classes to my program.Use more OOP principles for data redundancy. For example class board that will store the board and square coordinates.
