#include <iostream>
#include <unistd.h>
#include "CompanyCollection.h"

using namespace std;

void printCompanyManagementHeader() {
	// implementing a method that prints out on the console the companyManagement application header
	cout << "***************************************************************" << endl;
	cout << "*                      CompanyManagement                      *" << endl;
	cout << "***************************************************************" << endl;
	cout << endl;
}

void printActions() {
	// implementing a method that prints out on the console the companyManagement the available actions for the app
	cout << "+-------------------------------------------------------------+" << endl;
	cout << "|                      Available Actions                      |" << endl;
	cout << "+-------------------------------------------------------------+" << endl;
	cout << "| Action # |                   Description                    |" << endl;
	cout << "+-------------------------------------------------------------+" << endl;
	cout << "|    0     | Exit                                             |" << endl;
	cout << "|    1     | Add a new company                                |" << endl;
	cout << "|    2     | Show all companys' data                          |" << endl;
	cout << "|    3     | Add an employee                                  |" << endl;
	cout << "|    4     | Show all employees                               |" << endl;
	cout << "+-------------------------------------------------------------+" << endl;
	cout << endl;
}

void executeAction(int actionId, CompanyCollection &allCompanies) {
	// method implementation that executes a specified action on a specified companyWithGradesCollection
	// it is important to note that in order to avoid wrongful copying the object, we need an alias to it
	switch(actionId) {
		case 0:
			exit(0); // the user has chosen to quit
		case 1:
			allCompanies.addNewCompanyToCollection(); // the user has chosen to add a new company
			break;
		case 2:
			allCompanies.printcompanysData(); // the user has chosen to print all companys'data
			break;
		case 3:
			// the user has chosen to add a new employee to the employee file
			
			break;
		case 4:
			// the user has chosen to print all employees
			
			break;
	}
	cout << endl << "---------------        Action complete.         ---------------" << endl << endl; // finish off by letting the user know that the action execution has finished
	sleep (2); // sleep for 2 seconds so that the user can see the result of the action
}

int main(int argc, char *argv[]) {
	CompanyCollection allCompanies; // create a CompanyCollection object which we'll use later
	// also this object creation will deserialize and load all companies from the persistence file into the collection
	printCompanyManagementHeader(); // print the app header
	int actionChosen; // a variable that will be used to hold the action chosen by the user
	while(true) { // the application is basically active forever - until the user closes it or picks option 0
		printActions(); // print the list of actions
		cout << "Choose an action (0-4): ";
		cin >> actionChosen;
		if(actionChosen < 0 || actionChosen > 4) {
			// invalid action, print out the error message and continue to the next iteration
			cout << "Invalid action number." << endl << endl;
			continue;
		}
		cout << endl;
		executeAction(actionChosen, allcompanys); // pass apart from the chosen action ID, the companyWithGradesCollection because all actions have to be executed on the collection
	}
	return 0;
}