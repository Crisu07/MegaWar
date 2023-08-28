// Card.h
#include <string>
#include <iostream>
#ifndef CARD_H
#define CARD_H
using namespace std;

class Card
{
public:
    // Enums for card rank and suit
    enum value { BLANK, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum su { BLANK2, SPADE, HEART, DIAMOND, CLUB };
    Card(); // create blank card
    Card(value r, su s); // constructor to create a card, with rank and suit
    void setCard(value r, su s); // set value to existing blank card
    int getValue(); // return the point value of the card (ace=1, face=10)
    void showCard(); // display card - Ace of Spades would be AS
private:
    value rank;
    su suit;
};
#endif

