// LostnFound.cpp (lost and found pile)
// if both (or all players) cannot continue a war, they all lose and the war card pile goes into lost and found
// next time there is a war, the winner receives the cards from the lost and found pile
#include "LostnFound.h"
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardPile.h"
#include "Player.h"
//#include "WarPile.h"
using namespace std;

LostnFound::LostnFound()
{
	lostp.push_back(0);
}

// transfer lost and found pile to the winner
void LostnFound::givewin(Player& w)
{
	for (int i = 0; i < pile.size(); i++)
	{
		w.add(pile[i]);
	}
	pile.clear();
}