#include "Company.h"
#include "Department.h"
#include <vector>
#include <string>
#ifndef COMPANYCOLLECTION_H
#define COMPANYCOLLECTION_H

//Class definition of 
class CompanyCollection
{
    private:
        //only field of the class a Collection of Departments
        std::vector<Company> companyCollection;
        // also, we do not need an accessor for this field, as all operations with CompanyCollection should be done in this class
    public:
        CompanyCollection();
        std::string serializeCompanyCollection(); // a method that returns a serialized CompanyCollection
		std::string serializeCompanyData(Company* company); // a method that returns a serialized Company
        void persistCompanyCollection(); // a method that persists the serialized CompanyCollection
		void deserializeCompanyCollection(std::string serializedCompanyCollection); // a method that deserializes a serialized CompanyCollection and adds the Company elements to the CompanyCollection
		void deserializeCompanyData(std::string companyData); // a method that deserializes a serialized company
		void addNewCompanyToCollection(); // a method that creates a new CompanyWithDepartments object and then pushes it to the companyCollection vector
		void printCompanyData(); // a method that prints the data for all CompanyWithDepartments in companyCollection + their departments
		
};

#endif