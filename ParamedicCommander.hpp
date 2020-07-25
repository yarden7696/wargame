#pragma once
#include "Paramedic.hpp"

using namespace std;


const int max_health_point_paracom = 200;
const int Damage_paracom = 100;

class ParamedicCommander : public  Paramedic {

public:

ParamedicCommander(uint num_p) : Paramedic(max_health_point_paracom , Damage_paracom , num_p){}
/*pass through the board and call every paramedic in the board that in the same player*/
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
