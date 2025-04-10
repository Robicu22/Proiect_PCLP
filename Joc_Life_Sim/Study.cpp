#include "Study.h"
#include "User.h"
#include "QualityTools.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

extern User user;
extern QualityTools qualityTools;


void Study::StudyHard() {
    string study = user.study;
    if (user.age <=3) {
        cout<<"You are to young to study try when you are a bit older (4 years old)!!\n";
        return;
    }
    if (study == ""&&kind ==0&&user.age>=studyAt["kindergarden"]) {
        study = "kindergarden";
        user.study=study;
        kind++;
    }else {

        if (user.age>=studyAt["School"]&& kind >=3) {
            user.study="School";
            school++;
            user.inteligence++;
        }
        if (user.age>=studyAt["Highschool"]&& school >=8) {
            user.study="Highschool";
            high++;
            user.inteligence++;
        }
        if (user.age>=studyAt["University"]&& high >=4&&uni ==0) {
            user.study="University";
            uni++;
            user.inteligence++;
            ChoseUniversity();
        }
        if (user.study=="kindergarden") {
            kind++;
        }
        if (user.study=="school") {
            school++;
        }
        if (user.study=="highschool") {
            high++;
        }
    }
    user.age +=1;
    user.inteligence+=1;
    if (user.study=="university"&&uni<=3) {
        user.inteligence+= uniSpec[user.study];
        user.stress +=sterssLevelPerSession[user.uniSpec];
        uni++;
    }else {
        user.inteligence+= studyAt[user.study];
        user.degree.push_back(user.uniSpec);
        user.uniSpec="";
    }

}
void Study::ChoseUniversity() {
    if (user.inteligence< 40) {
        cout<<"You are not smart enough yet keep studing";
        user.study="trying to apply to uni";
        return;
    }
    cout<<"Chose one option if you have the inteligence for it: \n";
    cout<<"inteligence: "<<user.inteligence<<"\n";
    cout<<"1. Engineer inteligence: 60\n"
        <<"2. Medical  inteligence: 70\n"
        <<"3. Law      inteligence: 65\n"
        <<"4. Finnance inteligence: 50\n";
}

void Study::interviewMedical() {

    ifstream medicalRead("intrebari/medical.txt");
    vector<pair<string,vector<string>>> interviewMedicalQuestions;
    for (int i = 0; i < 70; i++) {
        string question;
        vector<string> responses;
        getline(medicalRead, question);
        for (int j = 0; j < 4; j++) {
            string response;
            getline(medicalRead, response);
            responses.push_back(response);
        }
        interviewMedicalQuestions.push_back(make_pair(question, responses));
    }


    // for (int i = 0; i < 70; i++) {
    //     cout<<interviewMedicalQuestions[i].first<<endl;
    //     cout<<interviewMedicalQuestions[i].second[0]<<endl;
    //     cout<<interviewMedicalQuestions[i].second[1]<<endl;
    //     cout<<interviewMedicalQuestions[i].second[2]<<endl;
    //     cout<<interviewMedicalQuestions[i].second[3]<<endl;
    // }


    medicalRead.close();
    auto rng = default_random_engine{};
    ranges::shuffle(interviewMedicalQuestions, rng);

    int correctResponses = 0, cursingLevel = 0;

    if (user.inteligence < Study::inteligent_req["Medical"]) {
        cursingLevel = Study::inteligent_req["Medical"]-user.inteligence;
    }

    for (int i = 0; i < 30; i++) {
        string question;
        question.append(interviewMedicalQuestions[i].first, 0, interviewMedicalQuestions[i].first.size()-2);
        char correct = interviewMedicalQuestions[i].first[interviewMedicalQuestions[i].first.size() - 1];
        question = qualityTools.curse(question, cursingLevel);
        cout<<i+1<<": "<<question<<endl;
        cout<<interviewMedicalQuestions[i].second[0]<<endl;
        cout<<interviewMedicalQuestions[i].second[1]<<endl;
        cout<<interviewMedicalQuestions[i].second[2]<<endl;
        cout<<interviewMedicalQuestions[i].second[3]<<endl;
        cout<<"Psst raspunsul corect este "<< correct<<endl;
        char response;
        cin>>response;

        if (response == correct) {
            cout<<"Ai raspuns bine rege \n";
        }
        else
            cout<<"Esti fraier \n";
    }

}