#ifndef CASINO_H
#define CASINO_H

//robicu isi pierde ciocanu la aparate xddddd

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
    void SlotsStart();
    void Roulet();
    void Baccarat();

    void playAGame(int game);
};




#endif //CASINO_H
