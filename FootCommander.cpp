#include "FootCommander.hpp"

using namespace std;

// כמו רגלי, אבל כשהוא זז, לא רק הוא יורה אלא כל החיילים *הרגלים* של אותו שחקן יורים.

    void FootCommander :: attack(vector<vector<Soldier *>> &board, pair<int, int> location) {
        
       Soldier *s_src = board[location.first][location.second]; // the FootCommander (that need to shoot) in location position 
       int i=location.first; //?
       int j=location.second; //?
      for (int i = 0; i < board.size(); i++) {
          for (int j = 0; j < board[0].size(); j++) {
              
                 Soldier *s_temp = board[i][j]; // create solider in (i,j) position 
                 if(s_temp != nullptr) { // if (i,j) position!= nullptr so- 
                    if( FootSoldier *fsoli = dynamic_cast<FootSoldier*> (s_temp)){ //check if s_temp from type footsolider, is true we do casting 
                        // that s_temp pointer with type FootSoldier
                        
                        FootCommander *footcom = dynamic_cast<FootCommander*> (s_temp); //check if s_temp from type FootCommander, is false we
                       // get nullptr, else- we do casting that s_temp pointer with type FootCommander(we wont false)
                        
                        if (footcom == nullptr || ( i == location.first && j == location.second)) { // if we found s_src position or footcom == nullptr                  
                            if ( fsoli->getNum() == s_src->getNum()){ // if they in the same group, so-
                                if ( fsoli != nullptr){ // thats mean its footsoldier there
                                    fsoli->FootSoldier::attack(board , {i,j}); // now fsoli attack caz he is FootSoldier
                                }
                            }
                        }
                    }
                }
            }
        }
    }


