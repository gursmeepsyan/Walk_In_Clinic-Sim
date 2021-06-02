/*
 * Patient.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 *
 * Author: Sehajvir Singh Pannu (301386534), Gursmeep Singh Syan (301386570)
 * Date: 16/09/2019
 */

#include <iostream>
#include <string>
#include "Patient.h"

// Default Constructor
// Description: Create a patient with a care card number of "0000000000".
// Postcondition: All data members set to "To be entered",
//                except the care card number which is set to "0000000000".
Patient::Patient()
{

        careCard = "0000000000";
        name = "To be entered";
        address = "To be entered";
        emailAddress = "To be entered";
        phoneNumber = "To be entered";

}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard)
{

  int index = 0;
	bool isNum = true;
	locale loc;
	while (isNum == true && index < 10) {
		isNum = isdigit(aCareCard[index], loc);
		index++;
	}
	if(aCareCard.length() == 10 && isNum == true)
		careCard = aCareCard;
	else
		careCard = "0000000000";
	name = "To be entered";
	address = "To be entered";
	phoneNumber = "To be entered";
	emailAddress = "To be entered";

}

// Parameterized Constructor
// Description: Create a patient with the given care card number, Name, Address, PhoneNumber,EmailAddress
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//
Patient::Patient(string aCareCard,string Name,string Address, string PhoneNumber, string EmailAddress)
{
  // Confirm the Care Card is valid before entering (i.e. 10 characters, all digits)
  int index = 0;
	bool isNum = true;
	locale loc2;
	while (isNum == true && index < 10) {
		isNum = isdigit(aCareCard[index], loc2);
		index++;
	}
	if(aCareCard.length() == 10 && isNum == true)
		careCard = aCareCard;
	else
		careCard = "0000000000";
	// Check to ensure name is valid (i.e. non-empty; starts with a letter)
	locale loc;
	if ( !Name.empty() && (isalpha(Name[0], loc)) )
		name = Name;
	else
		name = "To be entered";
	// Check to ensure address is non-empty
	if ( !Address.empty())
		address = Address;
	else
		address = "To be entered";
	// Check to ensure phone is non-empty
	if ( !PhoneNumber.empty())
		phoneNumber = PhoneNumber;
	else
		phoneNumber = "To be entered";
	// Check to ensure email is non-empty
	if ( !EmailAddress.empty())
		emailAddress = EmailAddress;
	else
		emailAddress = "To be entered";
}

// Description: Returns patient's address.
string Patient :: getName() const
{
  return name;
}
// Description: Returns patient's address.
string Patient :: getAddress() const
{
  return address;
}

// Description: Returns patient's phone.
string Patient :: getPhone() const
{
  return phoneNumber;
}

// Description: Returns patient's email.
string Patient :: getEmail() const
{
  return emailAddress;
}

// Description: Returns patient's care card.
string Patient :: getCareCard() const
{
  return careCard;
}

// Description: Sets the patient's name.
void Patient :: setName(const string aName)
{
  locale loc;
  if( !aName.empty() && (isalpha(aName[0],loc)) )
          name = aName;
  else
          name = "To be entered";
}

// Description: Sets the patient's address.
void Patient :: setAddress(const string anAddress)
{
    address = anAddress;
}

// Description: Sets the patient's phone.
void Patient :: setPhone(const string aPhone)
{
  phoneNumber = aPhone;
}

// Description: Sets the patient's email.
void Patient :: setEmail(const string anEmail)
{
  emailAddress = anEmail;
}
// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs)
{

	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();

} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs)
{

	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();

} // end of operator >

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p)
{

	os << p.careCard << ", Patient: " << p.name << ", "
	   << p.address << ", " << p.phoneNumber << ", " << p.emailAddress << endl;

	return os;

} // end of operator<<

// end of Patient.cpp
