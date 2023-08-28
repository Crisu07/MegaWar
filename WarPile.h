// WarPile.h
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardPile.h"
#include "Player.h"
#include "LostnFound.h"
#ifndef WARPILE_H
#define WARPILE_H
using namespace std;

class WarPile: public CardPile
{
private:
	vector<int> warp;
public:
	WarPile();
	void winnerpiles(Player& w); // transfer the war pile to the winner
	int doWar(Player& p);
	void lostpiles(LostnFound& w); // transfer the war pile to the lost and found
};

#endif