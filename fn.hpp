#include <iostream>
#include <vector>

void start();

std::vector<std::vector<std::string>> createBoard();

void printBoard(std::vector<std::vector<std::string>> board);

void printScore(std::vector<int> score);

bool isValidMove(std::string coord);

bool spaceIsTaken(std::string coord, std::vector<std::string> player1, std::vector<std::string> player2);

std::vector<std::vector<std::string>> markCoordinate(std::string mark, std::vector<std::string> player, std::string coord, std::vector<std::vector<std::string>> board);

bool isWinner(std::vector<std::string> player);