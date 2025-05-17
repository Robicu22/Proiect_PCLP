#ifndef STORY_H
#define STORY_H
#include <string>
#include<unordered_map>
#include <vector>

using namespace std;

class Story {
    public:
        vector<pair<int,string>> Posible_Activites={{1,"Wait a year"},{0,"Study"},{0,"Work"},{0,"shop"},{0,"Inventory"},{0,"Casino"},{0,"Partner"},{0,"Check stats"}};
        //vector<int> Posible_Activities;
    
        void Activity();
};



#endif
