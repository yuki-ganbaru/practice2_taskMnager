#include "h.hpp"
using namespace std;

    Work::Work(){};
    void Work::addwork(string n,string d){
       limit_to_work[d][n]=n;
       work_to_limit[n]=d;
    }

    void Work::removework(string n){
        limit_to_work[work_to_limit[n]].erase(n);
        work_to_limit.erase(n);
    }

    map<string,string> Work::getLatestWork(void){
        auto it = limit_to_work.begin();
        return it->second;
    }

    string Work::getWorkLimit(string n){
        return work_to_limit[n];
    }

    map<string,string> Work::getall(void){
        return work_to_limit;
    }