// Aidan Lewis
// blackjack.h

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "CardDeck.h"

#include <iostream>
using namespace std;

class blackjack: public CardDeck
{
  public:
    blackjack(int = 52); // constructor
    ~blackjack(); // destructor

    // member functions
    void deal();
    void play();
    int check();
    void reset();
    void printScore();
    int playerPlay();
    int dealerPlay();

  private:
    int playerWins;
    int dealerWins;
    int playerTotal;
    int dealerTotal;
    int playerIn;
    int dealerIn;
    int count;
    int playerTurn;
    int win;
    int keepPlay;
    CardDeck cd;
};

#endif
