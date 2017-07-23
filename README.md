Blackjack
=========

The user uses the program by deciding whether to hit (take another card) or stay at their current value. The program starts by drawing two cards for both the player and dealer. The player's total is displayed, and then they are prompted as to whether they would like to hit (by entering 1) or stay (by entering 0). The user will keep receiving this prompt (after the dealer takes its turn as well) until she either stays or goes over 21. Once the game is over and user has been informed whether she won or not, she will be prompted as to whether she wishes to continue playing. By entering 1, she can play another round, and by entering 0, she can quit.

Internally, blackjack inherits from CardDeck. Because of this, the card deck, and its shuffle, getSize, and getCard methods are accessible in this class. This makes blackjack significantly easier to craft. The main method in blackjack is play(), which contains two while loops. The outer while loop checks that the user still wants to play with the keepPlay variable. At the end of the game, the user is prompted as to whether he wishes to continue playing, and if does, keepPlay stays equal to 1, and the while loop continues to the next game. If the user quits at this prompt, the while loop will break. The inner while loop is for each individual game. While no one has won, the loop checks which player's turn it is, and calls either playerPlay or dealerPlay. In playerPlay, the deal will be called twice if the value of the player's cards is currently 0 (meaning no cards have been dealt yet). The deal function uses getCard from the CardDeck class, and takes the next card with count (which increases with each card taken). The remainder when the card is divded by 13 is the value for the card, unless this value is 0, 1, or 12. These values are set equal to ten to become the jack, queen, and king. If the player's total is greater than 0 (meaning it is not his first turn), the player will be prompted on whether to hit or stay. When hit is picked, deal is called, and if stay is picked, playerIn is set to 0 to indicate the player is no longer playing. After the turn has finished, playerTurn is set to 0 (indictaing it is the dealer's turn) only if the dealerIn is equal to 1 (meaning the dealer is still playing). check is called to determine whether any player has won or lost yet. It returns 1 if someone has won, and a 0 if the game is to continue. This return value is set equal to outcome, which returns to win in play. If win is equal to 1 and the game is over, the inner while loop will break so that the player can quit or a new game can start. dealerPlay is much simpler. If the dealer's card total is 0 (he hasn't been dealt cards), deal is called twice. Otherwise, if the dealer's total is less than 17, deal is called once, and if it is greater than or equal to 17, dealerIn is set to 0 to indicate the dealer will no longer hit. check is called once again here, and the turn is turned over to the player (as long as playerIn is equal to 1, meaning the player is still in the game). After any given game finishes, the dealer's total wins and the player's total wins are displayed with the printScore method. The reset method is also called here to reset the necessary variables to where they were at the beginning of the last game. Count, however, is not reset so that the same card deck will continue to be used until the number of cards remaining is less than or equal to 15. When this occurs, the cards are shuffled (using shuffle() from CardDeck), and count is reset.

I verified the program through several different methods. First, for anything involving user inputs (the hit or stay decision, and the quit or keep playing decision), a tested several random inputs. The program handled these well, since if the choice is not an expected one, it enters a while loop until the user enters a valid input. I also verified the input by playing the game many times to compare the wins and loses for the player and dealer. They tend to be about 50-50 over time. I also tested the "shuffle when there are 15 or fewer cards rule by playing through 37 cards. This appeared to work as well. I also tested the check function by continually looking to see if the computer designated the correct winner. It was able to determine the right winner every time I played.
