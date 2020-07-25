#include "FootSoldier.hpp"
#include "math.h"

void FootSoldier::attack(vector<vector<Soldier *>> &board, pair<int, int> dest) {// dest is the new position of the solider(he moved at "move" function) 
    
    double closest=board.size()*board.size();
    int s_i,s_j;
    int found =0;
    
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board.size();j++) {
            Soldier *s = board[i][j];
            
            // if there is solider in point (i, j) and its solider from the other group so-
            if(s!=nullptr && (s->getNum() != board[dest.first][dest.second]->getNum())) { 
                
                // Calculation distance from point (i, j) to dest (the point where the soldier is located)
                double dist = sqrt((i-dest.first)*(i-dest.first) + (j-dest.second)*(j-dest.second)); // distance= sqrt[(x1-x2)^2+(y1-y2)^2]
                if(dist<closest)
                {
                    closest =dist; // update closest caz we found smaller distance
                    s_i = i; // s_i is the num row of closest solider 
                    s_j = j; // s_j is the num col of closest solider
                    found = 1;
                }
            }
        }
    }

    if(found){ // we found the closest solider
        
        Soldier *s = board[s_i][s_j];
        int health_s = s->getHealth() - board[dest.first][dest.second]->getDamge(); // solider in dest point shoot on s(the closest solider)
        if(health_s <= 0) { board[s_i][s_j] = nullptr; } // dead
        else { s->setHealth(health_s); }
    }
}

