#pragma once
#ifndef AIMANAGER_HPP
#define AIMANAGER_HPP

#include <windows.h>
#include "BoardManager.hpp"

//Finds the board slot with the most adjacent opponent symbols to block them from winning
void AiDefenderMove(TicTacToeBoard& board);
//Counts the number of adjacent opponent symbols
int countAdjacent(TicTacToeBoard& board, std::list<char>& adjSymbols, int row, int col);
//Prints Ai dialogue over time period
void WriteDialogue(std::string str);

#endif