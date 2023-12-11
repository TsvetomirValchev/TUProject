#include <string>
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department
{
    private:
        std::string name;
        int numEmployees;
        std::string creationDate;
        
    public:
    
        Department(); //empty constructor
        Department(std::string name, int numEmployees, std::string creationDate); // constructor that initializes all fields of the Department class
        //accessors
        std::string getName();
        int getNumberOfEmployees();
        std::string getCreationDate();
        //mutators that take input from STDIN
        void setName();
        void setNumberOfEmployees();
        void setCreationDate();
        void requestCreationDateInput();
        friend std::ostream &operator<<(std::ostream &os, Department &department);// predefining << so that the data in a Department can be printed out using cout <<
        std::string serializeDepartment();
        void deserializeDepartment(std::string& serializedData);

};


#endif