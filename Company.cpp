#include <iostream>
#include "Company.h" // include Company class header file with class declarations in order to implement them in this file

using namespace std;

Company::Company() {
	// constructor implementation
	// the aim is to initialize all class fields using STDIN values, so call the methods that initialize the fields
	setCompanyType();
    setRegistered();
    setDepartments();
}

Company::Company(string companyType, bool isCompanyRegistered, vector<Department> departments) {
	// constructor that sets the class fields with the data that has been deserialized from the CompanyManagement persistent storage file
	type = companyType;
    registered = isCompanyRegistered;
    this->departments = departments;
}

string Company::getCompanyType(){
    //accessor implementation for the companyType field
    return type;
}

bool Company::isRegistered(){
    //accessor implementation for the registered field
    return registered;
}

vector<Department>& Company::getDepartments() {
    return departments;
}

void Company::setCompanyType(){
    // implementation for initialization of the company type field
	// request first STDIN input and then validate it
    requestCompanyType();

    while (type == "ET" || type == "EOOD" || type == "OOD" || type == "ET"){ //checks if the value is okay
        // validation failed, re-request company type value
		cout << "The company type has to be one of the listed values ( use the number infront of the value )." << endl;
		requestCompanyType();
    }
};

void Company::setRegistered(){
    // implementation for initialization of the groupId field
	cout << "is the company registered? : ";
	// initialize the groupId field's value with STDIN input
	cin >> registered;

};



void Company::setDepartments() {
    char addMoreDepartments = 'y';

    while (addMoreDepartments == 'y' || addMoreDepartments == 'Y') {
        Department department;
        addDepartment(department);

        cout << "Do you want to add another department? (y/n): ";
        cin >> addMoreDepartments;
        cin.ignore(); // Ignore newline character after reading character
    }
}

void Company::addDepartment(Department &department){
    departments.push_back(department);
};

void Company::requestCompanyType() {
    // Prompt the user to enter a value corresponding to a string
    cout << "Enter company type (ET, EOOD, OOD, ET): ";

    // Read the user input for company type value from the console
    cin >> type;

}

ostream& operator<<(ostream& os, Company& company) {
    os << "Company Type: " << company.getCompanyType() << endl;
    os << "Registered: " << (company.isRegistered() ? "Yes" : "No") << endl;
    os << "Departments: " << endl;
    // Print details of each department
    for (auto& department : company.getDepartments()) {
        // Assuming Department has its own operator<< overload
        os << department << endl;
    }
    return os;
}
