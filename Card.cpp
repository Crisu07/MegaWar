// Card.cpp
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

// default constructor
Card::Card()
{
    // assign as blank cards
    rank = BLANK;
    suit = BLANK2;
}

// overload constructor
Card::Card(value r, su s)
{
    rank = r;
    suit = s;
}

// pass in own values
void Card::setCard(value r, su s) // helps with resetting the deck
{
    rank = r;
    suit = s;
}

int Card::getValue()
{
    int r = rank; // set enum to an int and return a value
    return r;
}

void Card::showCard()
{
    // Determining Suit
    string s;
    switch (suit)
    {
    case SPADE:
        s = "S";
        break;
    case HEART:
        s = "H";
        break;
    case DIAMOND:
        s = "D";
        break;
    case CLUB:
        s = "C";
        break;
    }

    // Output card
    if (rank == JACK)
    {
        cout << "J" << s;
    }
    else if (rank == QUEEN)
    {
        cout << "Q" << s;
    }
    else if (rank == KING)
    {
        cout << "K" << s;
    }
    else if (rank == ACE)
    {
        cout << "A" << s;
    }
    else // Any non face cards
    {
        cout << rank << s;
    }
}