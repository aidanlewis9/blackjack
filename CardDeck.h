// Aidan Lewis
// CardDeck.h


#ifndef CardDeck_H
#define CardDeck_H

#include <iostream>
using namespace std;

class CardDeck {
  
  friend ostream &operator<<(ostream &, const CardDeck &);
  
  public:
    CardDeck(int = 52); // constructor
    ~CardDeck(); // destructor

   // member functions
    int getSize();
    int getCard(int);
    void shuffle();

  private:
    int * deck;
    int cards;
};

#endif
