// LostnFound.h
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardPile.h"
#include "Player.h"
#ifndef LOSTNFOUND_H
#define LOSTNFOUND_H
using namespace std;

class LostnFound: public CardPile
{
private:
	vector<int> lostp;
public:
	LostnFound();
	void givewin(Player& w); // give lost and found pile to winner
};

#endif