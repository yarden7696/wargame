#include "Paramedic.hpp"



// חובש - יכול ללכת משבצת אחת לכל כיוון. לא יורה בכלל, אלא רק מרפא את כל החיילים של אותו שחקן שנמצאים במשבצת לידו 
// .(מחזיר את מספר נקודות-הבריאות שלהם למספר ההתחלתי)


    void Paramedic :: attack(vector<vector<Soldier *>> &board, pair<int, int> location) {
        
       Soldier *paramedic = board[location.first][location.second]; // the paramedic(in location position) who needs to cure soliders next to him in 
       int i=location.first; // row num of paramedic
       int j=location.second; // col num of paramedic
        
       // DOWN CASE
       if ( i-1 >= 0 && board[i-1][j] != nullptr ) { // if line >= 0  and if there is somone in board[i-1][j]-   
           if (board[i-1][j]->getNum() == paramedic->getNum() ){ // if they in the same group, so-
               board[i-1][j]->setHealth(board[i-1][j]->getMaxHealth()); // the paramedic cure the solider in board[i-1][j] position
           }
       }
        
       // UP CASE
       if (i+1 <board.size() && board[i+1][j] != nullptr ){//if line<board.length and if there is somone in board[i+1][j]-   
           if ( board[i+1][j]->getNum() == paramedic->getNum() ){ // if they in the same group, so-
               board[i+1][j]->setHealth(board[i+1][j]->getMaxHealth()); // the paramedic cure the solider in board[i+1][j] position
           }
       }
        
       // LEFT CASE
        if (j-1 >= 0 && board[i][j-1] != nullptr ){// if col>=0 and there is somone in board[i][j-1]-
           if ( board[i][j-1]->getNum() == paramedic->getNum() ){ // if they in the same group, so-
               board[i][j-1]->setHealth(board[i][j-1]->getMaxHealth()); // the paramedic cure the solider in board[i][j-1] position
           }
       }
        
       // RIGHT CASE
       if (j+1< board[0].size() && board[i][j+1] != nullptr ){ // if col<board[0].length and there is somone in board[i][j+1]
           if ( board[i][j+1]->getNum() == paramedic->getNum() ){ // if they in the same group, so-
               board[i][j+1]->setHealth(board[i][j+1]->getMaxHealth()); // the paramedic cure the solider in board[i][j+1] position
           }
       }
        
        // DOWN and LEFT CASE
        if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] != nullptr ){ // if line >= 0(DOWN) and col>=0(LEFT) and there is somone in board[i-1][j-1]  
           if ( board[i-1][j-1]->getNum() == paramedic->getNum() ){ // if they in the same group, so-
               board[i-1][j-1]->setHealth(board[i-1][j-1]->getMaxHealth()); // the paramedic cure the solider in board[i-1][j-1] position
           }
       }
        
        // DOWN and RIGHT CASE
       if (i-1 >= 0 && j+1< board[0].size() && board[i-1][j+1] != nullptr ){//if line >= 0(DOWN) and col<board[0].length(RIGHT) and there is somone in board[i-1][j+1] 
           if ( board[i-1][j+1]->getNum() == paramedic->getNum() ){ // if they in the same group, so-
               board[i-1][j+1]->setHealth(board[i-1][j+1]->getMaxHealth()) // the paramedic cure the solider in board[i-1][j+1] position
           }
       }
        
       // UP and LEFT CASE
        if (i+1 <board.size() && j-1 >= 0 && board[i+1][j-1] != nullptr ){//if line<board.length(UP) and col>=0(LEFT) and there is somone in board[i+1][j-1] 
           if ( board[i+1][j-1]->getNum() == paramedic->getNum() ){ // if they in the same group, so-
               board[i+1][j-1]->setHealth(board[i+1][j-1]->getMaxHealth()); // the paramedic cure the solider in board[i+1][j-1] position
           }
       }
        
       // UP and RIGHT CASE
        if (i+1 <board.size() && j+1< board[0].size() && board[i+1][j+1] != nullptr ){//if line<board.length(UP) and col<board[0].length(RIGHT) and there is somone in board[i+1][j+1] 
           if ( board[i+1][j+1]->getNum() == paramedic->getNum() ){ // if they in the same group, so-
               board[i+1][j+1]->setHealth(board[i+1][j+1]->getMaxHealth()); // the paramedic cure the solider in board[i+1][j+1] position
           }
       }
    }
