#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>


WarGame::Board fillBoard1(){
    WarGame::Board board(10,10);

		//player 1
		board[{0,3}]= new Sniper(1);
        board[{9,1}]= new FootSoldier(1);
		board[{6,5}]= new ParamedicCommander(1);
		board[{2,5}]= new FootCommander(1);
		board[{2,1}]= new SniperCommander(1);
		board[{8,4}]= new Paramedic(1);
        //player 2
		board[{9,2}]= new FootSoldier(2);
        board[{4,0}]= new ParamedicCommander(2);        
        board[{2,4}]= new FootCommander(2);
        board[{5,3}]= new SniperCommander(2);
        board[{8,3}]= new Paramedic(2);
		board[{0,2}]= new Sniper(2);

		return board;
}

TEST_CASE("check the type"){
	WarGame::Board board=fillBoard1();
	CHECK(board.has_soldiers(1));
	CHECK(board.has_soldiers(2));

	CHECK(typeid(*board[{0,3}])==typeid(Sniper));
	CHECK(typeid(*board[{9,1}])==typeid(FootSoldier));
	CHECK(typeid(*board[{6,5}])==typeid(ParamedicCommander));
	CHECK(typeid(*board[{2,5}])==typeid(FootCommander));
	CHECK(typeid(*board[{2,1}])==typeid(SniperCommander));
	CHECK(typeid(*board[{8,4}])==typeid(Paramedic));

	CHECK(typeid(*board[{9,2}])==typeid(FootSoldier));
	CHECK(typeid(*board[{4,0}])==typeid(ParamedicCommander));
	CHECK(typeid(*board[{2,4}])==typeid(FootCommander));
	CHECK(typeid(*board[{5,3}])==typeid(SniperCommander));
	CHECK(typeid(*board[{8,3}])==typeid(Paramedic));
	CHECK(typeid(*board[{0,2}])==typeid(Sniper));

}

TEST_CASE("check the initialize"){
		WarGame :: Board board=fillBoard1();
		//sniper
		CHECK(board[{0,3}]->getHealth()==100);
		CHECK(board[{0,3}]->getDamge()==50);
		CHECK(board[{0,3}]->getNum()==1);
		CHECK(board[{0,2}]->getHealth()==100);
		CHECK(board[{0,2}]->getDamge()==50);
		CHECK(board[{0,2}]->getNum()==2);
		

		//SniperCommander
		CHECK(board[{2,1}]->getHealth()==120);
		CHECK(board[{2,1}]->getDamge()==100);
		CHECK(board[{2,1}]->getNum()==1);
		CHECK(board[{5,3}]->getHealth()==120);
		CHECK(board[{5,3}]->getDamge()==100);
		CHECK(board[{5,3}]->getNum()==2);

		//Paramedic
		CHECK(board[{8,4}]->getHealth()==100);
		CHECK(board[{8,4}]->getNum()==1);
		CHECK(board[{8,3}]->getHealth()==100);
		CHECK(board[{8,3}]->getNum()==2);

		//ParamedicCommander
		CHECK(board[{6,5}]->getHealth()==200);
		CHECK(board[{6,5}]->getNum()==1);
		CHECK(board[{4,0}]->getHealth()==200);
		CHECK(board[{4,0}]->getNum()==2);

		//FootSoldier 
		CHECK(board[{9,1}]->getHealth()==100);
		CHECK(board[{9,1}]->getDamge()==10);
		CHECK(board[{9,1}]->getNum()==1);
		CHECK(board[{9,2}]->getHealth()==100);
		CHECK(board[{9,2}]->getDamge()==10);
		CHECK(board[{9,2}]->getNum()==2);


		//FootCommander
		CHECK(board[{2,5}]->getHealth()==150);
		CHECK(board[{2,5}]->getDamge()==20);
		CHECK(board[{2,5}]->getNum()==1);
		CHECK(board[{2,4}]->getHealth()==150);
		CHECK(board[{2,4}]->getDamge()==20);
		CHECK(board[{2,4}]->getNum()==2);

}

