#include "Story.h"
#include "Casino.h"
#include "User.h"
#include"Jobs.h"
#include"Study.h"

#include <iostream>



using namespace std;
extern  Casino casino;
extern User user;
extern Jobs jobs;
extern Study study;

/*vector<int> Make_Activities(unordered_map<string,int> pos) {
    vector<int> res;
    for (auto i : pos) {
        res.push_back(i.second);
    }
    return res;

}*/

void Story::Activity() {
    if (!user.alive)return;
    int choice;
    cout<<"\nWhat would you like to do?\n";
    for (int i=0;i<Posible_Activites.size();i++) {
        if (Posible_Activites[i].first == 1) {
            cout<<i<<". "<<Posible_Activites[i].second<<endl;
        }
    }

    cin>>choice;

    switch(choice) {
        case 0:
            if (user.checkIfYouWannaKys()) {Story::Activity();return;}
            cout<<"You skipeda year!\n";
            user.age++;
            user.inteligence++;
            break;
        case 1:
            if (user.checkIfYouWannaKys()) {Story::Activity();return;}
            study.StudyHard();
            break;
        case 2:
            if (user.checkIfYouWannaKys()) {Story::Activity();return;}
            if (user.ocupation=="") {
                cout<<"You dont have a job!";
                break;
            }
            jobs.Work();
            break;
        case 3:
            if (user.checkIfYouWannaKys()) {Story::Activity();return;}
            casino.ShowGames();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 1000: {

        }
        default:cout<<"Wrong input!!!\n";break;
    }
}

/*
 0: skip year
 1: study
 2: work
 3: shop
 4: invetory
 5: casino
 6: partner
 7: check stats

 */
/*
void Activites() {
    cout<<"What would you like to do?\n";

    if (1 == 2) {
        cout<<"piticule baga banii in masini nu in masinarii\n";

    }
    else {

        cout<<"0. wait\n"
            <<"1. Gamble\n"
            <<"2. Work\n"
            <<"3. Get a job"
            <<"4. Study\n"
            <<"5. Just die u fucking twat\n"
            <<"6. Check stats\n";

        int choice;
        cin>>choice;
        switch (choice) {
            case 0: {

            }
            case 1: {
                casino.ShowGames();
                break;
            }
            case 2: {

            }
            case 3: {
                jobs.GetAJob();
            }
            case 4:


            case 5: {
                user.alive = false;
                break;
            }
            case 6: {
                user.ShowPlayerStats();
            }
        }
    }

}*/

//adictii (16 ani alege 1)
    //fumat -2strs,-1000 bani//70-hp(primesti aura de fumator)
    //alcool<3 -3int/an -1000$$//70-hp (primesti puncte x1.1)
    //droage -3stress -5int - 4000 //50// rehab (scapi de adicite) -10000$
    //zahar -1stres -5000$//75hp
//18
/*  GAMBLE
 *  FACULTA (int/an)
 *  JOB (ceva mic)
 *  Partener -Bani, +Mij
 */
//+30
/*
 * Copii -bani ++stress +Pct
 * Nevasta -bani ++stress +Pct
 * Divort +bani --stress -Bani copii
 */
//FINAL
/*
    Mori....
        Primesti puncte
        -Numele +10char +=69pct
        per an trait +=100
        1pct/1000$
        per copil +=5000
        Partener +=2000
        Gamble +1 per win si -1 per lose
        Per int +=10
        job/faculta/per an+= niste puncte


*/