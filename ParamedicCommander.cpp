#include "ParamedicCommander.hpp"

using namespace std;


// .כמו חובש, אבל כשהוא זז, כל החובשים של אותו שחקן מרפאים את החיילים שנמצאים לידם

    void ParamedicCommander :: attack(vector<vector<Soldier *>> &board, pair<int, int> location) {
        
       Soldier *prmdComndr_src = board[location.first][location.second]; // the ParamedicCommander (that need to shoot) in location position
       int i=location.first;
       int j=location.second;
        
      for (int i = 0; i < board.size(); i++) {
          for (int j = 0; j < board[0].size(); j++) {
              
                 Soldier *s_temp = board[i][j]; // create solider in (i,j) position  
                 if(s_temp != nullptr) { // if (i,j) position!= nullptr so- 
                 if(Paramedic *pemdc = dynamic_cast<Paramedic*> (s_temp)) { //check if s_temp from type Paramedic, is true we do casting 
                        // that s_temp pointer with type Paramedic
                     
                     ParamedicCommander *prmdComndr_temp = dynamic_cast<ParamedicCommander*> (s_temp); //check if s_temp from type ParamedicCommander, 
                       // if false we get nullptr, else- we do casting that s_temp pointer with type ParamedicCommander(we wont false)
                     
                     if (prmdComndr_temp == nullptr || ( i == location.first && j == location.second)) { // if we found prmdComndr_src position or prmdComndr_temp == nullptr                     
                        if (pemdc->getNum() == prmdComndr_src->getNum()) { // if they in the same group, so-
                           if (pemdc != nullptr){ // thats mean its Paramedic there
                               pemdc->Paramedic::attack(board , {i,j}); // now pemdc cure caz he is Paramedic
                                
                            }
                          }
                        }
                      }     
                    }
                  }
                }
              }


