#include "Casino.h"
#include "Deck_Of_Cards.h"
#include "QualityTools.h"
#include "User.h"

#include <iostream>
#include <string>
#include <random>
#include <bits/stdc++.h>
#include<chrono>



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
            cout<<"Balance: "<<balance<<endl;
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
                    balance -=stoi(pot);
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
                            balance-=stoi(pot);
                        }else if (dealer==hand) {
                            cout<<"Draw\n";
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

void Casino::Baccarat() {


    int choice = 1;
    string bet, betOn;
    vector<int> player, banker;
    int playerTotal, bankerTotal;
    Deck_Of_Cards deck;
    while (choice == 1) {
        int win = 0;
        playerTotal = 0;
        bankerTotal = 0;
        player.clear();
        banker.clear();

        cout<<"How much do you want to bet?\n";
        cout<<"Balance: "<<balance<<" RON\n";
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

        cout<<"On what do you want to bet?\n"
            <<"1. PLayer\n"
            <<"2. Banker\n"
            <<"3. Tie\n";

        while (true) {
            cin>>betOn;
            if (qualityTools.isStringAnInt(betOn)) {
                if (stoi(betOn) > 0 && stoi(betOn) < 4)
                    break;
                else
                    cout<<"The bet is invalid, try again!\n";
            }
            else
                cout<<"Invalid option, try again!\n";
        }
        deck.Shuffle();

        for (int i = 0; i < deck.deck.size(); i++)
            if (deck.deck[i].second> 10)
                deck.deck[i].second = 10;

        player.push_back(deck.deck[0].second);
        deck.deck.erase(deck.deck.begin());
        banker.push_back(deck.deck[0].second);
        deck.deck.erase(deck.deck.begin());
        playerTotal = accumulate(player.begin(), player.end(), 0);
        bankerTotal = accumulate(banker.begin(), banker.end(), 0);

        cout<<"Player's hand: "<<player[0]<<"       "<<"Banker's hand: "<<banker[0]<<endl;

        cout<<"Player's total: "<<playerTotal%10<<"       "<<"Banker's total: "<<bankerTotal%10<<endl;

        sleep(2);

        player.push_back(deck.deck[0].second);
        deck.deck.erase(deck.deck.begin());
        banker.push_back(deck.deck[0].second);
        deck.deck.erase(deck.deck.begin());
        playerTotal = accumulate(player.begin(), player.end(), 0);
        bankerTotal = accumulate(banker.begin(), banker.end(), 0);

        cout<<"Player's hand: "<<player[0]<<" "<< player[1]<<"       "<<"Banker's hand: "<<banker[0]<<" "<<banker[1]<<endl;

        cout<<"Player's total: "<<playerTotal%10<<"       "<<"Banker's total: "<<bankerTotal%10<<endl;
        sleep(2);
        int playersThirdCard = -1;

        //A treia carte a jucatorului
        if (bankerTotal%10 < 8)
        {
            if (playerTotal%10 >= 0 && playerTotal%10 < 6){
                player.push_back(deck.deck[0].second);
                deck.deck.erase(deck.deck.begin());
                playersThirdCard = player[2];
                playerTotal = accumulate(player.begin(), player.end(), 0);
                bankerTotal = accumulate(banker.begin(), banker.end(), 0);
                cout<<"Player's hand: "<<player[0]<<" "<< player[1]<<" "<<player[2]<<"       "<<"Banker's hand: "<<banker[0]<<" "<<banker[1]<<endl;
                cout<<"Player's total: "<<playerTotal%10<<"       "<<"Banker's total: "<<bankerTotal%10<<endl;
                sleep(1);
            }
        }
        //A treia carte a bancherului
        playerTotal = accumulate(player.begin(), player.end(), 0);
        bankerTotal = accumulate(banker.begin(), banker.end(), 0);
        if (playerTotal%10 < 8)
        {
            if (playersThirdCard > 0)
            {
                if (bankerTotal%10 < 3)
                {
                    banker.push_back(deck.deck[0].second);
                    deck.deck.erase(deck.deck.begin());
                    bankerTotal = accumulate(banker.begin(), banker.end(), 0);
                    cout<<"Player's hand: "<<player[0]<<" "<< player[1]<<" "<<player[2]<<"       "<<"Banker's hand: "<<banker[0]<<" "<<banker[1]<<" "<<player[2]<<endl;

                    cout<<"Player's total: "<<playerTotal%10<<"       "<<"Banker's total: "<<bankerTotal%10<<endl;
                }
                else if (bankerTotal%10 == 3 && playersThirdCard != 8)
                {
                    banker.push_back(deck.deck[0].second);
                    deck.deck.erase(deck.deck.begin());
                    bankerTotal = accumulate(banker.begin(), banker.end(), 0);
                    cout<<"Player's hand: "<<player[0]<<" "<< player[1]<<" "<<player[2]<<"       "<<"Banker's hand: "<<banker[0]<<" "<<banker[1]<<" "<<player[2]<<endl;

                    cout<<"Player's total: "<<playerTotal%10<<"       "<<"Banker's total: "<<bankerTotal%10<<endl;
                }
                else if (bankerTotal%10 == 4 && (playersThirdCard > 1 && playersThirdCard < 8))
                {
                    banker.push_back(deck.deck[0].second);
                    deck.deck.erase(deck.deck.begin());
                    bankerTotal = accumulate(banker.begin(), banker.end(), 0);
                    cout<<"Player's hand: "<<player[0]<<" "<< player[1]<<" "<<player[2]<<"       "<<"Banker's hand: "<<banker[0]<<" "<<banker[1]<<" "<<player[2]<<endl;

                    cout<<"Player's total: "<<playerTotal%10<<"       "<<"Banker's total: "<<bankerTotal%10<<endl;
                }
                else if (bankerTotal%10 == 5 && (playersThirdCard > 3 && playersThirdCard < 7))
                {
                    banker.push_back(deck.deck[0].second);
                    deck.deck.erase(deck.deck.begin());
                    bankerTotal = accumulate(banker.begin(), banker.end(), 0);
                    cout<<"Player's hand: "<<player[0]<<" "<< player[1]<<" "<<player[2]<<"       "<<"Banker's hand: "<<banker[0]<<" "<<banker[1]<<" "<<player[2]<<endl;

                    cout<<"Player's total: "<<playerTotal%10<<"       "<<"Banker's total: "<<bankerTotal%10<<endl;
                }
                else if (bankerTotal%10 == 6 && (playersThirdCard == 6 || playersThirdCard == 7))
                {
                    banker.push_back(deck.deck[0].second);
                    deck.deck.erase(deck.deck.begin());
                    bankerTotal = accumulate(banker.begin(), banker.end(), 0);
                    cout<<"Player's hand: "<<player[0]<<" "<< player[1]<<" "<<player[2]<<"       "<<"Banker's hand: "<<banker[0]<<" "<<banker[1]<<" "<<player[2]<<endl;

                    cout<<"Player's total: "<<playerTotal%10<<"       "<<"Banker's total: "<<bankerTotal%10<<endl;
                }

            }
        }


        sleep(2);

        playerTotal = accumulate(player.begin(), player.end(), 0);
        bankerTotal = accumulate(banker.begin(), banker.end(), 0);

        //Cine castiga

        if (playerTotal%10 == bankerTotal%10){
            cout<<"It's a tie!\n";
            if (stoi(betOn) == 3)
            {
                win = int(stoi(bet) * 9);
                cout<<"You won: "<<win<<" RON\n";
            }
            else
            {
                win = stoi(bet);
                cout<<"You got your money back\n";
            }

        }
        else if (playerTotal%10 > bankerTotal%10)
        {
            cout<<"Player won! \n";
            if (stoi(betOn) == 1)
            {
                win = int(stoi(bet) *2);
                cout<<"You won: "<<win<<" RON\n";
            }
            else
            {
                cout<<"You lost!\n";
            }
        }
        else
        {
            cout<<"Banker won! \n";
            if (stoi(betOn) == 2)
            {
                win = int(stoi(bet) * 1.90);
                cout<<"You won: "<<win<<" RON\n";
            }
            else
            {
                cout<<"You lost!\n";
            }
        }

        balance += win;

        cout<<"Do you want to play again? (Type the option number)\n"
         <<"1. Play again\n"
         <<"2. Exit\n";
        cin>>choice;
    }


}

auto RunRoulet(){
    vector<pair<int, string>> roulette = {{0, "green"},{1, "red"},{2, "black"},{3, "red"},{4, "black"},{5, "red"},{6, "black"},{7, "red"},{8, "black"},{9, "red"},{10, "black"},{11, "black"},{12, "red"},{13, "black"},{14, "red"},{15, "black"},{16, "red"},{17, "black"},{18, "red"},{19, "red"},{20, "black"},{21, "red"},{22, "black"},{23, "red"},{24, "black"},{25, "red"},{26, "black"},{27, "red"},{28, "black"},{29, "black"},{30, "red"},{31, "black"},{32, "red"},{33, "black"},{34, "red"},{35, "black"},{36, "red"}};
    srand(time(0));
    int rng=rand()%37;
    pair<int,string> draw= roulette[rng];
    return draw;
}
void RWin(auto draw,int pot){
    cout<<"It landed on "<<draw.first<<" "<<draw.second<<endl;
    cout<<"You won!!!\n";

}
void Rlose(auto draw,int pot){
    cout<<"It landed on "<<draw.first<<" "<<draw.second<<endl;
    cout<<"You lost!!!\n";
}
void RWait()
{
    cout<<"It is spining\n";
    sleep(1);
    cout<<"..\n";
    sleep(1);
    cout<<"....\n";
    sleep(1);
    cout<<"......\n";
    sleep(1);
}

void Casino::Roulet() {
    cout<<"Hello wellcome to the Roulet!!\n";
    string bet;
    int pot=0;
    while (true) {
        cout<<"How much do you want to bet?\n";
        cout<<"Balance: "<<balance<<endl;
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
    pot = stoi(bet);
    cout<<"Great now what do you want to bet on \n "
          "1.Black or Red or Green\n"
          "2.A number\n"
          "3.Odd or Even\n";
    cout<<"Write bellow the choice\n";
    int choice,secChoice;
    cin>>choice;
    pair<int,string> draw = RunRoulet();
    switch (choice)
    {
        case 1:
            {
                cout<<"1.Black for a 2x on the bet\n"
                      "2.Red for a 2x on the bet\n"
                      "3.Green for a 36x on the bet\n"
                      "Chose bellow\n";
                cin>>secChoice;
                RWait();
                if (secChoice==1)
                {
                    if (draw.second=="black")
                    {
                        RWin(draw,pot);
                        balance +=pot*2;
                    }else
                    {
                        Rlose(draw,pot);
                    }
                }else if (secChoice==2)
                {
                    if (draw.second=="red")
                    {
                        RWin(draw,pot);
                        balance += pot*2;
                    }else
                    {
                        Rlose(draw,pot);
                    }
                }else if (secChoice==3)
                {
                    if (draw.second=="green")
                    {
                        RWin(draw,pot);
                        balance +=pot*36;
                    }else
                    {
                        Rlose(draw,pot);
                    }
                }
                break;
            }
        case 2:
        {
                                                               cout<<"Chose a number to bet between 0 and 36 for a 36x bet\n";
                                                               int numChoice;
                                                               cin>>numChoice;
                                                               RWait();
                                                               if (draw.first==numChoice)
                                                               {
                                                                   RWin(draw,pot);
                                                                   balance=pot*36;
                                                               }else
                                                               {
                                                                   Rlose(draw,pot);
                                                               }
                                                                break;
        }
        case 3:
            {
                cout<<"Chose if the number it lands on is either Odd or Even:\n1.Odd for a 2x bet\n2.Even for a 2x bet\n";
                int evenChoice;
                cin>>evenChoice;
                RWait();
                if (evenChoice==1&&draw.first%2==1)
                {
                    RWin(draw,pot);
                    balance+=pot*2;
                }else if (evenChoice==2&&draw.first%2==0)
                {
                    RWin(draw,pot);
                    balance+=pot*2;
                }else
                {
                    Rlose(draw,pot);
                }
                break;
            }
    }
    cout<<"Do you want to play again?\n1.Play again!\n2.Exit\n";
    cin>>choice;
    if (choice==1)
    {
        Casino::Roulet();
    }
}
int Slots(int bet)
{
    int win=0,winnings=0,choice=1;
    do
    {
        //pacane aici

        if (win>0){cout<<"You won "<<win<<endl;}else{cout<<"You lost "<<bet<<endl;}
        winnings+=win-bet;
        win=0;
        cout<<"0.Exit\n"
            <<"1.Play again\n";
        cout<<"You have made "<<winnings<<endl;
        cout<<"The bet is "<<bet<<endl;
        cin>>choice;
        //qualityTools.Clear();
    }while (choice);
    return winnings;
}
void Casino::SlotsStart()
{
    int choice,win;
    cout<<"How much you wanna bet?\n";
    cout<<"Your balance: \n"<<balance;
    cin>>choice;
    if (choice)
    {
        balance -=choice;
        win=Slots(choice);
    }
}

