#include "SniperCommander.hpp"

using namespace std;

// .כמו צלף, אבל כשהוא זז, לא רק הוא יורה אלא כל הצלפים של אותו שחקן יורים

 void SniperCommander::attack(vector<vector<Soldier*>> &board,pair<int,int> dest) {
  
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
         
            Soldier *if_snifer = board[i][j]; // craete solider in board[i][j] position
            if(if_snifer!=nullptr) { // if this position!= nullptr, so- 
                if(Sniper *is_sniff = dynamic_cast<Sniper*> (if_snifer)) { // if the pointer type of if_snifer is " *sniffer ", so-
                 
                    SniperCommander *if_commSniff = dynamic_cast<SniperCommander*> (if_snifer); // trying to casting from pointer type *sniffer
                    // to pointer type *SniperCommander. if dont succeeded we get nullptr  
                    
                    if((if_commSniff == nullptr) || (i == dest.first && j==dest.second)) { 
                        if(is_sniff->getNum() == board[dest.first][dest.second]->getNum()){ // if they in the same group, so-
                            is_sniff->Sniper::attack(board,make_pair(i,j)); // now is_sniff can attack caz he is Sniper
                        
                          }
                      }     
                  }
              }
          }
      }
  }
