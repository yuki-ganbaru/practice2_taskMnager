#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>
class Work{
    public:
    std::map<std::string,std::string> work_to_limit;
    std::map<std::string,std::map<std::string,std::string>> limit_to_work;
    Work();
    void addwork(std::string,std::string);
    void removework(std::string);
    std::map<std::string,std::string> getLatestWork(void);
    std::string getWorkLimit(std::string n);
    std::map<std::string,std::string> getall(void);
};