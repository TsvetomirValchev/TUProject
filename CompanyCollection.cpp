#include <iostream>
#include <sstream>
#include <cmath>
#include "Company.h"
#include "CompanyManagmentIO.h"
#include "Constants.h"
#include "CompanyCollection.h"

using namespace std;

CompanyCollection::CompanyCollection() {
	// constructor implementation
	// read the data from the file that is used as persistent storage
	string serializedCompanies = CompanyManagmentIO::readFromFile();
	// deserialize the data from the file and push the companies to the companyCollection vector
	deserializeCompanyCollection(serializedCompanies);
}

void CompanyCollection::deserializeCompanyCollection(string serializedCompanyCollection) {
	if(serializedCompanyCollection.empty()) {
		// if serializedCompanyCollection is empty, nothing to deserialize
		return;
	}
	// time to iterate over the serialized data - first split it by Constants::COMPANY_MANAGEMENT_FILE_DELIMITER
	size_t pos = 0; // a variable that will hold the current position when iterating over the data
	string token; // a variable that will hold the data for each iteration
	while(serializedCompanyCollection.find(Constants::COMPANY_MANAGEMENT_FILE_DELIMITER) != string::npos) { // iterating until the delimiter is no longer available
		pos = serializedCompanyCollection.find(Constants::COMPANY_MANAGEMENT_FILE_DELIMITER); // assign pos to the current first occurence of the delimiter
		// string::npos, per the documentation: "As a return value, it is usually used to indicate no matches."
	    token = serializedCompanyCollection.substr(0, pos); // get the substring from 0 to the first occurence of the delimiter
	    deserializeCompanyData(token); // a method that deserializes the data for each company
	    serializedCompanyCollection.erase(0, pos + Constants::COMPANY_MANAGEMENT_FILE_DELIMITER.length()); // delete from the data from 0 to the first occurence of the delimiter + the delimiter
	}	
}

void CompanyCollection::deserializeCompanyData(string companyData) {
    string type; // a variable that will hold the student name
	bool registered; // a variable that will hold the boolean value for whether a company is registered
	std::vector<Department> departments; // a new vector that will be assigned to the company vector that hold departments


    stringstream strStream(companyData);
    string token;
    int dataIndex = 0;

    while (getline(strStream, token, '\n')) {
        stringstream strCaster;
        strCaster << token;
        switch (dataIndex) {
            case 0:
                type = token; //it's already a string
                break;
            case 1:
                strCaster >> registered;
                break;
            case 2:
				
                break;
        }
        dataIndex++;
       
        Company *deserializedCompany = new Company();
        companyCollection.push_back(deserializedCompany);
    }
}

string CompanyCollection::serializeCompanyCollection() {
	stringstream serializedCompanyCollectionStream; // create a stream that will hold all the serialized companyCollection data
	for(size_t i = 0; i < companyCollection.size(); i++) { // iterate through the companysCollection vector
		serializedCompanyCollectionStream << serializeCompanyData(companyCollection[i]); // push the data for each company to the stream
	}
	return serializedCompanyCollectionStream.str(); // return the contents in the stream as a string
}

string CompanyCollection::serializeCompanyData(Company *company) {
	stringstream serializedCompanyDataStream; // create a stream that will hold the serialized Company data
	// push each field's value on a new line in the string
	serializedCompanyDataStream << company->getCompanyType() << "\n";
    serializedCompanyDataStream << (company->isRegistered() ? "yes" : "no") << "\n";
    serializedCompanyDataStream << "Departments:\n";
    
    // Serialize each department with delimiters
    for (auto& department : company->getDepartments()) {
        serializedCompanyDataStream << department.serializeDepartment();
    }
	
	// finish off the serialized data with the delimiter
	serializedCompanyDataStream << Constants::COMPANY_MANAGEMENT_FILE_DELIMITER;
	
	return serializedCompanyDataStream.str(); // return the contents in the stream as a string
}

void CompanyCollection::persistCompanyCollection() {
	CompanyManagmentIO::writeToFile(serializeCompanyCollection()); // gets the serialized companys collection and writes it to the file, simple as that
}

void CompanyCollection::addNewCompanyToCollection() {
	Company *company = new Company(); // create a pointer to a new company object
	companyCollection.push_back(company); // push the newly created company to the companyCollection vector
	persistCompanyCollection(); // when a new company is added, it has to be added to the persistence file as well
}

void CompanyCollection::printCompanyData() {
	if(!companyCollection.size()) {
		// if there are no companys, let the user know about that fact
		cout << "There are no users currently available in companyManagement." << endl;
		return; // no need to continue the method execution
	}
	
	for(size_t i = 0; i < companyCollection.size(); i++) { // iterate over companysCollection
		Company *company = companyCollection[i];
		// print out the data for each companyWithGrades using the predefined << operator in company
		cout << *company << endl;
		// print out the companies delimiter for the persistence file for prettier output
		cout << Constants::COMPANY_MANAGEMENT_FILE_DELIMITER;
	}
}