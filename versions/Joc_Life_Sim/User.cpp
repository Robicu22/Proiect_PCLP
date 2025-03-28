#include "User.h"

#include <iostream>

using namespace std;


void User::ShowPlayerStats() {
    cout<<name<<endl;
    cout<<"Your age is: "<<age<<endl;
    cout<<"Your balance: "<<money<<"RON"<<endl;
    cout<<"You make per month: "<<moneyPerMonth<<"RON"<<endl;

}

