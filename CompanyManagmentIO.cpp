#include <string>
#include <fstream>
#include "Constants.h"
#include "CompanyManagmentIO.h"

using namespace std;

namespace CompanyManagementIO {
    // Writing content to a file
    void writeToFile(string content) {
        ofstream persistentStorage(Constants::COMPANY_MANAGEMENT_STORAGE_FILE.c_str()); // opening an output stream to write to a file that is used as persistentStorage
        
        if (!persistentStorage.is_open()) {
            cout << "Cannot open " << Constants::COMPANY_MANAGEMENT_STORAGE_FILE << " for writing!" << endl;
			exit(1);   
        }

        // Successfully wrote to the file
        persistentStorage << content;
        persistentStorage.close();
    }

    // Reading content from a file
    string readFromFile() {
        ifstream persistentStorage(Constants::COMPANY_MANAGEMENT_STORAGE_FILE.c_str()); // opening an input stream to read from a file that is used as persistentStorage
        
        string content;
        if(!persistentStorage.is_open()) {
			// if the file is not open, no need to exit, we can just return an empty string as we really cannot check in C++ if the file exists
			return "";
		}
		
		stringstream strStream; // A stringstream that we will fill with the contents of the file
		strStream << persistentStorage.rdbuf(); // read the file
		// a good practice is to always close the file
		persistentStorage.close();
		return strStream.str(); // stringStream
    }
}
