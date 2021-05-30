#include "BoardManager.hpp"

//Creates dynamically allocated 2D array
void TicTacToeBoard::InitializeTiles()
{
	tiles = new char* [size];
	for (int i = 0; i < size; i++) //board rows
	{
		tiles[i] = new char[size];
		for (int j = 0; j < size; j++) //board columns
		{
			tiles[i][j] = '*';
			openSpaces.push_back(tilePairs(i, j));
		}
	}
}


//Creates a board display
void TicTacToeBoard::DrawBoard()
{
	int rowIndexer = 0;

	turnsPlayed++;
	std::cout << "\nRound: " << turnsPlayed << "\n ";
	
	//Creates column indexes for board
	for (int i = 0; i < size; i++)
	{
		std::cout << " " << i;
	}
	std::cout << "\n";

	//Creates row indexes for board and draws tile spaces
	for (int i = 0; i < size; i++)
	{
		std::cout << rowIndexer;
		for (int j = 0; j < size; j++)
		{
			std::cout << "|";
			std::cout << tiles[i][j];
		}
		std::cout << "|" << std::endl;
		rowIndexer++;
	}
}


//Update the board after an input has been made
void TicTacToeBoard::UpdateBoard(int row, int col)
{
	switch (currentTurn)
	{
	case (Turn::Player1):
		tiles[row][col] = 'X';
		break;
	case (Turn::Player2):
		tiles[row][col] = 'O';
		break;
	}
	openSpaces.remove(tilePairs(row, col));
	DrawBoard();
}


//Change turns
void TicTacToeBoard::SwitchTurn()
{
	switch (currentTurn)
	{
	case (Turn::Player1):
		currentTurn = Turn::Player2;
		break;
	case (Turn::Player2):
		currentTurn = Turn::Player1;
		break;
	}
}


//Checks to see if a winner or tie has been reached
int TicTacToeBoard::CheckEndState()
{
	bool horizontalWin;
	bool verticalWin;
	bool rightDiagonalWin;
	bool leftDiagonalWin;

	//Checking Vertical & Horizontal Win
	for (int i = 0; i < size; i++)
	{
		horizontalWin = true;
		verticalWin = true;
		rightDiagonalWin = true;
		leftDiagonalWin = true;
		for (int j = 0; j < size; j++)
		{
			//if all tiles in a group are equal (Horizontal)
			if (tiles[i][0] == '*' || tiles[i][j] != tiles[i][0])
			{
				horizontalWin = false;
			}
			//if all tiles at same index are equal (Vertical)
			if (tiles[0][i] == '*' || tiles[j][i] != tiles[0][i])
			{
				verticalWin = false;
			}
			//if all tiles at +1 incrementing index are equal (Right Diagonal)
			if (tiles[0][0] == '*' || tiles[j][j] != tiles[0][0])
			{
				rightDiagonalWin = false;
			}
			//if all tiles at -1 index increment from end are equal (Left Diagonal)
			if (tiles[0][size - 1] == '*' || tiles[j][(size - 1) - j] != tiles[0][size - 1])
			{
				leftDiagonalWin = false;
			}
		}
		if (horizontalWin || verticalWin || rightDiagonalWin || leftDiagonalWin)
		{
			SwitchTurn();
			std::cout << "Player " << currentTurn << " has Won!" << std::endl;
			switch (currentTurn)
			{
			case (Turn::Player1):
				return EndState::P1; //End Game
			case (Turn::Player2):
				return EndState::P2; //End Game
			}
		}
		if (turnsPlayed == (size * size)+1)
		{
			std::cout << "It's a Tie!" << std::endl;
			return EndState::Tie; //End Game
		}
	}
	return EndState::NotOver; //Continue Game
}


//Clean up
void TicTacToeBoard::DeallocateMemory()
{
	for (int i = 0; i < size; i++)
	{
		delete[] tiles[i];
	}
	delete[] tiles;
}