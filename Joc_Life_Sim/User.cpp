#include "User.h"

#include <iostream>

using namespace std;


void User::ShowPlayerStats() {
    cout<<name<<endl;
    cout<<"Your age is: "<<age<<endl;
    cout<<"Your balance: "<<money<<"RON"<<endl;
    cout<<"You make per month: "<<moneyPerYear<<"RON"<<endl;
    cout<<"Your stress level: "<<stress<<endl;
}

int User::calculateLifeExpentence() {
    return User::health - User::age - 10%User::stress;
}


// 100 , 20 , 10