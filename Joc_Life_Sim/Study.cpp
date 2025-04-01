
#include "Study.h"

#include <iostream>

#include "User.h"

extern User user;


void Study::StudyHard(string study) {
    study = user.study;
    user.age +=1;
    user.inteligence+=1;
    if (user.study=="university") {
        user.inteligence+= uniSpec[user.study];
        user.stress +=sterssLevelPerSession[user.uniSpec];
    }else {
        user.inteligence+= studyAt[user.study];
    }

}
void Study::ChoseUniversity() {
    cout<<"Chose one option if you have the inteligence for it: \n";
    cout<<"inteligence: "<<user.inteligence<<"\n";
    cout<<"1. Engineer inteligence: 60\n"
        <<"2. Medical  inteligence: 70\n"
        <<"3. Law      inteligence: 65\n"
        <<"4. Finnance inteligence: 50\n";
}