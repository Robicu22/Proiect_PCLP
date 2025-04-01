#ifndef JOBS_H
#define JOBS_H

#include<unordered_map>
#include<string>

using namespace std;

class Jobs {
public:
    unordered_map<string,int> salaries={{"Barista",3000*12},{"Engineer_Junior",10000*12},{"Engineer_Senior",30000*12},{"Doctor",29000*12}};
    unordered_map<string,int> inteligent_req={{"Barista",20},{"Engineer_Junior",60},{"Engineer_Senior",80},{"Doctor",79}};
    unordered_map<string,int> sterssLevelPerWork = {{"Barista",1},{"Engineer_Junior",5},{"Engineer_Senior",10},{"Doctor",20}};

    void Work(string job);
};



#endif //JOBS_H
