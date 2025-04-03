#include "Study.h"

#include <iostream>

#include "User.h"

extern User user;


void Study::StudyHard() {
    string study = user.study;
    if (study == ""&&kind ==0) {
        study = "kindergarden";
        user.study=study;
        kind++;
    }else {
        if (user.age>=studyAt["School"]&& kind ==3) {
            user.study="School";
        }
        if (user.age>=studyAt["Highschool"]&& school ==3) {
            user.study="Highschool";
        }
        if (user.age>=studyAt["University"]&& high ==3&&uni ==0) {
            user.study="University";
            ChoseUniversity();
        }
    }
    user.age +=1;
    user.inteligence+=2;
    if (user.study=="university") {
        user.inteligence+= uniSpec[user.study];
        user.stress +=sterssLevelPerSession[user.uniSpec];
    }else {
        user.inteligence+= studyAt[user.study];
    }

}
void Study::ChoseUniversity() {
    if (user.inteligence> 40) {
        cout<<"You are not smart enough yet keep studing";
        return;
    }
    cout<<"Chose one option if you have the inteligence for it: \n";
    cout<<"inteligence: "<<user.inteligence<<"\n";
    cout<<"1. Engineer inteligence: 60\n"
        <<"2. Medical  inteligence: 70\n"
        <<"3. Law      inteligence: 65\n"
        <<"4. Finnance inteligence: 50\n";
}