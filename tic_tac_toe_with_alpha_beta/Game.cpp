
#include "Init.cpp"
#include <cstdlib>
#include "Game.h"

Game::Game() {
	fillCharArrWithNumbers();
	drawBoardOnTheScreen();
	chooseSide();
	gameDriver();
}

void Game::gameDriver() {
	while (remaining != 0) {
		takeMoveFromPlayerOrCalculateComputerMove();
		drawBoardOnTheScreen();
		bool end = false;
		end = checkIfEndState();
		if (end) {
			gameOver();
			break;
		}
		else
			whoComesNext();
	}
}