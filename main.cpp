#include <iostream>
#include <random> // for shuffle
#include "Card.h"
#include "CardPile.h"
#include "Deck.h"
#include "LostnFound.h"
#include "MegaDeck.h"
#include "Player.h"
#include "WarPile.h"
#include <vector>
#include <string>
using namespace std;

// Check if there is only one person with cards
bool checkwin(vector<Player> players)
{
    bool check;
    int count = 0; // counter for players that still have cards
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].hascards())
        {
            count++;
        }
    }
    if (count > 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Display round stats
void display(vector<Player> players, int round)
{
    cout << "Battle " << round << " Stats: " << endl;
    for (int i = 0; i < players.size(); i++)
    {
        cout << "\tPlayer " << i + 1 << ":Fierceness = " << players[i].getFierce() << "\tCards = "
            << players[i].getCards() << "\tBattles = " << players[i].getBattles() << "\tWon = " << players[i].getWins() << endl;
    }
}

int main()
{
    int players; // num of players to play
    int decks; // num of decks to use
    int rounds = 0; // total amount of battles / current round

    cout << "Welcome to Mega War!" << endl;
    cout << "Enter the amount of players:" << endl;
    cin >> players;
    cout << "Enter the amount of decks:" << endl;
    cin >> decks;

    vector<Player> playerv; // vector of players
    // append player objects based on amount of players wanted to the player vector
    for (int i = 0; i < players; i++)
    {
        playerv.push_back(Player());
    }

    MegaDeck maindeck(decks); // create the main deck based on how many decks wanted
    maindeck.shuffle(); // shuffle the mega deck
    //maindeck.showMega(); // test to see if mega deck is shuffled

    // Dealing cards to the players
    int turn = 0; // players turn to get card
    while (maindeck.cardsleft() != 0) // while there are still cards left in the mega deck, keep dealing
    {
        playerv[turn].add(maindeck.deal());
        turn++;

        // after iterating through all the players, reset
        if (turn == playerv.size())
        {
            turn = 0;
        }
    }

    WarPile warp;
    LostnFound lostp;
    Card c;
    vector<int> dealt; // dealt cards
    while (checkwin(playerv) == false) // while there is no winner, keep going
    {
        int max = 0; // highest max card
        // loop through the players
        for (int i = 0; i < players; i++)
        {
            // Account for if player has no cards left, skip them
            if (!playerv[i].hascards())
            {
                continue;
            }
            else
            {
                c = playerv[i].deal();
                playerv[i].battled(); // if they place a card down, they battled
                warp.add(c); // add to war pile
               
                // if the player has the highest card currently
                if (c.getValue() > max)
                {
                    max = c.getValue(); // assign new max
                    dealt.clear(); // clear vector before adding a new max
                    dealt.push_back(i); // pushback indexes that contain the max
                }
                
                // if another person has the same value then add indexes to commit war later
                else if (c.getValue() == max)
                {
                    dealt.push_back(i);
                }
            }
        }
        rounds++; // increment battles

        /* COMMIT WAR */
        // If 2 or more indexes have the highest card, commit war
        if (dealt.size() > 1)
        {
            bool stillWar = true;
            vector<int> dealt2;
            int temp = 0;
            while (stillWar)
            {
                int max2 = 0;
                int losers = 0;
                for (int i: dealt)
                {
                    temp = warp.doWar(playerv[i]);
                    playerv[i].battled(); // increment that player participated in war
                    if (temp > max2)
                    {
                        max2 = temp;
                        dealt2.clear();
                        dealt2.push_back(i); // push back original index
                    }
                    // If the player did war and returned a value of 0, then they already lost
                    else if (temp == 0)
                    {
                        losers++;
                    }
                }

                // If all players competing in the war have no cards left, the warpile gets sent to lost and found pile
                if (dealt.size() == losers)
                {
                    warp.lostpiles(lostp);
                    stillWar = false; // mo more war if all players lost
                }

                // If there is only one person with high card, that player wins
                else if (dealt2.size() == 1)
                {
                    int index = dealt2[0];
                    warp.winnerpiles(playerv[index]); // transfer war pile to winner
                    playerv[index].won(); // increment that they won battle
                    stillWar = false; // there is no more wars

                    // transfer lost and found pile to winner if it has anything
                    if (lostp.hascards())
                    {
                        lostp.givewin(playerv[index]);
                    }
                }
                else
                {
                    // error - when doing war again, it uses dealt 1 indexes instead of dealt2 indexes
                    // this else statement updates dealt
                    dealt = dealt2;
                }
                rounds++;
                display(playerv, rounds);
            }
        }
        // if there is only 1 high card, that player wins the pile
        else
        {
            int index = dealt[0]; 
            warp.winnerpiles(playerv[index]);
            // transfer lost and found pile to winner if it has anything
            if (lostp.hascards())
            {
                lostp.givewin(playerv[index]);
            }
            playerv[index].won(); // increment that they won battle
            display(playerv, rounds);
        }
    }
}