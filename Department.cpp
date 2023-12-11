#include "Department.h"
#include "Constants.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructors
Department::Department() {
    // constructor implementation
	// the aim is to initialize all class fields using STDIN values, so call the methods that initialize the fields
    setName();
    setNumberOfEmployees();
    setCreationDate();
}

Department::Department(string depName, int numOfEmployees, string date){
    // constructor that sets the class fields with the data that has been deserialized from the CompanyManagement persistent storage file
    name = depName;
    numEmployees = numOfEmployees; 
    creationDate = date;
}

// Accessors
string Department::getName() {
    return name;
}

int Department::getNumberOfEmployees() {
    return numEmployees;
}

string Department::getCreationDate() {
    return creationDate;
}

// Mutators using STDIN for input
void Department::setName() {
    cout << "Enter the name of the department: ";
    cin >> name;
}

void Department::setNumberOfEmployees() {
    cout << "Enter the number of employees of the department: ";
    cin >> numEmployees; 
}

void Department::setCreationDate() {
    requestCreationDateInput();

    string date = getCreationDate();
    // Check if the date string has the correct format (YYYY-MM-DD)
    if (!(date.length() == 10 &&
        date[4] == '-' && date[7] == '-' &&
        isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) &&
        isdigit(date[5]) && isdigit(date[6]) &&
        isdigit(date[8]) && isdigit(date[9]))) {

        cout << "Invalid date format. Please use YYYY-MM-DD format." << endl;
        requestCreationDateInput();
    }
}


void Department::requestCreationDateInput(){
    cout << "Please enter the creation date of the department: " << endl;
    cin >> creationDate;
}

ostream& operator<<(ostream& os, Department& department) {
    os << "Department Name: " << department.getName() << endl;
    os << "Number of Employees: " << department.getNumberOfEmployees() << endl;
    os << "Creation Date: " << department.getCreationDate() << endl;
    return os;
}

string Department::serializeDepartment(){
    ostringstream serializedData;
    // Serialize each member of the Department class to a string
    serializedData << getName() << "\n";
    serializedData << getNumberOfEmployees()<< "\n";
    serializedData << getCreationDate() << "\n";
    serializedData << Constants::DEPARTMENT_DELIMITER;
    return serializedData.str();
}

void Department::deserializeDepartment(string& serializedData) {
    istringstream strStream(serializedData);
    string token;
    int dataIndex = 0;

    while (getline(strStream, token, '\n')) {
        // Deserialize each piece of data from the serialized string and assign it to the corresponding member of the Department class
        switch (dataIndex) {
            case 0:
                name = token;
                break;
            case 1:
                numEmployees = stoi(token);
                break;
            case 2:
                creationDate = token;
                break;
        }
        dataIndex++;
    }
}

