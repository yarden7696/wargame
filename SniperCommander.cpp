#include "SniperCommander.hpp"
#include <iostream>
#include "Sniper.hpp"


void SniperCommander::playS(vector<vector<Soldier*>> &b, pair<int,int> location) {
    int nRow = b.size();
    int nCol = b[0].size();
    pair < double, Soldier * > nextStep = make_pair(MAXFLOAT, nullptr);
    for (int i = 0; i < nRow; ++i) {
        for (int j = 0; j < nCol; ++j) {
            Soldier *soli = b[i][j];
            if (soli != nullptr) { //if there is some solider in this position on the board so-
                if (Sniper * soliP = dynamic_cast<Sniper *>(soli)) { //soli->get_player_number() == this->get_player_number()
                    soliP->playS(b, {i, j});
                } else if (soli->get_player_number() != this->get_player_number()) { // We found an enemy soldier
                    double findS = soli->get_max_health(); // now we want to find the largest health
                    if (soli->get_current_health() == MAXFLOAT) {
                        nextStep.first = findS;
                        nextStep.second = soli;
                    } //else if (soli->get_current_health() > playS.first) {
//                        nextStep.first = findS;
//                        nextStep.second = soli;
//                    }
                }
            }
        }
    }
    int reHealth = nextStep.second->get_current_health() + this->get_demage();
    if (reHealth <= 0) {
        delete nextStep.second;
        nextStep.second = nullptr;
    }
    else nextStep.second->set_current_health(reHealth);
}





