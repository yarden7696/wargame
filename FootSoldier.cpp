
#include "FootSoldier.hpp"
 
                                                                    //location is the current position of the soldier
void FootSoldier::playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location) {

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            int health = board[i][j]->get_current_health(); 
            if ((board[i][j] != nullptr) && (board[location.first][location.second]->get_player_number() != board[i][j]->get_player_number())) //dis <= 1
                board[i][j]->set_current_health(health + board[location.first][location.second]->get_demage());
            if (health + board[location.first][location.second]->get_demage() <= 0) delete board[i][j];
        }
    }
}


