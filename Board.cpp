#include "Board.hpp"
#include <iostream>
using namespace std;

namespace WarGame {

    Soldier *&Board::operator[](pair<int, int> location) {
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](pair<int, int> location) const {
        return board[location.first][location.second];
    }



    void Board::move(uint player_number, pair<int, int> source, MoveDIR direction) {
        if(source.first<0 || source.first>=board.size() || source.second>=board[source.first].size() || source.second<0) {
            throw invalid_argument("out of board");
        }

        Soldier* s = (*this)[source];
        std::pair<int,int> dst;

        if(dst.first<0 || dst.first>=board.size() || dst.second>=board[dst.first].size() || dst.second<0) {
            throw invalid_argument("out of range");
        }

        else if(s == nullptr || s->get_player_number()!=player_number || (*this)[dst]!= nullptr){
            throw invalid_argument("Not Allowed");
        }
    }



    bool Board::has_soldiers(uint player_number) const {
        for(int i= 0; i< board.size(); ++i){
            for(int j=0; j< board[i].size(); ++j) {
                Soldier* s = (*this)[{i, j}];
                if (s != nullptr && s->get_player_number() == player_number)
                    return true;
            }
        }
        return false;
    }

}



