#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Soldier{
   
    private:
    uint  current_health;
    uint  max_health_points;
    uint damage; 
    uint num_player;

   // CONSTRUCTOR
    public:
    Soldier(uint max_health,uint damage , uint num_player) :
       max_health_points(max_health), current_health(max_health) , damage(damage) , num_player(num_player) {} 

   // DESTRUCTOR -its virtual to create a vptr to delete the right solider
    virtual ~Soldier(){};
    
     // Referring to the correct attack function by the virtual(caz every solider has diffrent attack function)
    virtual void attack(vector<vector<Soldier *>> &board, pair<int, int> location) = 0;

    // getters and setters
    int getNum() { return this->num_player; }
    int getHealth(){ return this->current_health; }
    int getMaxHealth() { return this->max_health_points; }
    int getDamge() { return this->damage; }
    void setHealth(uint  health_points1) { this->current_health=health_points1; }

};
