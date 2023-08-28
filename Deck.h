// Deck.h
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "CardPile.h"
#ifndef DECK_H
#define DECK_H
using namespace std;

class Deck :public CardPile // inherit card pile
{
public:
    Deck(); // constructor which creates 52 card deck (S, H, D, C suit order)
    void refreshDeck(); // reset the deck to look like new deck
    void refillDeck(); // refill the deck instead of resetting
};

#endif