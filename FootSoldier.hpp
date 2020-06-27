#pragma once
#include "Soldier.hpp"
using namespace std;

class FootSoldier : public Soldier {
    public:
    FootSoldier (int solider_number) :
            Soldier(100, -10, solider_number,100){}    // 100 = max_health
                                                      // -10 = demage
                                                     // solider_number = which group
                                                    // 100 = current_health

        void playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location);

};



