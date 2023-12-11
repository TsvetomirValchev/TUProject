#include <string>
#include <vector>
#include "Department.h"
#ifndef COMPANY_H
#define COMPANY_H

//Class definition of Company
class Company
{
    private:
        // fields of the class
        std::string type;
        bool registered;
        std::vector<Department> departments;

    public:
        // declaration of the constructor
        Company();
        // declaration of the constructor with all fields
        Company(std::string type, bool registered, std::vector<Department> departments);
        // declaration of accessors of all class fields
        std::string getCompanyType();
        bool isRegistered();
        std::vector<Department>& getDepartments();
        //mutator methods that initialize class fields from STDIN
        void setCompanyType();
        void setRegistered();
        void addDepartment(Department &department);
        void setDepartments();
        // method that reads the actual STDIN input for company type, because it requires validation (very specific values of enum class)
        //returns int because its later used in the setCompanyType method
        void requestCompanyType();
        friend std::ostream &operator<<(std::ostream &os, Company &company); // predefining << so that the data in a CompanyWithDepartments can be printed out using cout <<   
};




#endif
