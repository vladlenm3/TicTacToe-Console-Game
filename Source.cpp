/************************************************
* TicTacToe console game.
* Author: Vladlen Mykhailovskyi
* Date: 1/19/2023
*************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <ctype.h>                                 
#include <string>                                                                                                                                                      
using namespace std;

/**************************************************
* This class holds the name of the file where
* the board is located.
***************************************************/
class fName
{
private:
	string fileName = "Text.txt";
public:
	string getFname() { return fileName; }
};

/**************************************************
* Those are prototypes of all the functions.
***************************************************/
void interact(char board[][3], fName f, bool &xTurn, int &count);
void editBoard(char board[][3], fName f, bool &xTurn, int &count);
void clear(char board[][3]);
void Bexit(char board[][3], fName f, bool &xTurn, int &count);


/**************************************************
* This function reads the data from the .txt file.
***************************************************/
void readBoard(char board[][3], fName f, bool &xTurn)
{
	// creating ifstream object
	ifstream fin;
	fin.open(f.getFname());

	// checking for errors
	if (fin.fail())
	{
		cout << " ERROR1: Failed reading the file "
			<< f.getFname() << endl;
		return;
	}

	// reading the board to an arry
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fin >> board[i][j];

			if (fin.fail())
			{
				cout << " ERROR2: Somthing happened while reading a file"
					<< f.getFname() << endl;
				fin.close();
				return;
			}
		}
	}
	fin.close();
	return;
}

/************************************************
* This function saves the board to a .txt file.
*************************************************/
void saveBoard(char board[][3])
{
	string fileName;
	cout << " Please enter a file name in .txt format to save the board: ";
	getline(cin, fileName);

	// ofstream object created
	ofstream fout;
	fout.open(fileName.c_str());
	//checking for errors
	if (fout.fail())
	{
		cout << " ERROR4: Fail to open a file check format.\n";
		return;
	}

	//writing to a file
	bool success = true;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				board[i][j] = '.';
			fout << board[i][j];
			if (fout.fail())
			{
				cout << " ERROR5: Fail writing to file "
					<< fileName;
				success = false;
				fout.close();
				return;
			}
		}

		fout << "\n";
	}
	if (success)
	{
		cout << " Board was successfully writen to a file "
			<< fileName << ".\n";
		// vector that stores all the file with saved boards
		vector <string> files;
		files.push_back(fileName);
		clear(board);
	}
	else
	{
		cout << " Board is not written FAIL_345_15\n";
	}
	fout.close();
}

/********************************************************************************
* This function displays the options on the screen.
*********************************************************************************/
void displayOptions(char board[][3], fName f, bool &xTurn, int &count)
{
	system("Color B");
	cout << " \n Options: \n"
		<< "\t?. . .Display this options\n"
		<< "\te. . .Edit a square\n"
		<< "\td. . .Display the current board\n"
		<< "\ts. . .Save a board\n"
		<< "\tc. . .Clear the board\n"
		<< "\tq. . .Quit";
	interact(board, f, xTurn, count);
}

/**************************************************************************************
* This function displays the board on the screen.
***************************************************************************************/
void displayBoard(char board[][3], fName f, bool & xTurn, int &count)
{
	cout << "    A   B   C\n";
	for (int i = 0; i < 3; i++)
	{
		cout << " " << i + 1 << "  ";
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '.')
			{
				board[i][j] = ' ';
			}
			if (j == 1 || j == 2)
			{
				cout << "| ";
			}

			cout << board[i][j] << " ";
		}
		cout << endl;
		if (i == 0 || i == 1)
		{
			cout << "   ---+---+---\n";
		}
	}
	interact(board, f, xTurn, count);
}

/***************************************************************************
* This function makes the game interactive.
***************************************************************************/
void interact(char board[][3], fName f, bool &xTurn, int &count)
{
	char option;
	cout << "\n>";
	cin >> option;
	cin.ignore();
	bool invalid = true;

	while (invalid)
	{
		switch (option)
		{
		case 'd':
		case 'D':
			readBoard(board, f, xTurn);
			displayBoard(board, f, xTurn, count);
			invalid = false;
			break;
		case '?':
			displayOptions(board, f, xTurn, count);
			invalid = false;
			break;
		case 's':
		case 'S':
			saveBoard(board);
			invalid = false;
			displayOptions(board, f, xTurn, count);
			break;
		case 'E':
		case 'e':
			editBoard(board, f, xTurn, count);
			invalid = false;
		case 'C':
		case 'c':
			count = 0;
			xTurn = true;
			clear(board);
			displayBoard(board, f, xTurn, count);
			invalid = false;
			break;
		case 'Q':
		case 'q':
			Bexit(board, f, xTurn, count);
			invalid = false;
			break;
		case 'Z':
			break;
		default:
			cout << "INVALID OPTION: Try again: \n>";
			cin >> option;
			break;

		}
	}
}

