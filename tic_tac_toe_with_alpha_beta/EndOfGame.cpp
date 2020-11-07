#include "Game.h"
#include <thread>
#include <chrono>
//rendben
void Game::gameOver() {
	using namespace std::chrono_literals;
	if (counterX < 3 && counterO < 3) {

		cout << "it is a draw" << endl;
		std::this_thread::sleep_for(5s);
	}
	else if ((counterX == 3 && player == "X") || (counterO == 3 && player == "O")) {
		std::this_thread::sleep_for(5s);
		cout << "Player has won" << endl;
	}
	else if ((counterX == 3 && player != "X") || (counterO == 3 && player != "O")) {
		std::this_thread::sleep_for(5s);
		cout << "computer has won" << endl;
	}
	std::this_thread::sleep_for(5s);
	cout << "game over" << endl;
}


//sztem rendben
bool Game::checkIfEndState() {
	if (remaining <= 4) {
		for (int i = 0; i < WINNING_ROWS; i++) {
			counterO = 0;
			counterX = 0;
			for (int j = 0; j < WINNING_COLUMNS; j++) {
				int elemFromWinningCombo = winningCombination[i][j];
				elemFromWinningCombo -= 1;
				string talalt = arr[elemFromWinningCombo / 3][elemFromWinningCombo % 3];
				if (talalt == "O")
					counterO++;
				if (talalt == "X")
					counterX++;
			}
			if (counterX == 3 || counterO == 3)
				return true;
		}
	}
	return false;
}