#include "Game.h"


void Game::drawBoardOnTheScreen() {
	for (auto& row : arr) {
		cout << "|";
		for (auto& col : row) {
			cout << col << "|";
		}
		cout << endl;
	}
}


void Game::whoComesNext() {
	{
		if (remaining == 0) {
			gameOver();
		}
		if (who_is_next == "player") {
			who_is_next = "Computer";
		}
		else {
			who_is_next = "player";
		}
	}
}
void Game::takeMoveFromPlayerOrCalculateComputerMove() {
	if (remaining <= MAX_NUMBER_OF_SQUARES && remaining > 0) {
		cout << "next move is of " << who_is_next << endl;
	}
	if (who_is_next == "player") {
		cout << "what's your next move? " << endl;
		PushChoosenSpotToVector();
	}
	else {
		cout << "computer is thinking " << endl;
		int moveToPush = calculateComputerMove(arr,computer,player,remaining);
		std::cout << "choosen move in takefromplayer" << moveToPush << std::endl;
		pushComputerMoveToVector(moveToPush);
	}
}
void Game::pushComputerMoveToVector(int moveToPush) {
	while (true) {
		//check if the position is already taken
		std::cout << std::boolalpha << "szabad a spot ? "<<checkIfThisSpotIsFree(moveToPush) << std::endl;
		if ( moveToPush >= 1 && moveToPush <= MAX_NUMBER_OF_SQUARES && checkIfThisSpotIsFree(moveToPush)) {
			for (auto& row : arr) {
				for (auto& col : row) {
					if (col == std::to_string(moveToPush)) {
						if (who_is_next == "player") {
							col = player;
						}
						else {

							col = computer;
						}
					}
				}
			}
			remaining--;
			break;
		}
		else {
			cout << "valassz masik szamot" << endl;
			calculateComputerMove(arr, computer, player, remaining);
		}
	}

}

void Game::PushChoosenSpotToVector() {
	while (true) {
		cin >> choosenMove;
		//check if the position is already taken
		creatingAVectorOfTheCurrentFreeSpots();
		if (choosenMove >= 1 && choosenMove <= 9 && checkIfThisSpotIsFree(choosenMove)) {
			for (auto& row : arr) {
				for (auto& col : row) {
					if (col == std::to_string(choosenMove)) {
						if (who_is_next == "player") {
							col = player;
						}
						else {
							col = computer;
						}
					}
				}
			}
			cout << std::boolalpha;
			cout << checkIfThisSpotIsFree(choosenMove) << endl;
			cout << freeSpots.size() << endl;
			remaining--;
			break;
		}
		else {
			cout << "valassz masik mezot ! " << endl;

		}
	}
}