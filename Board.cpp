#include "Board.hpp"
#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

namespace WarGame {

        // operator for putting soldiers on the game-board during initialization. like: board[{i,j}]
         Soldier*& Board :: operator[](std::pair<int,int> location){
             return board[location.first][location.second];
        }

        // operator for reading which soldiers are on the game-board. like: board[{i,j}]
        Soldier* Board:: operator[](std::pair<int,int> location) const{
            return  board[location.first][location.second];
        }

        //move the soldier of player_number from the "source" location to the "target" location(Right,Left,Up,Down)
        void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
                //checking limits
                if(source.first>=board.size() || source.second>=board.size()){
                    throw invalid_argument("invaild location"); // source position is out of the board(i>board.len || j>board[0].len) 
                 }
                Soldier *src = board[source.first][source.second]; //src is the solider in position source
                if(src == nullptr) { // if there is no solider in source position so-
                    throw invalid_argument(" There is no player on source  position ");
                }
                if(src->getNum() != player_number) { // soldier in the source location belongs to the other player
                    throw invalid_argument(" soldier in the source location belongs to the other player ");
                }
 
                pair<int,int> dest; // dest is the new position of the solider
                switch(direction) { // direction could be one pf this options: Right,Left,Up,Down
                    case Up :
                    dest = make_pair(source.first+1,source.second);
                    break;
                    case Down :
                    dest = make_pair(source.first-1,source.second);
                    break;
                    case Right : 
                    dest = make_pair(source.first,source.second+1);
                    break;
                    case Left :
                    dest = make_pair(source.first,source.second-1);
                    break;

                }
                
                // dest position is out of the board( (i>=board.len) || (i<0) || (j>=board[0].len) || (j<0) ) 
                if(dest.first < 0 || dest.second < 0 || dest.first >= board.size() || dest.second >= board[dest.first].size()){
                    throw invalid_argument(" dest position is out of the board "); 
                }
                
                //if there is a solider in dest position
                if(board[dest.first][dest.second] != nullptr){
                    throw invalid_argument(" There is already another soldier in the this dest "); 
                }

                // else- dest is good
                board[dest.first][dest.second] = src; // put src soledre in dest position 
                board[source.first][source.second]= nullptr; // remove src solider from source position 
                src->attack(board,dest); // the solider moved to his new dest and now he can attack and shot 
            }


        // returns true if the player has an soldiers on the board
         bool Board::has_soldiers(uint player_number) const {
            int count=0;
             for(int i=0; i<board.size(); i++){
                 for(int j=0; j<board[i].size(); j++){
                     Soldier* s= board[i][j];
                     if (s!=nullptr){
                        if( s->getNum()==player_number){ // we found solider in the same group
                            return true;
                        }
                     }
                 }
             }
             return false; // we did not found solider in the same group
         }
}
