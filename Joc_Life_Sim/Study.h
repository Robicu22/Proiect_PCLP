#ifndef STUDY_H
#define STUDY_H
#include <unordered_map>
#include<string>

using namespace std;

class Study {
    public:
    unordered_map<string,int> studyAt={{"kindergarden",4},{"school",7},{"highschool",15},{"university",19}};//<name,age>
    unordered_map<string,int> uniSpec ={{"engineer",8},{"medical",10},{"law",7},{"finnance",3}};//<name,inteligence>
    unordered_map<string,int> sterssLevelPerSession ={{"engineer",15},{"medical",22},{"law.txt",10},{"finnance",-5}};//<name,stress>
    unordered_map<string,int> inteligent_req={{"Engineering",80},{"Medical",79}};//<name,intel>

    int kind=0,school=0,high=0,uni=0;

    void StudyHard();
    void ChoseUniversity();
    void interviewMedical();
};



#endif //STUDY_H
