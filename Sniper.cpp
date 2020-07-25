#include "Sniper.hpp"
#include "math.h"

using namespace std;


//  צלף - יכול ללכת משבצת אחת לכל כיוון. יורה על החייל החזק ביותר של האויב - זה שיש לו הכי הרבה נקודות בריאות 
// .(אם יש כמה - הוא בוחר אחד מהם שרירותית)

    void Sniper :: attack(vector<vector<Soldier *>> &board, pair<int, int> location) { 
        
       int num_player_src = board[location.first][location.second]->getNum(); // Sniper player number
            int max_health=0;
            Soldier *attack_him = nullptr; 
            int i_max=0;
            int j_max=0;
        
            for(int i=0;i<board.size();i++) {
                for(int j=0;j<board[0].size();j++) {
                    if(board[i][j]!=nullptr) {
                        if(board[i][j]->getNum()!=num_player_src) { // player from different group 
                            if(board[i][j]->getHealth()>max_health) { // if the solider in board[i][j] has more health that the other so- 
                                attack_him=board[i][j]; // update the new solider with the higher health
                                max_health=board[i][j]->getHealth(); // save his current health
                                i_max=i; // save his row num 
                                j_max=j; // save his col num 
                            }
                        }
                    }    
                }
            }
        
       if (attack_him != nullptr) {
            int damage = board[location.first][location.second]->getDamge(); // save the number of points that "attack_him" solider is going to lose 
            int new_health = attack_him->getHealth() - damage; // attack him
            if(new_health <= 0) { // "attack_him" solider is dead
                board[i_max][j_max]=nullptr;
            }
            else { attack_him->setHealth(new_health); } // just hurt
        }  
    }  
    
