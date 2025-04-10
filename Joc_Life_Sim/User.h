#ifndef USER_H
#define USER_H

////////Libraries////////////
#include<string>
#include<vector>

using namespace std;



class User {
public:
        int age,money,moneyPerYear,stress, lifeExpentence, health,inteligence;
        string name,ocupation,study,uniSpec;
        vector<string> degree;
        bool alive;

        //////methods///////
        void ShowPlayerStats();
        void KillYourself(bool alive);
        int calculateLifeExpentence();
};



#endif //USER_H
