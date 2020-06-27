#pragma once
#include "Soldier.hpp"
using namespace std;


class Paramedic : public Soldier{
public:
    Paramedic (int solider_number) :
            Soldier(100, 0, solider_number,100){}      // 100 = max_health
                                                      // 0 = caz he
                                                     // solider_number = which group
                                                    // 100 = current_health


    void playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location);
};
