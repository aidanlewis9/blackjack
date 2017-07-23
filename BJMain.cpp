// Aidan Lewis
// BJMain.cpp

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include "CardDeck.h"
#include "blackjack.h"

using namespace std;

int main()
{
  srand(time(NULL));
  blackjack bob;
  bob.play();
  bob.printScore();

}