TEST_CASE(" check throws ") {  
    WarGame::Board board = fillBoard1();
			//out of range
            CHECK_THROWS(board.move(2, {0,2}, WarGame::Board::Down));
            CHECK_THROWS(board.move(1, {0,3}, WarGame::Board::Down));
            CHECK_THROWS(board.move(2, {4,0}, WarGame::Board::Left));
            CHECK_THROWS(board.move(1, {9,1}, WarGame::Board::Up));
			CHECK_THROWS(board.move(2, {9,2}, WarGame::Board::Up));

			//there is a soldier there
			CHECK_THROWS(board.move(2, {9,2}, WarGame::Board::Left));
			CHECK_THROWS(board.move(1, {9,1}, WarGame::Board::Right));
			CHECK_THROWS(board.move(2, {0,2}, WarGame::Board::Right));
			CHECK_THROWS(board.move(1, {0,3}, WarGame::Board::Left));
			
			//wrong number player
			CHECK_THROWS(board.move(0, {9,2}, WarGame::Board::Left));
			CHECK_THROWS(board.move(0, {9,1}, WarGame::Board::Right));
			CHECK_THROWS(board.move(0, {0,2}, WarGame::Board::Right));
			CHECK_THROWS(board.move(0, {0,3}, WarGame::Board::Left));
			CHECK_THROWS(board.move(-1, {9,2}, WarGame::Board::Left));
			CHECK_THROWS(board.move(-2, {9,1}, WarGame::Board::Right));
			CHECK_THROWS(board.move(-5, {0,2}, WarGame::Board::Right));
			CHECK_THROWS(board.move(-7, {0,3}, WarGame::Board::Left));
			
			//wrong location
			CHECK_THROWS(board.move(0, {-10,2}, WarGame::Board::Right));
			CHECK_THROWS(board.move(0, {10,33}, WarGame::Board::Left));
			CHECK_THROWS(board.move(0, {-1,-1}, WarGame::Board::Left));
			CHECK_THROWS(board.move(0, {9,10}, WarGame::Board::Right));
			CHECK_THROWS(board.move(0, {10,2}, WarGame::Board::Right));
			CHECK_THROWS(board.move(0, {10,3}, WarGame::Board::Left));
			CHECK_THROWS(board.move(0, {-1,-1}, WarGame::Board::Left));
			CHECK_THROWS(board.move(0, {9,10}, WarGame::Board::Right));
			CHECK_THROWS(board.move(0, {10,2}, WarGame::Board::Right));
			CHECK_THROWS(board.move(0, {10,3}, WarGame::Board::Left));
			CHECK_THROWS(board.move(0, {-1,-1}, WarGame::Board::Left));
			CHECK_THROWS(board.move(0, {9,10}, WarGame::Board::Right));
			CHECK_THROWS(board.move(0, {10,2}, WarGame::Board::Right));
			CHECK_THROWS(board.move(0, {10,3}, WarGame::Board::Left));

}



TEST_CASE (" check attack "){
	WarGame::Board board=fillBoard1();
	//player 1
	
	board.move(1,{9,1},WarGame::Board::Left );
	CHECK(board[{9,1}]==nullptr);
	CHECK(typeid(*board[{9,0}])== typeid(FootSoldier));

	board.move(1,{6,5},WarGame::Board::Right );
	CHECK(typeid(*board[{6,6}])== typeid(ParamedicCommander));
	CHECK(board[{6,5}]==nullptr);

	CHECK(board.has_soldiers(1));
	CHECK(board.has_soldiers(2));

	board.move(1,{2,5},WarGame::Board::Down );
	CHECK(typeid(*board[{1,5}])== typeid(FootCommander));
	CHECK(board[{2,5}]==nullptr);
	
	board.move(1,{2,1},WarGame::Board::Down );
	CHECK(typeid(*board[{1,1}])== typeid(SniperCommander));
	CHECK(board[{2,1}]==nullptr);

	board.move(1,{8,4},WarGame::Board::Up );
	CHECK(typeid(*board[{9,4}])== typeid(Paramedic));
	CHECK(board[{8,4}]==nullptr);

	CHECK(board.has_soldiers(1));
	CHECK(board.has_soldiers(2));

	//player 2
	board.move(2,{9,2},WarGame::Board::Right );
	CHECK(typeid(*board[{9,3}])== typeid(FootSoldier));
	CHECK(board[{9,2}]==nullptr);

	board.move(2,{4,0},WarGame::Board::Right );
	CHECK(typeid(*board[{4,1}])== typeid(ParamedicCommander));
	CHECK(board[{4,0}]==nullptr);

	board.move(2,{2,4},WarGame::Board::Up );
	CHECK(typeid(*board[{3,4}])== typeid(FootCommander));
	CHECK(board[{2,4}]==nullptr);

	board.move(2,{5,3},WarGame::Board::Up );
	CHECK(typeid(*board[{6,3}])== typeid(SniperCommander));
	CHECK(board[{5,3}]==nullptr);

	CHECK(board.has_soldiers(1));
	CHECK(board.has_soldiers(2));

	board.move(2,{8,3},WarGame::Board::Right );
	CHECK(typeid(*board[{8,4}])== typeid(Paramedic));
	CHECK(board[{8,3}]==nullptr);
	
	board.move(2,{0,2},WarGame::Board::Up );
	CHECK(typeid(*board[{0,3}])== typeid(Sniper));
	CHECK(board[{0,2}]==nullptr);


}

