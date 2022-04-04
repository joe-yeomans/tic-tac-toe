#include <iostream>
#include <vector>
#include <string>
#include "functions.hpp"

int main() {
    int player = 1;
    bool is_game_over = false;
    int game = 1;
    int maximum_games = 3;
    int player_1_wins = 0;
    int player_2_wins = 0;

    reset_grid();

    while (!is_game_over) {
        print_grid();
        get_user_input(player);

        if (is_winner()) {
            if (player == 1) {
                player_1_wins++;
            }
            else {
                player_2_wins++;
            }

            if (player_1_wins == 2) {
                std::cout << "Player 1 wins!" << std::endl;
                is_game_over = true;
            }
            else if (player_2_wins == 2) {
                std::cout << "Player 2 wins!" << std::endl;
                is_game_over = true;
            }
            else {
                player = (player == 1) ? 2 : 1;

                if (player == 1) {
                    std::cout << "Player 1 wins this round!" << std::endl;
                } else {
                    std::cout << "Player 2 wins this round!" << std::endl;
                }
                show_score(player_1_wins, player_2_wins);
                reset_grid();
            }
        }
        else if (is_draw()) {
            std::cout << "It's a draw!" << std::endl;
            reset_grid();
        }
        else {
            player = (player == 1) ? 2 : 1;
        }
    }

    return 0;
}