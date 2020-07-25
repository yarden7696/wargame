#pragma once
#include "Soldier.hpp"


const int max_health_point_paramedic = 100;
const int Damage_para = 50;

class Paramedic : public  Soldier {

public:
  
//CONSTRUCTORS
Paramedic(uint num_p) : Soldier(max_health_point_paramedic , Damage_para , num_p){}
Paramedic(uint max_health_point , uint damage , uint num_p) : Soldier(max_health_point , damage , num_p){}

void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
