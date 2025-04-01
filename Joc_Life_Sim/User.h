#ifndef USER_H
#define USER_H

////////Libraries////////////
#include<string>

using namespace std;



class User {
public:
        int age,money,moneyPerYear,stress, lifeExpentence, health,inteligence;
        string name,ocupation,study,uniSpec;
        bool alive;

        //////methods///////
        void ShowPlayerStats();
        void KillYourself(bool alive);
        int calculateLifeExpentence();
};



#endif //USER_H
