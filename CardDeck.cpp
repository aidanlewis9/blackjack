// Aidan Lewis
// CardDeck.cpp

#include <iostream>
#include <cstdlib>
#include "CardDeck.h"
using namespace std;

// constructor
CardDeck::CardDeck(int deckSize)
{
  cards = deckSize; 
  
  deck = new int[cards]; // dynamic array
  
  for (int i = 0; i < cards; i++) { // give each card a value
    deck[i] = i + 1;
  }
}

// destructor
CardDeck::~CardDeck()
{
  delete [] deck;
}

// return number of cards
int CardDeck::getSize()
{
  return cards;
}

int CardDeck::getCard(int card)
{
  return deck[card];
}

void CardDeck::shuffle()
{
  for (int i = 0; i < cards; i++)
  {
    int randNum = rand() % cards;
    int temp = deck[i];
    deck[i] = deck[randNum];
    deck[randNum] = temp;
  }
}

// overload output operator to print cards
ostream &operator<<(ostream &output, const CardDeck &cd) 
{
  for (int i = 0; i < cd.cards; i++)
  {
    if (i == cd.cards - 1)
    {
      output << cd.deck[i] << endl;
    } else {
      output << cd.deck[i] << ", "; 
    }
  }

  output << endl;
  return (output); 
}
