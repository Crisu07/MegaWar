// MegaDeck.h
#include <iostream>
#include <vector>
#include "Deck.h"
#include "Card.h"
#include "CardPile.h"
#ifndef MEGADECK_H
#define MEGADECK_H
using namespace std;

class MegaDeck: public CardPile
{
public:
	MegaDeck(int d); // how many decks to use
	void refreshMega();
	void showMega();
};

#endif