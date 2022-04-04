#include <iostream>
#include <vector>
#include <string>

std::vector<char> board;
const char empty_space = '_';
const char player_1 = 'x';
const char player_2 = 'o';

void reset_grid() {
    board.clear();
    for (int i = 0; i < 9; i++) {
        board.push_back(empty_space);
    }
}

void print_grid() {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
}

bool is_winner() {
    //vertical check
    if (board[0] != empty_space && board[3] != empty_space && board[6] != empty_space) {
        if (board[0] == board[3] && board[3] == board[6]) {
            return true;
        }
    } else if (board[1] != empty_space && board[4] != empty_space && board[7] != empty_space) {
        if (board[1] == board[4] && board[4] == board[7]) {
            return true;
        }
    } else if (board[2] != empty_space && board[5] != empty_space && board[8] != empty_space) {
        if (board[2] == board[5] && board[5] == board[8]) {
            return true;
        }
    }

    //horizontal check
    if (board[0] != empty_space && board[1] != empty_space && board[2] != empty_space) {
        if (board[0] == board[1] && board[1] == board[2]) {
            return true;
        }
    } else if (board[3] != empty_space && board[4] != empty_space && board[5] != empty_space) {
        if (board[3] == board[4] && board[4] == board[5]) {
            return true;
        }
    } else if (board[6] != empty_space && board[7] != empty_space && board[8] != empty_space) {
        if (board[6] == board[7] && board[7] == board[8]) {
            return true;
        }
    }

    //diagonal check
    if (board[0] != empty_space && board[4] != empty_space && board[8] != empty_space) {
        if (board[0] == board[4] && board[4] == board[8]) {
            return true;
        }
    } else if (board[2] != empty_space && board[4] != empty_space && board[6] != empty_space) {
        if (board[2] == board[4] && board[4] == board[6]) {
            return true;
        }
    }

    return false;
}

void get_user_input(int player) {
    std::string input;
    if (player == 1) {
        std::cout << "Player 1, enter a number between 1 and 9: ";
    } else {
        std::cout << "Player 2, enter a number between 1 and 9: ";
    }
    std::cin >> input;
    int position = std::stoi(input);
    if (position < 1 || position > 9) {
        std::cout << "Invalid input" << std::endl;
        get_user_input(player);
    }
    else {
        if (board[position - 1] == empty_space) {
            if (player == 1) {
                board[position - 1] = 'x';
            } else {
                board[position - 1] = player_2;
            }
        }
        else {
            std::cout << "Invalid input" << std::endl;
            get_user_input(player);
        }
    }
}

void show_score(int player_1_wins, int player_2_wins) {
    std::cout << "Player 1 wins: " << player_1_wins << std::endl;
    std::cout << "Player 2 wins: " << player_2_wins << std::endl;
}

bool is_draw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == empty_space) {
            return false;
        }
    }
    return true;
}