// Player.cpp
#include <iostream>
#include <vector>
#include "CardPile.h"
#include "Player.h"
using namespace std;

// Default constructor
Player::Player()
{
	fierce = 0.0;
	battles = 0;
	victories = 0;
}

// Return amount of cards player has left in hand
int Player::getCards()
{
	return pile.size();
}

// return fierceness of the player's hand
double Player::getFierce()
{
	// If the player has no cards their fierceness is 0
	if (pile.size() == 0)
	{
		fierce = 0.0;
	}
	else
	{
		for (int i = 0; i < pile.size(); i++) // add all values of the cards in hand
		{
			double num = pile[i].getValue();
			fierce += num;
		}
		fierce = fierce / pile.size(); // calculate fierce by finding average value
	}
	return fierce;
}

// Call this function to accumulate battles
void Player::battled()
{
	battles++;
}
// Return number of battles player fought
int Player::getBattles()
{
	return battles;
}

// Call this function to accumulate wins
void Player::won()
{
	victories++;
}
// Return the number of victories
int Player::getWins()
{
	return victories;
}