//
// Created by robicu on 3/28/25.
//

#ifndef CASINO_H
#define CASINO_H

//robicu isi pierde pula la aparate xddddd

class Casino{
public:
    int balance=1000;
    ///////methods
    void ShowGames();
    void Depozit();
    void Withdraw();

    //Casino games
    void Blackjack();
    void Dices();
    void Findjoker();
    void Poker();
    void Slots();
    void Roulet();

    void playAGame(int game);
};



#endif //CASINO_H
