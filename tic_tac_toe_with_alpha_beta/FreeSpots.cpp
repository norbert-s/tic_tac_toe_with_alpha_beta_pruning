#include "Game.h"

//rendben
void Game::creatingAVectorOfTheCurrentFreeSpots() {
	freeSpots.clear();
	for (auto& row : arr) {
		for (auto& col : row) {
			if (col != "X" && col != "O") {
				freeSpots.push_back(std::stoi(col));
			}
		}
	}
}
//rendben
bool Game::checkIfThisSpotIsFree(int spot) {
	creatingAVectorOfTheCurrentFreeSpots();
	for (const auto& i : freeSpots)
		if (i == spot)
			return true;
	return false;
}

