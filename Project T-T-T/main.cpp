//Karim Najib
//Coding Challenge - Carbonated

/////
// Hello There! This is my Tic-Tac-Toe Project. There are two modes to play with :)
// Fight against a defensive AI which tries only to block your moves (he has anger issues) and claim victory!...or lose
// Input your own custom board size from 3x3 to 10x10
/////

#include "InputManager.hpp"
#include "AiManager.hpp"

TicTacToeBoard board;

//Welcome Display
void WelcomeScreen()
{
	std::cout << "WELCOME TO TIC-TAC-TOE" << std::endl;
	std::cout << "----------------------\n" << std::endl;
	std::cout << "Play on a custom board size against a defensive AI opponent" << std::endl;
}


//Program Execution
int main()
{
	//Start
	WelcomeScreen();
	StartSettings(board);
	
	//Board Setup
	board.InitializeTiles();
	board.DrawBoard();

	//Game
	while (board.CheckEndState() == EndState::NotOver)
	{
		if (board.currentTurn == board.playerTurn)
		{
			UserMove(board);
		}
		else
		{
			AiDefenderMove(board);
		}
		board.SwitchTurn();
	}
	
	//End
	board.DeallocateMemory();
	
	return 0;
}