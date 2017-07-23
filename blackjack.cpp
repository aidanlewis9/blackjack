// Aidan Lewis
// blackjack.cpp

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <unistd.h>
#include "blackjack.h"
#include "CardDeck.h"
using namespace std;

// constructor
blackjack::blackjack(int deckSize) : CardDeck(deckSize)
{
// initialize private variable values
  playerWins = 0;
  dealerWins = 0;
  playerTotal = 0;
  dealerTotal = 0;
  playerIn = 1;
  dealerIn = 1;
  count = 0;
  playerTurn = 1;
  win = 0;
  keepPlay = 1;
  CardDeck cd;
  cd.shuffle();
}

// destructor
blackjack::~blackjack()
{ }

void blackjack::deal()
{
  while (count >= cd.getSize()-15) // if there are 15 or fewer cards remaining
  { 
    CardDeck cd;
    srand(time(NULL)); // set seed 
    cd.shuffle(); // shuffle cards: from CardDeck
    count = 0; // reset count
  }
  int card = cd.getCard(count) % 13; // gives card value of 0-12
  count++;
  if (card <= 1 || card == 12) // change values for 0,1, and 12 to jack, queen, and king
  {
    card = 10;
  }
  // increase total of player who was dealt cards
  if (playerTurn == 1)
  { playerTotal += card; }
  else { dealerTotal += card; }
}

void blackjack::play()
{
  while (keepPlay == 1) // loops until player chooses to quit
  {
    while (win == 0) // loops until someone wins
    {
      if (playerTurn == 1) // if player's turn
      {
	win = playerPlay();	
      } else { // if dealer's turn
	win = dealerPlay();
      }
    }
    printScore(); // print results and win tallies
    reset(); // reset variables
  }
}

int blackjack::check()
{
  
  if (playerTotal == 21 || dealerTotal > 21) // if the player hit 21 or dealer is over 21
  {
    cout << "Player wins!" << endl << endl;
    playerWins++; // increase player wins
    return 1; // someone won
  }
  else if (playerTotal > 21) // if the player is over 21
  {
    cout << "Dealer wins." << endl << endl;
    dealerWins++; // increase dealer wins
    return 1;
  }
  else if (dealerIn == 0 && playerIn == 0) // if both players folded
  {
    if (playerTotal >= dealerTotal) 
    {
      cout << "Player wins!!!" << endl << endl;
      playerWins++;
    }
    else {
      cout << "Dealer wins." << endl << endl;
      dealerWins++;
    }
    return 1;
  }
  else if (dealerTotal >= 17) // dealer cannot hit at or above 17
  {
    dealerIn = 0;
    return 0; // no winner yet
  }
  else { return 0; } // no winner yet
}

void blackjack::reset()
{
  keepPlay = 2;
  // ask user if they wish to continue playing or quit
  while (keepPlay != 0 && keepPlay != 1)
  {
    cout << "Would you like to keep playing? Enter 1 for yes, 0 for no" << endl;
    cin >> keepPlay;
    cout << endl;
  }
  // reset variables for next game
  playerTurn = 1;
  playerTotal = 0;
  dealerTotal = 0;
  playerIn = 1;
  dealerIn = 1;
  win = 0;
}

void blackjack::printScore()
{
  cout << endl;
  cout << "Player wins: " << playerWins << endl;
  cout << "Dealer wins: " << dealerWins << endl << endl;
}

int blackjack::playerPlay()
{
  int choose = 2;
  cout << "Player's turn - Score: " << playerTotal << endl << endl;
  if (playerTotal != 0) // if the player already has cards (not first turn)
  {
  // prompt user for choice
    cout << "Enter 1 to hit, and 0 to stay" << endl;
    cin >> choose;
  // to protect against invalid inputs
    while (choose != 0 && choose != 1)
    {
      cout << "Please enter a valid option: " << endl;
      cin >> choose;
    }
  } else { // if the player has yet to receive any cards
    deal(); 
    deal(); // get two cards to start
  }
  if (choose == 1) { // if the user chooses to hit
    deal();
  }
  else if (choose == 0) { // if the player chooses to stay
    playerIn = 0;
  }
  cout << "Your Total: " << playerTotal << endl << endl;
  int outcome = check(); // check if there is a winner
  if (dealerIn == 1) // transfer turn if the dealer is still in
  { playerTurn = 0; }
  return outcome;
}

int blackjack::dealerPlay()
{
  if (dealerTotal == 0) // if dealer has no cards
  {
    deal();
    deal(); // deal two cards to start
    cout << "Dealer Total: " << dealerTotal << endl << endl;
  }
  else if (dealerTotal < 17) // if the dealer is below 17, hit
  {
    deal();
    cout << "Dealer Total: " << dealerTotal << endl << endl;
  }
  else { // otherwise, the dealer is stays
    dealerIn = 0;
  }
  int outcome = check(); // check for winner
  if (playerIn == 1) // transfer turn if player is still in
  { playerTurn = 1; }
  return outcome;
}
