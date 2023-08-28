// CardPile.h
#include <iostream>
#include <vector>
#include "Card.h"
#ifndef CARDPILE_H
#define CARDPILE_H
using namespace std;

class CardPile
{
protected:
	vector<Card> pile;
public:
	void add(Card);
	Card remove();
	Card deal();
	void shuffle();
	bool hascards();
	int cardsleft();
};
#endif