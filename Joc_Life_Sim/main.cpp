#include <algorithm>
#include <iostream>


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
    user.study="kindergarden";
    user.uniSpec="";
    user.inteligence=0;
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
    ,pair<string,int>("KYS",user.stress)};

void activites(int age) {
    cout<<"What would you like to do?\n";

    if (age < 18) {
        cout<<"piticule baga banii in masini nu in masinarii\n";

    }
    else {

            cout<<"1. Gamble\n"
                <<"2. Work\n"
                <<"3. Study\n"
                <<"5. Just die u fucking twat\n"
                <<"6. Check stats\n";

        int choice;
        cin>>choice;
        switch (choice) {

            case 1: {
               casino.ShowGames();
                break;
            }
            case 2: {
               jobs.Work(user.ocupation);
                break;
            }
            case 3:
                if (user.age >= 19|| user.study == "Highschool") {
                    study.ChoseUniversity();
                }
                study.StudyHard();
                break;

            case 5: {
                user.alive = false;
                break;
            }
            case 6: {
              user.ShowPlayerStats();
            }
        }
    }

}
int main() {
    // start();
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

    string s;
    int n;
    cin>>s>>n;

    cout<<tools.curse(s,n);


    return 0;
}