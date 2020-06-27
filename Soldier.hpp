#pragma once
#include <math.h>
#include <vector>

class Board;

using namespace std;


class Soldier {

    private:
        uint max_health;
        uint demage;
        uint player_number;
        uint current_health;

    public:
    Soldier (uint max_health, uint demage, uint player_number, uint current_health) :
        max_health(max_health),
        demage(demage),
        player_number(player_number),
        current_health(current_health){}

        virtual ~Soldier() {}

        double distance (int x1, int y1, int x2, int y2) {
            return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
        }

        virtual void playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location) = 0;

        int get_current_health() {
            return this->current_health;
        }

        int get_max_health() {
            return this->max_health;
        }

        int get_demage() {
            return this->demage;
        }

        void set_demage(int demage) {
            this->demage = demage;
        }

        void set_max_health(int max_health) {
            this->max_health = max_health;
        }

        void set_current_health(int current_health) {
            this->current_health = current_health;
        }

        void set_player_number(int player_number) {
            this->player_number = player_number;
        }

        int get_player_number() {
            return this->player_number;
        }


};

