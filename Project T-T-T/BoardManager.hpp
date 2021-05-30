#pragma once
#ifndef BOARDMANAGER_HPP
#define BOARDMANAGER_HPP

#include <iostream>
#include <list>

//Help code readability by using descriptive names
enum Turn { Player1 = 1, Player2 = 2 };
enum EndState { NotOver = 0, P1 = 1, P2 = 2, Tie = 3 };
typedef std::pair<int, int> tilePairs;

class TicTacToeBoard
{
	public:
		//Data Members
		char** tiles;
		std::list<tilePairs> openSpaces;
		int currentTurn = Turn::Player1;
		int turnsPlayed;
		int playerTurn;
		int size;
		
		//Member Functions
		void InitializeTiles(); //Creates dynamically allocated 2D array
		void DrawBoard(); //Creates a board display
		void UpdateBoard(int row, int col); //Update the board after an input has been made
		void SwitchTurn(); //Change turns
		int CheckEndState(); //Checks to see if a winner or tie has been reached
		void DeallocateMemory(); //Clean up
};

#endif