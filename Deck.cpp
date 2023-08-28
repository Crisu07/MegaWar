// Deck.cpp
#include <iostream>
#include <string>
#include <vector>
#include "Deck.h"
#include "Card.h"
using namespace std;

Deck::Deck()
{
    for (int j = 1; j < 5; j++) // for every suit, skip blank card for suit
    {
        for (int i = 0; i < 13; i++) // for every value
        {
            Card c(Card::value(i + 1), Card::su(j)); // convert to enums for rank and suit in order to make card
            add(c);
        }
    }
}

void Deck::refreshDeck() // should be the same as initializing it so paste it again
{
    int num = 0;
    for (int j = 1; j < 5; j++) // for every suit
    {
        for (int i = 0; i < 13; i++) // for every value
        {
            pile[num].setCard(Card::value(i + 1), Card::su(j));
            num++;
        }
    }
}

// refill the deck instead of refreshing
void Deck::refillDeck()
{
    for (int j = 1; j < 5; j++)
    {
        for (int i = 0; i < 13; i++)
        {
            Card c(Card::value(i + 1), Card::su(j));
            add(c);
        }
    }
}