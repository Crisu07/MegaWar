// CardPile.cpp
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardPile.h"
using namespace std;

// add card to pile
void CardPile::add(Card c)
{
	pile.push_back(c);
}

// remove card from pile
Card CardPile::remove()
{
	//pile.erase(pile.begin()); // should always removes the top or first card of the pile anyways
	Card temp = pile[pile.size() - 1];
	pile.pop_back();
	return temp;
}

// deal top card of pile
Card CardPile::deal()
{
	return remove();
}

// shuffle the cards within the pile
void CardPile::shuffle()
{
	srand(time(NULL)); // ensures random values are different each time
	for (int i = 0; i < 628; i++) // swap two indexes multiple times to shuffle
	{
		int x = rand() % 52; // random index in deck
		int y = rand() % 52; // another random index

		Card z = pile[x];
		pile[x] = pile[y];
		pile[y] = z;
	}
}

// If the player has cards left in their hand
bool CardPile::hascards()
{
	bool check;
	if (pile.empty())
	{
		check = false;;
	}
	else
	{
		check = true;
	}
	return check;
}

// Determine amount of cards left 
int CardPile::cardsleft()
{
	return pile.size();
}