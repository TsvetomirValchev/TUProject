#include <string>
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {

	// constants that can be used in all classes
    const unsigned short EGN_LENGTH = 10;
	const unsigned short HOURS_PER_DAY = 24;
	const std::string COMPANY_MANAGEMENT_STORAGE_FILE = "CompanyManagement.mgmt"; // file is used for persistent storage of CompanyWithDepartments collection
	const std::string COMPANY_MANAGEMENT_FILE_DELIMITER = "\n---------------------------------------------------------------\n"; // delimiter that separates each serialized Comapanies
	const std::string DEPARTMENT_DELIMITER ="---\n";
}

#endif