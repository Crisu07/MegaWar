// MegaDeck.cpp
#include "MegaDeck.h"
#include <iostream>
#include <vector>
#include "Deck.h"
#include "Card.h"
#include "CardPile.h"
using namespace std;

MegaDeck::MegaDeck(int d)
{
	int n = 0;
	Deck deck1;
	while (n < d) // repeat as many times as decks needed
	{
		deck1.refillDeck();
		for (int i = 0; i < 52; i++)
		{
			add(deck1.deal()); // append top card one by one to mega deck
		}
		n++;
	}
}

// Refresh the mega deck
void MegaDeck::refreshMega()
{
	for (int i = 0; i < pile.size(); i++)
	{
		Deck deck2; // refresh deck
		while (deck2.cardsleft() > 0) // if the deck has cards left, keep appending to megadeck
		{
			pile[i] = deck2.deal();
		}
	}
}

// Display the mega deck for testing
void MegaDeck::showMega()
{
	int count = 0;
	for (int i = 0; i < pile.size(); i++)
	{
		pile[i].showCard();
		cout << " ";
		count++;

		if (count == 13)
		{
			//cout << "\b\b"; // delete last comma
			cout << endl;
			count = 0;
		}
	}
}