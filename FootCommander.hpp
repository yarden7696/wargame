#pragma once
#include "Soldier.hpp"

using namespace std;

class FootCommander : public Soldier {
public:
    FootCommander (int solider_number) :
            Soldier(150, -20, solider_number,150){}    // 150 = max_health
                                                      // -20 = demage
                                                     // solider_number = which group
                                                    // 150 = current_health


     void playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location);

};



