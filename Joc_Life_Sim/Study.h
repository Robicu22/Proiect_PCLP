#ifndef STUDY_H
#define STUDY_H
#include <unordered_map>
#include<string>

using namespace std;

class Study {
    public:
    unordered_map<string,int> studyAt={{"kindergarden",4},{"school",7},{"highschool",14},{"university",18}};//<name,age>
    unordered_map<string,int> uniSpec ={{"engineer",8},{"medical",10},{"law",7},{"finnance",3}};//<name,inteligence>
    unordered_map<string,int> sterssLevelPerSession ={{"engineer",15},{"medical",22},{"law",10},{"finnance",-5}};//<name,stress>

    int kind=0,school=0,high=0,uni=0;

    void StudyHard();
    void ChoseUniversity();
};



#endif //STUDY_H
