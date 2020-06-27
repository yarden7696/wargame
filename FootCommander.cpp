#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include <iostream>

#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include <iostream>

void FootCommander::playS(vector<vector<Soldier*>> &b, pair<int,int> location) { // location is the solider position
    int nRow = b.size();
    int nCol = b[0].size();
    pair < double, Soldier * > nextStep = make_pair(distance(0, 0, nRow - 1, nCol - 1) + 1, nullptr);
    for (int i = 0; i < nRow; ++i) {
        for (int j = 0; j < nCol; ++j) {
            Soldier *soli = b[i][j];
            if (soli != nullptr) { //if there is some solider in this position on the board so-
                if (FootSoldier* soliP=dynamic_cast<FootSoldier*>(soli)){ //&& (soli->get_player_number() == player_number)
                    soliP->playS(b, {i, j});
                }
                else if (soli->get_player_number() != this->get_player_number()) {
                    double dist = distance(location.first, location.second, i, j);
                    if (dist < nextStep.first) {
                        nextStep.first = dist;
                        nextStep.second = soli;
                    }
                }
            }
        }
    }

int reHealth = nextStep.second->get_current_health() + this->get_demage();
if(reHealth <= 0) {
delete nextStep.second;
nextStep.second = nullptr;
}
else  nextStep.second->set_current_health(reHealth);
// לשים לב שהחייל לא זז משבצת
}