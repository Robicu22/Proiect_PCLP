#include "User.h"

#include <iostream>

using namespace std;


void User::ShowPlayerStats() {
    cout<<name<<endl;
    cout<<"Your age is: "<<age<<endl;
    cout<<"Your balance: "<<money<<"RON"<<endl;
    cout<<"You make per month: "<<moneyPerYear<<"RON"<<endl;
    cout<<"Your stress level: "<<stress<<endl;
    cout<<"Your ocupation is: "<<ocupation<<endl;
    cout<<"You study at: "<<study<<endl;
    cout<<"Your inteligence is: "<<inteligence<<endl;
}

int User::calculateLifeExpentence() {
    return User::health - User::age - 10%User::stress;
}


// 100 , 20 , 10