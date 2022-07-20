#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include "fn.hpp"

int main() {

    bool isDraw = false;
    bool playing = true;
    bool roundOver = false;
    std::string currentPlayer = "Player 1";

    std::vector<int> score = {0, 0};
    std::string currentMove;

    std::vector<std::string> player1;
    std::vector<std::string> player2;

    std::vector<std::vector<std::string>> board;

    start();

    while (playing) {

        board = createBoard();
        player1.clear();
        player2.clear();

        while (!roundOver) {

            printScore(score);
            printBoard(board);

            std::cout << currentPlayer << "'s Move: ";
            std::cin >> currentMove;
            std::cout << "\n";

            if (isValidMove(currentMove) && !spaceIsTaken(currentMove, player1, player2)) {
                if (currentPlayer == "Player 1") {
                    player1.push_back(currentMove);
                    board = markCoordinate("o", player1, currentMove, board);
                    roundOver = isWinner(player1);
                } else {
                    player2.push_back(currentMove);
                    board = markCoordinate("x", player2, currentMove, board);
                    roundOver = isWinner(player2);
                }

                if (!roundOver) {
                    if (player1.size() + player2.size() == 9) {
                        isDraw = true;
                        roundOver = true;
                    } else {
                        if (currentPlayer == "Player 1") {
                            currentPlayer = "Player 2";
                        } else {
                            currentPlayer = "Player 1";
                        }
                    }
                }
                
            }

        }

        if (isDraw) {
            std::cout << "It's a draw!\n\n";
            isDraw = false;
        } else {
            std::cout << currentPlayer << " wins!\n\n";

            if (currentPlayer == "Player 1") {
                score[0]++;
            } else {
                score[1]++;
            }
        }

        printScore(score);

        std::string again;

        while (again != "y" && again != "yes" && again != "n" && again != "no") {
            std::cout << "Would you like to play again? [y,n]: ";
            std::cin >> again;
        }

        if (again == "n" || again == "no") {
            playing = false;
        } else {
            roundOver = false;
            
            if (currentPlayer == "Player 1") {
                currentPlayer = "Player 2";
            } else {
                currentPlayer = "Player 1";
            }
        }

    }
}