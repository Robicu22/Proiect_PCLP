#ifndef USER_H
#define USER_H

////////Libraries////////////
#include<string>

using namespace std;

class User {
public:
        int age,money,moneyPerMonth;
        string name,ocupation;
        bool alive;

        //////methods///////
        void ShowPlayerStats();
        void KillYourself(bool alive);
};



#endif //USER_H
