//
// Created by robicu on 3/29/25.
//

#include "Jobs.h"
#include "User.h"

#include <iostream>

extern User user;

void Jobs::Work(string job) {
    cout<<"You are working as a: "<<job<<"\n";
    if(Jobs::salaries.count(job) != 0) {
        while (true) {
           user.age = user.age + 1;
            user.money += Jobs::salaries[job];
            cout<<"You earned "<< Jobs::salaries[job]<< " RON this year! \n"
                <<"You now have "<<user.money<<" RON'\n"
                <<"Do you wish to work for another year? Type yes or no \n";
            string answer;
            while (true) {
                cin>>answer;
                if (answer == "yes")
                    break;
                else if (answer == "no") {
                    return;
                }
                else
                    cout<<"Please enter a valid option\n";
            }

            //user.lifeExpentence = user.calculateLifeExpentence();
            if (user.age >= 60)//user.lifeExpentence
                return;
        }
    }
    else
        cout<<"Esti somer varule";
}