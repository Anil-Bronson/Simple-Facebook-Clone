/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Anil Bronson
 * Date: 29/01/22
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include <locale>
#include "Patient.h"

using namespace std;

  
Patient::Patient() {
	name = "To be entered";
	address = "To be entered";
	phone= "To be entered";
	email = "To be entered";
	careCard = "0000000000";
}


Patient::Patient(string aCareCard) {
	//cout << "Pateint aCareCard has been called" << endl;
	//checks if careCard has 10 digits
	if(aCareCard.length() < 10){
		cout << "careCard length needs to be 10! set to 00000000000" << endl;
		this->careCard = "0000000000";
	}
	//else sets it to aCareCard
	else{
	this->careCard = aCareCard;
	}

	name = "To be entered";
	address = "To be entered";
	phone= "To be entered";
	email = "To be entered";
}

void Patient::setName(const string aName){
	locale loc;
	//code referenced from friendsbook
	if (!aName.empty() && (isalpha(aName[0], loc)))
		name = aName;
	else
		name = "To_Be_Named";  
}

void Patient::setAddress(const string anAddress){
	address = anAddress;
}

void Patient::setPhone(const string aPhone){
	phone = aPhone;
}

void Patient::setEmail(const string anEmail){
	email = anEmail;
}
// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();
	
} // end of operator >

// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is < the care card 
//              number of "rhs" Patient object.
bool Patient::operator < (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard < rhs.getCareCard();
	
} // end of operator <

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
	os << p.careCard << " - Patient: " << p.name << ", "
	   << p.address << ", " << p.phone << ", " << p.email << endl;  
	     
	return os;

} // end of operator<<

// end of Patient.cpp