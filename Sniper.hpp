#pragma once
#include "Soldier.hpp"

const int max_health_sniper = 100;
const int Damage_snipe = 50;

class Sniper : public  Soldier {

public:
  
// CONSTRUCTORS
Sniper(uint num_p) : Soldier(max_health_sniper , Damage_snipe , num_p) {}
Sniper(uint max_health_point , uint damage , uint num_p) : Soldier(max_health_point , damage , num_p){}

void attack(vector<vector<Soldier *>> &board, pair<int, int> location);
};

