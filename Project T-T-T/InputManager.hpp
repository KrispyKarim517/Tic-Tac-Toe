#pragma once
#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "BoardManager.hpp"

//Input options for initializing the game
void StartSettings(TicTacToeBoard& board);
//Allows user to make a move by selecting a row and column
void UserMove(TicTacToeBoard& board);
//Clears input stream if user inputs wrong type
void CheckInputFail(int input);

#endif