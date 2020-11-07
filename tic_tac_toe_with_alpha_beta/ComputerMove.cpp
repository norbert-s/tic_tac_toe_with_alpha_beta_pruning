#include "Game.h"
#include <map>


class Ai {
    int counterOfDepth;
    std::vector<int>freeSpotsHere;
    string computerHere;
    string humanHere;
    int counterO;
    int counterX;
    //int remainingCopy;
    //a konstruktor készít egy másolatot a tömbrõl
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
    std::map<string, int> scores = { {"X",-10},{"O",10},{"tie",0} };
    std::map<string, int> scoresX = { {"X",10},{"O",-10},{"tie",0} };
public:
    Ai(string computerSign,string HumanSign) {

        computerHere = computerSign;
        humanHere = HumanSign;
        counterOfDepth = 0;
    }
    string bestMove(string arr[3][3]);
    int creatingAVectorOfTheCurrentFreeSpots(string arr[3][3]);
    //bool checkIfThisSpotIsFree(int spot);
    string checkIfEndState(string arr[3][3]); 
    int minimax(string arr[3][3], int depth, int alfa,int  beta ,bool isMaximizing);
    int min(int elso, int masodik);
    int max(int elso, int masodik);
};

int Game::calculateComputerMove(string arr[3][3], string computerSign, string humanSign, int remaining) {

    Ai ai( computerSign, humanSign);
    std::cout << "comouter sign " << computerSign << " human sign: " << humanSign << std::endl;
    string thisIsTheMove = ai.bestMove(arr);
    //pushComputerMoveToVector(thisIsTheMove);
    std::cout << "this is the move" << thisIsTheMove << std::endl;
    int thisIsTheChoosenMove=  std::stoi(thisIsTheMove);
    
    return thisIsTheChoosenMove;
}

string Ai::bestMove(string arrCopy[3][3]) {
    // AI to make its turn
    
    //long long int bestScore = std::numeric_limits<int>::min();
    int bestScore = -100;
    string move;
    int alfa = -1000;
    int beta = 1000;
    //lemásolva a tömb akkori állapota, amikor az ai-é a következõ lépés

    //
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Is the spot available? 
            if (arrCopy[i][j] != "O" && arrCopy[i][j] != "X") {
                string temp = arrCopy[i][j];//ez egy szám lesz
                //std::cout << "kiirjuk a temp értékét a bestmove elsõ fázisánál : " << temp << std::endl;
                //std::cout << "computer here : " << computerHere << std::endl;
                arrCopy[i][j] = computerHere;
                int score = 0;
                score = minimax(arrCopy, 9,alfa,beta, false);
                //std::cout << "kiirjuk a score-t ami a bestmovenál van : " << score << std::endl;
                arrCopy[i][j] = temp;
                
                if (score > bestScore) {
                    //std::cout << "bestmove, score :" << bestScore << std::endl;
                    bestScore = score;
                    move = temp;
                }
            }
        }
    }

    return move;

}
int Ai::minimax(string arrCopy[3][3], int depth, int alfa,int beta,bool isMaximizing) {
    string result = checkIfEndState(arrCopy);
    //std::cout << "kiirjuk a resultbol jovo erteket az if elõtt vayunk : " << result << std::endl;
    
    if ( (depth==0|| (result != "false")) && computerHere=="O" ) {

        return scores.at(result);
    }
    if ((depth == 0 || (result != "false")) && computerHere == "X") {

        return scoresX.at(result);
    }
    //if(result != "false" && computerHere == "O") {

    //    return scoresX.at(result);
    //}
    //std::cout << "depth : " << depth<<std::endl;

    if (isMaximizing) {
        //long long int bestScore = std::numeric_limits<int>::min();
        int bestScore = -100;
        //updates value of alfa
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Is the spot available?
                if (arrCopy[i][j] != "O" && arrCopy[i][j] != "X") {
                    string temp = arrCopy[i][j];
                    arrCopy[i][j] = computerHere;
                    int score = 0;
                    alfa = max(alfa,minimax(arrCopy, depth -1,alfa, beta, false));
                    arrCopy[i][j] = temp;
                    if (beta <= alfa) {
                        break;
                    }


                }
            }
        }
        //std::cout << "minimax, maximizing, score :" << bestScore << std::endl;
        return alfa;
    }
    else {
        //long long int bestScore = std::numeric_limits<int>::max();
        int bestScore = 100;
        //updates value of beta
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Is the spot available?
                if (arrCopy[i][j] != "O" && arrCopy[i][j] != "X") {
                    string temp = arrCopy[i][j];
                    arrCopy[i][j] = humanHere;
                    int score = 0;
                    beta = min(beta,minimax(arrCopy, depth -1,alfa,beta, true));
                    arrCopy[i][j] = temp;
                    if (beta <= alfa) {
                        break;
                    }
                    

                }
            }
        }
        //std::cout << "minimax, minimizing, score :" << bestScore << std::endl;
        return beta;
    }
}

string Ai::checkIfEndState(string arrCopy[3][3]) {

    int remaining = creatingAVectorOfTheCurrentFreeSpots(arrCopy);
    //std::cout << "remaining : " << remainingCopy << std::endl;

    if (remaining >= 0 && remaining<=5) {
        for (int i = 0; i < WINNING_ROWS; i++) {
            counterO = 0;
            counterX = 0;
            for (int j = 0; j < WINNING_COLUMNS; j++) {
                int elemFromWinningCombo = winningCombination[i][j];
                elemFromWinningCombo -= 1;
                string talalt = arrCopy[elemFromWinningCombo / 3][elemFromWinningCombo % 3];
                //std::cout << "talalt " << talalt << std::endl;
                if (talalt == "O")
                    counterO++;
                if (talalt == "X")
                    counterX++;
            }
            if (counterX == 3) {
                //std::cout << "talalt xet 3at" << std::endl;
                return "X";
            }
            else if (counterO == 3) {
                //std::cout << "talalt Oet 3at" << std::endl;
                return "O";
            }
            
        }

    }
    if (remaining > 0) {
        return "false";
    }
    else if (remaining == 0 ) {
        return "tie";
    }
    
}

int Ai::min(int elso, int masodik) {
    if (elso < masodik)
        return elso;
    else if (masodik < elso)
        return masodik;
    else
        return elso;
}
int Ai::max(int elso, int masodik) {
    if (elso > masodik)
        return elso;
    else if (masodik > elso)
        return masodik;
    else
        return elso;
}

int Ai::creatingAVectorOfTheCurrentFreeSpots(string arrCopy[3][3]) {
    int counterFreeSpots = 0;
    //freeSpotsHere.clear();
    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            if (arrCopy[i][j] != "X" && arrCopy[i][j] != "O") {
                //freeSpotsHere.push_back(std::stoi(arrCopy[i][j]));
                counterFreeSpots++;
            }
        }
    }
    return counterFreeSpots;
}

//bool Ai::checkIfThisSpotIsFree(int spot,string arr[3][3]) {
//    for (const auto& i : arr)
//        if (i == spot)
//            return true;
//    return false;
//}
