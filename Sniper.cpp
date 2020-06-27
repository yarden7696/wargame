#include "Sniper.hpp"


void Sniper::playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            //double dis = distance(location.first, location.second, i, j);
            int health = board[i][j]->get_current_health();
            if ((board[i][j] != nullptr) && (board[location.first][location.second]->get_player_number() != board[i][j]->get_player_number())) //dis <= 1
                board[i][j]->set_current_health(health + board[location.first][location.second]->get_demage());
            if (health + board[location.first][location.second]->get_demage() <= 0) delete board[i][j];
        }
    }
}



//    int max_health = 0;
//
//    for (int i = 0; i < board.size(); ++i) {
//        for (int j = 0; j < board[0].size(); ++j) {
//            int health = board[i][j]->get_current_health();
//            if (health > max_health) {
//                max_health = health;
//                Solider player = board[i][j];
//            }
//                if ((player != nullptr) && (this->get_player_number() != player->get_player_number()))
//                    player->set_current_health(health + this->get_demage());
//                if (health + this->get_demage() <= 0) delete player;
//            }
//
//    }
//}