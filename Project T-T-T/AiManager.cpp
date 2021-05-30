#include "AiManager.hpp"

//Finds the board slot with the most adjacent opponent symbols to block them from winning
void AiDefenderMove(TicTacToeBoard& board)
{
	std::list<char> adjSymbols;
	int highestCount = 0;
	int count;
	int row = 1, col = 1;

	//Iterates through each open space to find board slot with most adjacent opponent symbols
	for (std::list<tilePairs>::iterator iter = board.openSpaces.begin(); iter != board.openSpaces.end(); ++iter)
	{
		adjSymbols.clear();
		count = max(countAdjacent(board, adjSymbols, iter->first, iter->second), highestCount);
		if (count > highestCount)
		{
			highestCount = count;
			row = iter->first;
			col = iter->second;
		}
	}
	board.UpdateBoard(row, col);
}


//Counts the number of adjacent opponent symbols
int countAdjacent(TicTacToeBoard& board, std::list<char>& adjSymbols, int row, int col)
{
	int adjCount = 0;

	//Checks all adjacent positions
	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			//Checks board boundaries
			if (!(row + x < 0 || row + x >= board.size || col + y < 0 || col + y >= board.size))
			{
				if (!(row + x == row && col + y == col))
				{
					adjSymbols.push_back(board.tiles[row + x][col + y]);
				}
			}
		}
	}

	//Count number of opponent symbols
	for (std::list<char>::iterator iter = adjSymbols.begin(); iter != adjSymbols.end(); ++iter)
	{
		if (board.currentTurn == Turn::Player1)
		{
			if (*iter == 'O')
			{
				adjCount++; //Count all adjacent 'O'
			}
		}
		else
		{
			if (*iter == 'X')
			{
				adjCount++; //Count all adjacent 'X'
			}
		}
	}
	return adjCount;
}


//Prints Ai dialogue over time period
void WriteDialogue(std::string sentence)
{
	for (char& letter : sentence)
	{
		std::cout << letter;
		if (ispunct(letter))
		{
			Sleep(300); //Long pause after each punctuation
		}
		Sleep(50); //Short pause after each letter
	}
}