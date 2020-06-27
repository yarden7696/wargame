#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"

void ParamedicCommander::playS(std::vector<std::vector<Soldier *>> &b, pair<int, int> location) {
    int i=location.first;
    int j= location.second;

    if( i>0 && b[i-1][j] != nullptr){
        if(b[i-1][j]->get_player_number()== this->get_player_number() )
            b[i-1][j]->set_current_health(b[i-1][j]->get_max_health());
    }

    if( j<b[0].size()-1 && b[i][j+1] != nullptr){
        if(b[i][j+1]->get_player_number()== this->get_player_number() )
            b[i][j+1]->set_current_health(b[i][j+1]->get_max_health());
    }
    if(j>0 && b[i][j-1] != nullptr){
        if(b[i][j-1]->get_player_number()== this->get_player_number() )
            b[i][j-1]->set_current_health(b[i][j-1]->get_max_health());
    }
    if(i<b[0].size()-1 && b[i+1][j] != nullptr){
        if(b[i+1][j]->get_player_number()== this->get_player_number() )
            b[i+1][j]->set_current_health(b[i+1][j]->get_max_health());
    }

    int row = b.size();
    int col = b[0].size();
    for(int i= 0; i<row; ++i){
        for(int j= 0; j<col; ++j){
            Soldier* s = b[i][j];
            if(s != nullptr) {
                if(s->get_player_number() == this->get_player_number()){
                    if(Paramedic* ps=dynamic_cast<Paramedic*>(s)){
                        ps->playS(b, {i,j});
                    }
                }
            }
        }
    }
}



