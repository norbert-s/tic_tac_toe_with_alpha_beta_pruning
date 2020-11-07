
#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <string>
#include <thread>
#include <vector>
#define DIMENSION_OF_ARRAY 3
#define MAX_NUMBER_OF_SQUARES 9
#define WINNING_ROWS 8
#define WINNING_COLUMNS 3
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::thread;
using std::vector;
class Game {

	

	int remaining = MAX_NUMBER_OF_SQUARES;
	string beginner = "";
	string who_is_next = "";
	
	int choosenMove = -1;
	vector<int>freeSpots;
	int counterX = 0;
	int counterO = 0;
	
public:
	string player = "";
	string computer = "";
	int winningCombination[WINNING_ROWS][WINNING_COLUMNS]{
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{1,4,7},
	{2,5,8},
	{3,6,9},
	{1,5,9},
	{3,5,7}
	};
	string arr[DIMENSION_OF_ARRAY][DIMENSION_OF_ARRAY];
	Game();
	void fillCharArrWithNumbers();
	void drawBoardOnTheScreen();
	void chooseSide();
	void whoComesNext();
	void gameDriver();
	void takeMoveFromPlayerOrCalculateComputerMove();
	void PushChoosenSpotToVector();
	//void calculateComputerMove();
	int calculateComputerMove(string arr[3][3], string computerSign, string humanSign, int remaining);
	void pushComputerMoveToVector(int moveToPush);
	void creatingAVectorOfTheCurrentFreeSpots();
	bool checkIfThisSpotIsFree(int spot);
	void gameOver();
	bool checkIfEndState();

	//void bestMove();
	//int minimax(int board[3][3], int depth, bool isMaximizing);
};
#endif // !_GAME_H_
#pragma once
