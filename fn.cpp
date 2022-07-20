#include <iostream>
#include <vector>

void start() {

    std::cout << "Welcome to console tic-tac-toe!\n\n";

    std::cout << "Instructions:\n";
    std::cout << "This is a two player game, to take your turn enter a co-ordinate on the board (a1, a2, a3, b1, b2, b3, c1, c2, c3). The first player to get three in a row wins the round. Ready, set, tic-tac-toe!\n\n";

}

std::vector<std::vector<std::string>> createBoard() {

    std::vector<std::vector<std::string>> board = {
        {" ", " ", "a", " ", "b", " ", "c"},
        {"1", " ", " ", "|", " ", "|", " "},
        {" ", " ", "-", "-", "-", "-", "-"},
        {"2", " ", " ", "|", " ", "|", " "},
        {" ", " ", "-", "-", "-", "-", "-"},
        {"3", " ", " ", "|", " ", "|", " "}
    };

    return board;
    
}

void printBoard(std::vector<std::vector<std::string>> board) {

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }

    std::cout << "\n";

}

void printScore(std::vector<int> score) {

    std::cout << "Score\n";
    std::cout << "=============\n";
    std::cout << "Player 1: " << score[0] << "\n";
    std::cout << "Player 2: " << score[1] << "\n\n";

}

bool isValidMove(std::string coord) {

    bool isValid = false;
    std::vector<std::string> coords = {"a1","a2","a3","b1","b2","b3","c1","c2","c3"};

    for (int i = 0; i < coords.size(); i++) {
        if (coords[i] == coord) {
            isValid = true;
            break;
        }
    }

    if (!isValid) {
        std::cout << "Space isn't valid. Please select a valid space.";
    }

    return isValid;

}

bool spaceIsTaken(std::string coord, std::vector<std::string> player1, std::vector<std::string> player2) {

    bool isTaken = false;

    for (int i = 0; i < player1.size(); i++) {
        if (player1[i] == coord || (i < player2.size() && player2[i] == coord)) {
            isTaken = true;
            std::cout << "Space is already taken, choose another.\n\n";
            break;
        }
    }

    return isTaken;

}

std::vector<std::vector<std::string>> markCoordinate(std::string mark, std::vector<std::string> player, std::string coord, std::vector<std::vector<std::string>> board) {

    if (coord == "a1") {
        board[1][2] = mark;
    } else if (coord == "b1") {
        board[1][4] = mark;
    } else if (coord == "c1") {
        board[1][6] = mark;
    } else if (coord == "a2") {
        board[3][2] = mark;
    } else if (coord == "b2") {
        board[3][4] = mark;
    } else if (coord == "c2") {
        board[3][6] = mark;
    } else if (coord == "a3") {
        board[5][2] = mark;
    } else if (coord == "b3") {
        board[5][4] = mark;
    } else if (coord == "c3") {
        board[5][6] = mark;
    }

    return board;

}

bool isWinner(std::vector<std::string> player) {

    bool isWinner = false;

    if (player.size() > 2) {
        std::vector<std::vector<std::string>> winningCombinations = {
            {"a1", "b1", "c1"},
            {"a2", "b2", "c2"},
            {"a3", "b3", "c3"},
            {"a1", "a2", "a3"},
            {"b1", "b2", "b3"},
            {"c1", "c2", "c3"},
            {"a1", "b2", "c3"},
            {"a3", "b2", "c1"}
        };

        std::vector<bool> matches;

        for (int i = 0; i < winningCombinations.size(); i++) {
            matches = {false, false, false};
            for (int j = 0; j < winningCombinations[i].size(); j++) {
                for (int k = 0; k < player.size(); k++) {
                    if (winningCombinations[i][j] == player[k]) {
                        matches[j] = true;
                    }
                }
            }

            if (matches[0] && matches[1] && matches[2]) {
                isWinner = true;
                break;
            }
        }
    }

    return isWinner;

}

