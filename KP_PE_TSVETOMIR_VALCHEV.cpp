#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

struct Employee
{
private:
    string name;
    string EGN;
    int YearsOfExperience;
    int workHoursPerDay;
    vector<string> projects;

public:
    Employee() {}

    Employee(string name, string EGN, int expYears, int contractHrs, vector<string> projects)
        : name(name), EGN(EGN), YearsOfExperience(expYears), workHoursPerDay(contractHrs), projects(projects) {}

    friend ostream &operator<<(ostream &os, const Employee &employee);

    string getName() const
    {
        return name;
    }

    string getEGN()
    {
        return EGN;
    }

    int getExperience()
    {
        return YearsOfExperience;
    }

    int getWorkHoursPerDay()
    {
        return workHoursPerDay;
    }

    vector<string> getProjects()
    {
        return projects;
    }

    void setName(string new_name)
    {
        name = new_name;
    }

    void setEGN(string new_EGN)
    {
        EGN = new_EGN;
    }

    void setExperience(int experience)
    {
        YearsOfExperience = experience;
    }

    void setWorkHoursPerDay(int hours)
    {
        workHoursPerDay = hours;
    }

    void addProject(string project)
    {
        projects.push_back(project);
    }

    void displayAllProjects() const
    {
        for (const auto &project : projects)
        {
            cout << project;
        }
    }
    

    
};

ostream& operator<<(ostream& os, const Employee& employee) {
    os << "Employee Name: " << employee.getName() << endl;
    os << "Employee ENG: " << employee.EGN <<  endl;
    os << "Experience " << employee.YearsOfExperience << " year(s)" << endl;
    os << "Is on " << employee.workHoursPerDay << " hour shifts " << endl;
    os << "And participates in: " << endl;
    employee.displayAllProjects();
    return os;
}


struct Department
{
    private:
        string name;
        int numEmployees;
        string creationDate;
        
    public:
        
        Department() {}

        Department(string name, int numEmployees, string creationDate) : 
        name(name), numEmployees(numEmployees), creationDate(creationDate) {}

        string getName() const { return name; }

        friend ostream &operator<<(ostream &os, const Department &department);

        int getNumberOfEmployees()
        {
            return numEmployees;
        }

        string getName()
        {
            return name;
        }

        string getCreationDate() const
        {
            return creationDate;
        }

        void setName(string new_name)
        {
            name = new_name;
        }

        void setNumberOfEmployees(int new_NumberOfEmployees)
        {
            numEmployees = new_NumberOfEmployees;
        }

        void setCreationDate(string date)
        {
            creationDate = date;
        }

        static Department create(){

            string departmentName;        
            cout << "What should the name of the new department be? " << endl;
            cin >> departmentName;
            int numEmployees;
            cout << "How many employees are there in this department? " << endl;
            cin >> numEmployees;
            string creationDate;
            cout << "When was it created? (YYYY-MM-DD) " << endl;
            cin >> creationDate;

            Department department;
            department.setName(departmentName);
            department.setNumberOfEmployees(numEmployees);
            department.setCreationDate(creationDate);
            return department;
        } 
};

ostream& operator<<(ostream& os, const Department& department) {
    os << "Department Name: " << department.name << endl;
    os << "Number of Employees: " << department.numEmployees << endl;
    os << "Creation Date: " << department.creationDate << endl;
    return os;
}

enum CompanyType
{
    ET,
    EOOD,
    OOD,
    AD,
};

struct Company
{
private:
    CompanyType type;
    bool registered;
    vector<Department> departments;

public:
    Company() {}

    Company(CompanyType type, bool isReg)
        : type(type), registered(isReg) {}

    void displayAllDepartments() const
    {
        for (const auto &department : departments)
        {
            cout << department;
        }
    }
    
    friend ostream &operator<<(ostream &os, const Company &department);

    CompanyType getCompanyType()
    {
        return type;
    }

    bool isRegistered()
    {
        return registered;
    }

    void setCompanyType(CompanyType companyType)
    {
        type = companyType;
    }

    void setRegistered(bool isRegistered)
    {
        registered = isRegistered;
    }

    void addDepartment(const Department &department)
    {
        departments.push_back(department);
    }

    static Company create(){
        Company company;
        cout << "Enter company type (0 - ET, 1 - EOOD, 2 - OOD, 3 - ET): ";
        int companyTypeValue;
        cin >> companyTypeValue;
        CompanyType companyType = static_cast<CompanyType>(companyTypeValue);

        bool isRegistered;
        cout << "Is the company registered (1-Yes, 2-No)? ";
        cin >> isRegistered;

        int input = 1;
        
        do
        {
            company.addDepartment(Department::create());
            cout << "Do you want to add a department to your company (1-Yes, 2-No)";
            cin >> input;
        }
        while (input == 1);
            
        company.setCompanyType(companyType);
        company.setRegistered(isRegistered);
        return company;
    }

    void writeCompanyToFile(const string& filename, const Company& company) {
            
        ofstream file(filename);

        if (file.is_open()) {
            file << company;
            file.close();
            cout << "Company data written to file successfully." << endl;
        } else {
            cerr << "Unable to open file." << endl;
        }
    }
};

ostream& operator<<(ostream& os, const Company& company) {
    os << "Comapny type: " << company.type << endl;
    os << "Comapny is registered " << (company.registered ? "Yes" : "No") << endl;
    os << "Departments: " << endl;
    company.displayAllDepartments();
    return os;
}

class MyMenu{

    public:
    void displayMenuOptions(){
        cout << "====== Company Management System ======\n";
        cout << "1. Add Company\n";
        cout << "2. Display All Companies\n";
        cout << "5. Save Company Data to File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";  
    }

    


};

int main()
{
    MyMenu menu;
    menu.displayMenuOptions();
    int choice;
    do
    {
        
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
           Company company = Company::create();
           company.writeCompanyToFile("Company.txt", company);
           break;
        }
        case 2:
            cout << "=== Displaying All Companies ===\n";

            break;
        case 3:
        {
            string filename;
            cout << "Enter file name to save: ";
            cin >> filename;
            break;
        }
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please enter again.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
