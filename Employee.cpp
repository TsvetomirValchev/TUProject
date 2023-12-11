#include "Employee.h"
#include "Constants.h"
#include <iostream>

using namespace std;

// Constructors
Employee::Employee() {
    // constructor implementation
	// the aim is to initialize all class fields using STDIN values, so call the methods that initialize the fields
    setName();
    setEGN();
    setExperience();
    setContractHours();
}

Employee::Employee(string employeeName, string employeeEGN, int expYears, int Hours) {
    // constructor that sets the class fields with the data that has been deserialized from the CompanyManagement persistent storage file
    name = employeeName;
    EGN = employeeEGN;
    contractHours = Hours;
}

// Accessors implementation
string Employee::getName() {
    return name;
}

string Employee::getEGN() {
    return EGN;
}

int Employee::getExperience() {
    return YearsOfExperience;
}

int Employee::getContractHours() {
    return contractHours;
}

vector<string> Employee::getProjects() {
    return projects;
}

void Employee::setName() {
    // implementation for initialization of the name field
    cout << "Enter employee name: ";
    // initialize the name field's value with STDIN input
    cin.ignore(); // ignores \n in cin after cin >> something
	getline(cin, name); // cin >> name would fail if there are whitespaces in the name, so use getline
}

void Employee::setEGN() {
    requestEGN();

    bool allDigits = true;
    //for loop that checks if all characters in the EGN are numbers
    for(char c : EGN){
        if(!isdigit(c)){
            allDigits = false;
            break;
        }
    }

    // checks the conditions for a valid EGN and if either are false 
    //prints an error message and promts the user to enter new values
    while(EGN.length() != Constants::EGN_LENGTH  || allDigits != true){
        cout << "Invalid EGN format. EGN is a 10 digit number!"
        requestEGN();
    }
}

void Employee::requestEGN() {
	cout << "Enter EGN: ";
    cin >> EGN;
}

void Employee::setExperience() {
    cout << "Enter years of experience: ";
    cin >> YearsOfExperience;
}

void Employee::setContractHours(){
    requestContractHours();

    //checks if contract hours are within reasonable limits (less than the hours in a day per day)
    while(contractHours > Constants::HOURS_PER_DAY){
        cout << "Invalid contract hours! Please provide a reasonable amount of time!";
        requestEGN();
    }

}

void Employee::requestContractHours() {
    cout << "Enter contract hours of the employee: ";
    cin >> contractHours;
}

void Employee::addProject(string project) {
    
    char addMore;

    do {
        cout << "Enter project name: ";
        cin >> project;

        // Add the project to the vector
        projects.push_back(project);

        cout << "Add more projects? (y/n): ";
        cin >> addMore;
    } while (tolower(addMore) == 'y');
}

ostream& operator<<(ostream& os,  Employee& employee) {
    os << "Name: " << employee.getName() << endl;
    os << "EGN: " << employee.getEGN() << endl;
    os << "Years of Experience: " << employee.getExperience() << endl;
    os << "Work Hours per Day: " << employee.getContractHours() << endl;
    os << "Projects: ";
    for (auto& project : employee.getProjects()) {
        os << project << ", ";
    }
    os << endl;
    return os;
}
