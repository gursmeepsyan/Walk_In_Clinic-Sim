/* walkIn.cpp
 *
 * Description: Application to allow for the creation, organization, and management of patient files at a walk-in clinic
 *
 * Author: Sehajvir Singh Pannu(301386534), Gursmeep Singh Syan(301386570).
 *
 * Last modified on September 19, 2019
 */

#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

using namespace std;

// Tool for modifying the components of a Patient object (name, address, phone, email)
void modify(Patient & modPatient) {
		bool done = false;
		char entry;
		while (!done) {
		cout << "\nThe information on this patient's file is currently as follows:" << endl;
		cout << modPatient.getCareCard() << " - Patient: " << modPatient.getName() << ", " << modPatient.getAddress() << ", " << modPatient.getPhone() << ", " << modPatient.getEmail() << endl;
		cout << "\n\tTo enter/modify the patient's name, enter 'n'" << endl;
		cout << "\tTo enter/modify the patient's address, enter 'a'" << endl;
		cout << "\tTo enter/modify the patient's phone number, enter 'p'" << endl;
		cout << "\tTo enter/modify the patient's email address, enter 'e'" << endl;
		cout << "\tTo return to the main menu, enter 'm'" << endl;
		cout << "\nYour selection: ";
		cin >> entry;
		entry = tolower(entry);
		switch(entry) {
			case 'n': {
				string modName = "";
				cout << "Please enter the patient's first and last name: ";
				getline(cin >> ws, modName);
				modPatient.setName(modName);
			}
				break;
      		case 'a' : {
      			string modAddress = "";
      			cout << "Please enter the patient's address: ";
      			getline(cin >> ws, modAddress);
      			modPatient.setAddress(modAddress);
      		}
      			break;
      		case 'p': {
      			string modPhone = "";
      			cout << "Please enter the patient's phone number: ";
      			getline(cin >> ws, modPhone);
      			modPatient.setPhone(modPhone);
      		}
      			break;
      		case 'e': {
      			string modEmail = "";
      			cout << "Please enter the patient's email address: ";
      			getline(cin >> ws, modEmail);
      			modPatient.setEmail(modEmail);
      		}
      			break;
      		case 'm': cout << "\nOk, returning to the main menu.\n" << endl; done = true; break;
      		default: cout << "\nUnfortunately, \"" << entry << "\" is not a valid selection. Please, try again!" << endl;
		}
	}
	return;
}

// Tool to look for Patient by care card number in list, aslso gives the user an opportunity to modify personal details
void find(List * clinic) {
	string inputCareCard = "";
	cout << "Enter the Care Card number of the patient you are trying to find: ";
	cin >> inputCareCard;
	if (clinic->search(inputCareCard)) {
		cout << "\nPatient with Care Card number " << inputCareCard << " has been found." << endl;
		Patient *fmPatient = clinic->search(inputCareCard);
		modify (*fmPatient);
		clinic->insert(*fmPatient);
		return;
	}
	else {
		cout << "\nPatient with Care Card number " << inputCareCard << " could not be found." << endl;
		return;
	}
}

// Tool for creating a new patient file, and adding additional personal information
void create(List * clinic) {
	string theCareCard = "";
	char response = 0;
	cout << "Creating a new patient file.\nPlease enter the patient's 10-digit Care Card number: ";
	cin >> theCareCard;
	Patient thePatient(theCareCard);
	if(clinic->insert(thePatient)) {
		cout << "A new patient entry has been created with Care Card number " << thePatient.getCareCard() << ".\nWould you like to enter additional information for this patient? (y/n): ";
		cin >> response;
		response = tolower(response);
		// calls 'modify' function at the command of the user, allowing for modification of patient information
		if (response == 'y') {
			modify(thePatient);
			clinic->insert(thePatient); // updates the list with the modifications, overwriting the previous entry with the most up-to-date information
		}

		else if (response == 'n')
			cout << "Ok.  Returning to main menu." << endl;
		else
			cout << "Not sure what you mean!  Returning to main menu." << endl;
	}
	else
		cout << "A new patient entry could not be created.\nThis may be because the Care Card entered was invalid, or because the database is full.\nPlease note that the database currently contains " << clinic->getElementCount() << " patient files." << endl;
	return;
}

// Tool for removing a patient from the list by calling clinic::remove( const Patient& toBeRemoved )
void remove(List * clinic) {
	string inputCareCard = "";
	cout << "Enter the Care Card number of the patient you are trying to find: ";
	cin >> inputCareCard;
	if (clinic->search(inputCareCard)) {
		cout << "\nCare Card number " << inputCareCard << " has been found." << endl;
		Patient *rmPatient = clinic->search(inputCareCard);
		clinic->remove(*rmPatient);
		cout << "Patient with Care Card number " << inputCareCard << " has been removed." << endl;
		return;
	}
	else {
		cout << "\nPatient with Care Card number " << inputCareCard << " could not be found." << endl;
		return;
	}
}
/*
void remove(List * clinic) {
	Patient rmPatient = *find(clinic);

	return;
} */

// Tool to print list by calling List::printList()
void print(List * clinic) {
	cout << endl;
	clinic->printList();
	return;
}

// Remove all list entries
void removeAll(List * clinic) {
	clinic->removeAll();
	cout << "\nAll patient files have been removed.  The database is empty.\n" << endl;
	return;
}


// Application to allow for the creation, organization, and management of patient files at a walk-in clinic
int main(void) {

	// Declarding variables
	List * clinic = new List;
	bool done = false;
	char input = 0;


	while (!done) {
		// Print menu to user
    cout << "\n\t\t***** Welcome to the Clinic Patient Database *****\n\n" << endl;
    cout << "\tPlease select an option from the menu below:\n\n" << endl;
    cout << "\tf ::: Find and modify a patient file" << endl;
    cout << "\tc ::: Create a new patient file" << endl;
    cout << "\tr ::: Remove a patient file" << endl;
    cout << "\tp ::: Print the list of all patient files by descending Care Card Number" << endl;
    cout << "\ta ::: Remove *all* patient files" << endl;
    cout << "\tx ::: Exit the database" << endl;

    cout << "\nYour selection: ";
    cin >> input;
    input = tolower(input);
    switch(input) {
      case 'f': find(clinic); break;
      case 'c': create(clinic); break;
      case 'r': remove(clinic); break;
      case 'a': removeAll(clinic); break;
      case 'p': print(clinic); break;
      case 'x': cout << "\nYou have exited the Clinic Patient Database.\n" << endl; done = true; break;
      default: cout << "\nUnfortunately, \"" << input << "\" is not a valid selection. Please, try again!" << endl;
    }
    //cout << "There are now " << members->getElementCount() << " members in FriendsBook." << endl;
    //cout << *members << endl;
	}





	}
