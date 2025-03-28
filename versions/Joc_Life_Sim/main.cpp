#include <algorithm>
#include <iostream>

#include "User.h"
#include "Casino.h"
#include "Deck_Of_Cards.h"

using namespace std;

User user;
Casino casino;
Deck_Of_Cards deck;
int currentMonth = 0;
void start() {
    cout<<"You just were born! Congrats welcome to the real world little one!\nSoon you will understand the real struggles of the humankind:) \n";
    cout<<"First please enter your name:\n";
    cin>>user.name;
    user.moneyPerMonth = 30;
    user.money = 3000;
    user.age = 18;
    user.alive = true;
    cout<<"Hello ";
    user.ShowPlayerStats();
}

void activites(int age) {
    cout<<"What would you like to do?\n";

    if (age < 18) {
        cout<<"Esti prea mic sa faci ceva\n";
    }
    else {
        cout<<"1. Gamble \n"
            <<"2. Work\n"
            <<"3. Sleep\n"
            <<"4. Waste time\n"
            <<"5. Kill yourself\n";

        int choice;
        cin>>choice;
        switch (choice) {

            case 1: {
                casino.ShowGames();
                break;
            }
            case 5: {
                user.alive = false;
                break;
            }
        }
    }

}
int main() {
    start();

    while (user.alive) {
        activites(user.age);

    }

    cout<<"Congrats you are dead!";

    return 0;
}