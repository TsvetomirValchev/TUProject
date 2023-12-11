#include <string>
#include <vector>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
    std::string name;
    std::string EGN;
    int YearsOfExperience;
    int contractHours;
    std::vector<std::string> projects;

public:
    //Constructors
    Employee();
    Employee(std::string name, std::string EGN, int expYears, int contractHrs); //with all arguments
    //accessors
    std::string getName();
    std::string getEGN();
    int getExperience();
    int getContractHours();
    std::vector<std::string> getProjects();
    //mutators
    void setName();
    void setEGN();
    void setExperience();
    void setContractHours();
    void requestEGN(); // helper method used to check whether the EGN is 10 symbols
    void requestContractHours(); // helper method used to check whether the contract hours are a number that is adequate.
    void addProject(std::string project); //method that is used to add a project to an employees projects list
    friend std::ostream &operator<<(std::ostream &os, Employee &employee); // redefining of << operator 

};      


#endif