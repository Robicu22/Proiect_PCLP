
#include "Casino.h"
#include "Deck_Of_Cards.h"
#include "QualityTools.h"
#include "User.h"

#include <iostream>
#include <string>
#include <random>
#include <bits/stdc++.h>



using namespace std;

extern User user;
QualityTools qualityTools;

void Casino::ShowGames() {
    cout<<"Balance: "<<balance<<"RON"<<endl;
    cout<<"If you want to depozit/withdraw\n"
        <<"10. Depozit\n"
        <<"11. Withdraw\n";
    cout<<"What you want to play?\n";
    cout<<"1. Blackjack\n"
        <<"2. Dices\n"
        <<"3. Find the Joker\n"
        <<"4. Poker\n"
        <<"5. Slots\n"
        <<"6. Roulet\n";

    int game;
    cin>>game;
    playAGame(game);
}

void Casino::playAGame(int game) {
    switch (game) {
        case 1: {
            Casino::Blackjack();
            break;
        }
        case 2: {
            Casino::Dices();
            break;
        }
        case 10: {
            Casino::Depozit();
            break;
        }
        case 11: {
            Casino::Withdraw();
            break;
        }

    }
}
void Casino::Withdraw() {
        cout<<"How much you want to withdraw?\n";
        cout<<"Balance= " << balance <<"\n";
        int choice;
        string aux;
        cin>>aux;
        if (qualityTools.isStringAnInt(aux)) {
            choice=stoi(aux);
        }else {
            cout<<"No string allowed, pls use int like a normal human being";
            Casino::Withdraw();
            return;
        }

        if (choice >balance) {
            cout<<"You dont have that much, sorry.\n";
        }else {
            cout<<"The amount of "<<choice <<" has been transfered to your account!!!\n";
            user.money += choice;
            balance-=choice;
        }
}
void Casino::Depozit() {
    cout<<"How much you want to depozit?\n";
    cout<<"Balance= " << user.money <<"\n";

    int choice;
    string aux;
    cin>>aux;
    if (qualityTools.isStringAnInt(aux)) {
        choice=stoi(aux);
    }else {
        cout<<"No string allowed, pls use int like a normal human being";
        Casino::Depozit();
        return;
    }
    if (choice >user.money) {
        cout<<"You dont have that much, sorry.\n";
    }else {
        cout<<"The amount of "<<choice <<" has been transfered to your balance!!!\n";
        balance += choice;
        user.money -= choice;
    }
}
void Casino::Dices() {
    int choice = 1;
    pair<int,int> dealerDices, playerDices;
    srand(time(0));
    string answer,n,bet;

    cout<<"Game rules: \n"
        <<"1. Mostly if you roll higher than the dealer you win and double the sum of your bet\n"
        <<"2. If you roll 1 and 1 your win is double than normal\n"
        <<"3. If you roll the same thing as the dealer you are forced to roll again, only if you don't roll 1 and 1, in that case you don't lose anything\n"
        <<"Do you wish to continue? Type yes or no \n";

    while (true) {
        cin>>answer;
        if (answer == "yes")
            break;
        else if (answer == "no") {
            choice = 2;
            break;
        }
        else
            cout<<"Please enter a valid option\n";
    }

    while (choice == 1) {
        int win = 0;
        cout<<"How much do you want to bet?\n";
        while (true) {
            cin>>bet;
            if (qualityTools.isStringAnInt(bet)) {
                if (stoi(bet) > balance)
                    cout<<"You don't have that much! Try again\n";
                else if (stoi(bet) > 0)
                    break;
                else
                    cout<<"The bet is invalid, try again!\n";
            }
            else
                cout<<"The bet is invalid, try again!\n";
        }

        balance -= stoi(bet);
        cout<<"Type anything to start the game\n";
        cin>>n;
        dealerDices.first = 1+rand()%6;
        dealerDices.second = 1+rand()%6;

        playerDices.first = 1+rand()%6;
        playerDices.second = 1+rand()%6;

        cout<<"You rolled: "<< playerDices.first<<" "<<playerDices.second<<endl;
        if (playerDices.first == playerDices.second == 1 && !(dealerDices.first == dealerDices.second == 1)) {

            win = 4*stoi(bet);
            cout<<"Nice throw, you won: "<<win<<endl;
        }
        else if (playerDices.first + playerDices.second == dealerDices.first + dealerDices.second) {
            cout<<"Dealer rolled: "<< dealerDices.first<<" "<<dealerDices.second<<endl;
            cout<<"It's a draw! \n";

        }
        else {
            cout<<"Dealer rolled: "<< dealerDices.first<<" "<<dealerDices.second<<endl;
            if (playerDices.first + playerDices.second > dealerDices.first + dealerDices.second) {
                win = 2*stoi(bet);
                cout<<"Congrats you won: "<<win<<endl;
            }
            else if (playerDices.first + playerDices.second < dealerDices.first + dealerDices.second)
                {
                win = 0;
                cout<<"You lost: "<<bet<<" RON\n";
            }

        }

        cout<<"Type anything to continue! \n";
        cin>>n;



        balance += win;
        cout<<"Your balance is: "<<balance<<" RON \n";
        cout<<"Do you want to play again? (Type the option number)\n"
            <<"1. Play again\n"
            <<"2. Exit\n";
        cin>>choice;
    }

}
/////////////////BLACKJACK////////////////////////////////////////
int TransformCardBJ(int num,int hand) {
    if (num==1) {
        if (hand+num+10>21) {
            return 1;
        }else {
            return 11;
        }
    }
    if (num>=11) {
        return 10;
    }
    return num;
}
void Casino::Blackjack() {// fa asu sa fie as
    int choice=1,dealer=0,hand=0,aux;
    int num;
    string pot;
    Deck_Of_Cards deck;
    bool end=false;
    srand(time(0));
    num = rand()%13;

    while (choice) {
        if (choice == 1) {
            deck.Shuffle();
            hand=0;
            dealer=0;
            cout<<"How much you want to bet?\n";
            while (true) {
                cin>>pot;
                if (qualityTools.isStringAnInt(pot)) {
                    if (stoi(pot) > balance)
                        cout<<"You don't have that much! Try again\n";
                    else if (stoi(pot) > 0)
                        break;
                    else
                        cout<<"The bet is invalid, try again!\n";
                }
                else
                    cout<<"The bet is invalid, try again!\n";
            }

            aux=TransformCardBJ(deck.deck[0].second,0);
            deck.deck.erase(deck.deck.begin());
            dealer +=aux;
            aux=0;
            end=false;
            while (!end) {
                aux=TransformCardBJ(deck.deck[0].second,0);
                deck.deck.erase(deck.deck.begin());
                hand+=aux;
                cout<<"dealer shows: "<<dealer<<endl;
                cout<<"Your hand: "<<hand<<"\n";
                if (hand>21) {
                    end=true;
                    cout<<"You LOST\n";
                    break;
                }else {
                    cout<<"Chose what to do:\n";
                    cout<<"1.Hit\n";
                    cout<<"2.Stay\n";
                    cin>>choice;
                    if (choice==2) {
                        end=true;
                        while (dealer<17) {
                            aux=TransformCardBJ(deck.deck[0].second,0);
                            deck.deck.erase(deck.deck.begin());
                            dealer+=aux;
                            cout<<"Dealer hit: "<<dealer<<endl;
                        }

                        cout<<"Your hand: "<<hand<<"\n";
                        cout<<"Dealer hand: "<<dealer<<"\n";
                        if (dealer>hand&&dealer<=21) {
                            cout<<"You lost!\n";
                        }else if (dealer==hand) {
                            cout<<"Draw\n";
                            balance+=stoi(pot);
                        }else {
                            cout<<"YOU WIN!!!"<<"+ "<<stoi(pot)*2 <<"\n";
                            balance+=stoi(pot)*2;
                        }
                    }

                }
            }

            cout<<"Do you want to play again? \n"
                <<"1. Play again\n"
                <<"2. Exit\n";
            cin>>choice;
        }
        if (choice==2) {
            break;
        }
    }
    cout<<"Your balance is "<<balance<<"\n";
}