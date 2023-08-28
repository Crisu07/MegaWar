// Player.h
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardPile.h"
#ifndef PLAYER_H 
#define PLAYER_H
using namespace std;

class Player : public CardPile
{
private:
	int battles; // number of battles player fought
	int victories; // number of battles player won
	double fierce; // fierceness of hand
public:
	Player();
	int getCards();
	double getFierce();
	void battled();
	int getBattles();
	void won();
	int getWins();
};
#endif