/******************************************************
* This function is responsible for game exit.
*******************************************************/
void Bexit(char board[][3], fName f, bool &xTurn, int &count)
{
	char anwser;
	bool invalid = false;
	do
	{
		cout << " Are you sure you want to quit?(y/n): ";
		cin >> anwser;
		if (anwser == 'y' || anwser == 'Y')
			exit(1);
		else if (anwser == 'n' || anwser == 'N')
		{
			displayOptions(board, f, xTurn, count);

		}
		else
		{
			cout << " INVALID OPTION: Your option must be (y or n). "
				<< "Try again.\n";
			invalid = true;
		}
	} while (invalid);
}
/**************************************************************
* The purpuse of this function is to clear the existing board
* and restart the game.
**************************************************************/
void clear(char board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
			{
				board[i][j] = ' ';
			}
		}
	}
}
/***********************************************************************
* This function detrmins the winner of the game according to the rules.
************************************************************************/
bool winner(char board[][3], fName f, bool &xTurn, int &draw)
{
	bool notWon = true;
	if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
		(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
		(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
		(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
		(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
		(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
		(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
		(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
	{
		cout << "Congradulations \"X\" won!";
		displayOptions(board, f, xTurn, draw);
		notWon = false;
	}
	else if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
		(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
		(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
		(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
		(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
		(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
		(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
		(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
	{
		cout << "Congradulations \"O\" won!";
		displayOptions(board, f, xTurn, draw);
		notWon = false;
	}
	else if (notWon == true && draw >= 9)
	{
		cout << "Draw no Winner! Shake your hand it was a nice game.\n";
		displayOptions(board, f, xTurn, draw);
		notWon = false;
	}
	return notWon;
}
/**********************************************
* This function allows user to edit the board.
***********************************************/
void editBoard(char board[][3], fName f, bool &xTurn, int &count)
{
	char letter;
	int number;
	char sign;

	while (winner(board, f, xTurn, count))
	{
		if (xTurn)
		{
			xTurn = false;
			sign = 'X';
			cout << " It is \"X\" turn enter the cordinates.(letter and number): ";
			cin >> letter >> number;
			if (islower(letter))
			{
				letter = toupper(letter);
			}
			while ((letter < 'A' || letter > 'C') && (letter != 'B') || (number < 1 || number > 3) && (number != 2))
			{
				cout << "INVALID COORRDINATES: Your letter must be from A to C "
					<< "and number from 1 to 3. Try again: ";
				cin >> letter >> number;
				if (islower(letter))
				{
					letter = toupper(letter);
				}
			}
		}
		else
		{
			xTurn = true;
			sign = 'O';
			cout << " It is \"O\" turn enter the cordinates.(letter and number): ";
			cin >> letter >> number;
			if (islower(letter))
			{
				letter = toupper(letter);
			}
			while ((letter < 'A' || letter > 'C') && (letter != 'B') || (number < 1 || number > 3) && (number != 2))

			{
				cout << "INVALID COORRDINATES: Your letter must be from A to C "
					<< "and number from 1 to 3. Try again: ";
				cin >> letter >> number;
				if (islower(letter))
				{
					letter = toupper(letter);
				}
			}
		}
		int row = number - 1;
		int col = letter - 65;
		while (board[row][col] != ' ')
		{
			cout << "ERROR: The spot is already filled! Try another cordinates: ";
			cin >> letter >> number;
			if (islower(letter))
			{
				letter = toupper(letter);
			}
			while ((letter < 'A' || letter > 'C') && (letter != 'B') || (number < 1 || number > 3) && (number != 2))
			{
				cout << "INVALID COORRDINATES: Your letter must be from A to C "
					<< "and number from 1 to 3. Try again: ";
				cin >> letter >> number;
				if (islower(letter))
				{
					letter = toupper(letter);
				}
			}
			row = number - 1;
			col = letter - 65;
		}
		count++;
		board[row][col] = sign;
		displayBoard(board, f, xTurn, count);
	}
}
/***********************************************************
* This is the main function which call other functions.
************************************************************/
int main()
{
	cout << "----------------------------------------------------\n";
	char board[3][3];
	fName f;
	bool xTurn = true;
	int count = 0;
	displayOptions(board, f, xTurn, count);
	system("pause");
	return 0;
}