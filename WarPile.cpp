// WarPile.cpp
#include "WarPile.h"
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardPile.h"
#include "Player.h"
#include "LostnFound.h"
using namespace std;

WarPile::WarPile()
{
	// create empty warpile
	warp.push_back(0);
}

// transfer cards to the winner
void WarPile::winnerpiles(Player& w)
{
	for (int i = 0; i < pile.size() ; i++)
	{
		w.add(pile[i]);
	}
	pile.clear();
}

int WarPile::doWar(Player& p)
{
	Card temp;
	p.battled(); // increase battles fought
	for (int i = 0; i < 4; i++) // deal 3 cards and return 4th card
	{
		if (p.hascards()) // if player has cards
		{
			temp = p.deal();
			pile.push_back(temp);
		}
		else // if player has no cards, return 0
		{
			return 0;
		}
	}
	return temp.getValue(); // return value of fourth card
}

// transfer cards to the lost and found pile
void WarPile::lostpiles(LostnFound& w)
{
	for (int i = 0; i < pile.size(); i++)
	{
		w.add(pile[i]);
	}
	pile.clear();
}