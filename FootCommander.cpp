#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include <iostream>

#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include <iostream>

void FootCommander::playS(vector<vector<Soldier*>> &b, pair<int,int> location) { // location is the new position of the solider
    
    int nRow = b.size();
    int nCol = b[0].size();
    
    pair < double, Soldier * > nextStep = make_pair(distance(0, 0, nRow - 1, nCol - 1) + 1, nullptr); //nullptr will be a enemy with the min distance  
    
    for (int i = 0; i < nRow; ++i) {
        for (int j = 0; j < nCol; ++j) {
            Soldier *soli = b[i][j];
               if (soli != nullptr) { //if there is some solider in this position on the board so-
                  if (FootSoldier* soliP=dynamic_cast<FootSoldier*>(soli)){ // if soli is FootCommander also so he need to shoot to
                       if (soli->get_player_number() == this->get_player_number())
                         soliP->playS(b, {i, j});
                }
              }
                // if soli and this are from 2 different groups so:
                else if (soli->get_player_number() != this->get_player_number()) {
                    double dist = distance(location.first, location.second, i, j); // distance from this to soli
                    if (dist < nextStep.first) {
                        nextStep.first = dist; // check the min distance
                        nextStep.second = soli; // set the pointer to the enemy with the minimum distance
                    }
                }
            }
        }
    }

int reHealth = nextStep.second->get_current_health() + this->get_demage(); //reHealth the health of enemy After he was hit
if(reHealth <= 0) {
delete nextStep.second; // solider dead
nextStep.second = nullptr;
}
else  nextStep.second->set_current_health(reHealth); // update its current health
}
