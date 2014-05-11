/*//////////////////////////////////////////////////////////////
//Program: cards.cpp
//Author: Robert Payne
//Lab section: L15
//Date: 4/07/1512
//Purpose:  Creates a deck of cards using three arrays and then
//          randomly generates a hand. The hand's point value
//          is added up, and the hand is outputed along with
//          the points.
//
///////////////////////////////////////////////////////////////*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //arrays that make up the deck____________________________
    char deckSuite [52];    //holds the suite of the card
    int deckCardValue [52]; //holds the point value of the card
    bool cardPicked [52];   //true if the card has been picked
    //_________________________________________________________
    //data that does not make up the deck
    int playerHand [5]; //the player's hand
    int playerPoints;   //total points of the card hand
    int i = 0;      //iterator 1
    int a = 0;      //iterator 2
    int pickCard;   //used for picking a card

    //seeds the random generator w/ time
    srand(time(0));

    //initializes the player's points
    playerPoints = 0;

    //initializes the deck of cards
    while(i < 52)
    {
        //sets the suite
        switch(a%4)
        {
            case 0: deckSuite [i] = 'h';    //hearts
                    break;
            case 1: deckSuite [i] = 'd';    //diamonds
                    break;
            case 2: deckSuite [i] = 'c';    //clubs
                    break;
            case 3: deckSuite [i] = 's';    //spades
                    break;
        }
        //sets the point value
        switch(i%13)
        {
            case 0: deckCardValue[i] = 2;   //2...
                    break;
            case 1: deckCardValue[i] = 3;
                    break;
            case 2: deckCardValue[i] = 4;
                    break;
            case 3: deckCardValue[i] = 5;
                    break;
            case 4: deckCardValue[i] = 6;
                    break;
            case 5: deckCardValue[i] = 7;
                    break;
            case 6: deckCardValue[i] = 8;
                    break;
            case 7: deckCardValue[i] = 9;
                    break;
            case 8:
            case 9:
            case 10:
            case 11: deckCardValue[i] = 10; //10, jack, queen, king...
                     break;
            case 12: deckCardValue[i] = 11; //ace
                     a++;   //jumps to the next suite
                     break;
        }
        cardPicked[i] = false;  //puts the cards in the deck

        i++;
    }


    //Picks a random card from the deck;
    //also checks to see if the card has
    //been picked already
    for(i = 0; i < 5; i++)
    {
        do{
            pickCard = rand() %52;
        }while(cardPicked[pickCard]); //validation of card

        cardPicked[pickCard] = true;    //picks the card
        playerHand[i] = pickCard;       //sets the card index number to the hand
        playerPoints += deckCardValue[pickCard]; //updates the hand point total
    }

    //Outputs the player's hand
    cout<<"===========Your Hand============\n";
    for(i = 0; i < 5; i++)
    {
        //Outputs the card value
        switch(playerHand[i]%13)
        {
            case 0:     //2...
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8: cout<<deckCardValue[playerHand[i]]<<" ";//10
                    break;
            case 9: cout<<"Jack ";
                    break;
            case 10: cout<<"Queen ";
                    break;
            case 11: cout<<"King ";
                    break;
            case 12: cout<<"Ace ";
                    break;
        }

        //Outputs the suite of the card
        switch(deckSuite[playerHand[i]])
        {
            case 'h': cout<<"of Hearts\t"<<deckCardValue[playerHand[i]]<<endl;
                    break;
            case 'd': cout<<"of Diamonds\t"<<deckCardValue[playerHand[i]]<<endl;
                    break;
            case 'c': cout<<"of Clubs\t"<<deckCardValue[playerHand[i]]<<endl;
                    break;
            case 's': cout<<"of Spades\t"<<deckCardValue[playerHand[i]]<<endl;
                    break;
        }
        cout<<endl;
    }

    //Outputs point total for the hand
    cout<<"________________________________\n";
    cout<<"Point Total: "<< playerPoints<<endl;

return 0;
}
