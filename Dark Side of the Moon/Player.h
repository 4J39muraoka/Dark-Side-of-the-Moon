#pragma once

#include "memory"
#include "Card.h"

#define NUMBER_IN_FEILD 3
#define NUMBER_IN_HAND 12

using namespace std;

class Player{
public:
//	unique_ptr<Card> gardian_area[NUMBER_IN_FEILD];
//	unique_ptr<Card> player_area[NUMBER_IN_FEILD];

	bool open_gardian[NUMBER_IN_FEILD] = {0, 0, 0};
	bool open_player[NUMBER_IN_FEILD] = {0, 0, 0};

	Player();
	~Player();

	void setDeck();
	void initPlayer();

protected:
private:
//	unique_ptr<Card> hand[NUMBER_IN_HAND];
//	unique_ptr<Card> cemetery;
};

