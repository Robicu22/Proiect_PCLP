#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "User.h"
#include "Casino.h"
#include "Deck_Of_Cards.h"
#include "Jobs.h"
#include "Study.h"
#include "QualityTools.h"

using namespace std;

Jobs jobs;
User user;
Casino casino;
Deck_Of_Cards deck;
Study study;
QualityTools tools;
int currentMonth = 0;
void start() {
    cout<<"You just were born! Congrats welcome to the real world little one!\nSoon you will understand the real struggles of the humankind:) \n";
    cout<<"First please enter your name:\n";
    getline(cin, user.name);
    user.moneyPerYear= 0;
    user.money = 0;
    user.age = 0;
    user.alive = true;
    user.ocupation="";
    user.study="";
    user.uniSpec="";
    user.inteligence=0;
    user.unlockedActivities.push_back("Kind");   user.unlockedActivities.push_back("Wait");   user.unlockedActivities.push_back("Sleep");

    //user.health = 100;

    //user.lifeExpentence = user.calculateLifeExpentence()+10000;
    cout<<"Hello ";
    user.ShowPlayerStats();
}



vector<pair<string,int>> activities={pair<string,int>("Gamble",18)
    ,pair<string,int>("Gamble",18)
    ,pair<string,int>(user.ocupation,10)
    ,pair<string,int>(user.study,5)
    ,pair<string,int>("Sleep",18)
    ,pair<string,int>("KYS",user.stress)}
;
int main() {
        start();
    // cout<<"nenorocirile";
    // while (user.alive) {
    //     activites(user.age);
    //
    //
    //     //user.lifeExpentence = user.calculateLifeExpentence();
    //     if (user.age >= 60) {
    //         user.alive = false;
    //         cout<<"You turned 60! You are too old to live.\n";
    //     }
    // }
    //
    // cout<<"Congrats you are dead!";


    return 0;
}