#include "Game.h"

inline void Game::fillCharArrWithNumbers() {
	int count = 1;
	for (auto& row : arr) {
		for (auto& col : row) {
			string a = std::to_string(count++);
			col = a;
		}
	}
}

inline void Game::chooseSide() {
	bool choosenOk = false;
	while (!choosenOk) {
		cout << "which one do you choose, 'X' or 'O' ?" << endl;
		cin >> player;
		if (player == "X" || player == "O") {
			choosenOk = true;
			if (player == "X")
				computer = "O";
			else
				computer = "X";
		}
	}
	cout << "player is " << player << endl;
	player == "X" ? beginner = "player" : beginner = "Computer";
	cout << "the first move is of " << beginner << endl;
	who_is_next = beginner;
}



