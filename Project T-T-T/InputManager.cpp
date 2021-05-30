#include "InputManager.hpp"
#undef max();

//Input options for initializing the game
void StartSettings(TicTacToeBoard& board)
{
    int size; //3 to 10
    int turn; //First or Second

    do //User Input: Board Size
    {
        std::cout << "\nHow big would you like the board to be? (3 to 10): ";
        std::cin >> size;
        CheckInputFail(size);
    } while (size < 3 || size > 10);
    board.size = size;

    do //User Input: First or Second
    {
        std::cout << "\nWould you like to be first or second? (1 or 2): ";
        std::cin >> turn;
        CheckInputFail(turn);
    } while (not(turn == Turn::Player1 || turn == Turn::Player2));
    board.playerTurn = turn;
}


//Allows user to make a move by selecting a row and column
void UserMove(TicTacToeBoard& board)
{
    int row, col;

    ROW: do //User Input: Row
    {
        std::cout << "Select Row: ";
        std::cin >> row;

        if (!std::cin)
        {
            CheckInputFail(row);
            goto ROW;
        }
    } while (row < 0 || row >= board.size);

    COL: do //User Input: Column
    {
        std::cout << "Select Column: ";
        std::cin >> col;

        if (!std::cin)
        {
            CheckInputFail(col);
            goto COL;
        }
    } while (col < 0 || col >= board.size);

    //If user selects a spot that is already taken
    if (board.tiles[row][col] != '*')
    {
        std::cout << "\nSpot already taken" << std::endl;
        goto ROW;
    }

    board.UpdateBoard(row, col);
}


//Clears input stream if user inputs wrong type
void CheckInputFail(int input)
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Source: https://stackoverflow.com/questions/3876107/while-loop-loops-infinitely-when-wrong-input-is-entered
    }
}