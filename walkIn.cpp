// MAIN FILE 
#include <iostream>
#include <string>
#include <cctype>
#include "Patient.h"
#include "List.h"

using namespace std;

void join(List * theMembers) {
  
  string careCard = "";
  string name = "";
  string ad = "";
  string ph = "";
  string em = "";
  // Create a new member profile
  cout << "Please, enter your careCard number: "; 
  getline(cin >> ws, careCard);
  
  Patient theMember(careCard);

  // Add new member profile to the end of list
  cout << "Please enter your name: ";
  getline(cin >> ws, name);
  theMember.setName(name);

  cout << "Please enter your address: ";
  getline(cin >> ws, ad);
  theMember.setAddress(ad);

  cout << "Please enter your phone: ";
  getline(cin >> ws, ph);
  theMember.setPhone(ph);

  cout << "Please enter your email: ";
  getline(cin >> ws, em);
  theMember.setEmail(em);

  theMembers->insert(theMember);

  cout<< theMember << " has successfully joined the walkIn." << endl;
  
  return;
}


void search(List * theMembers){
  string careCard = "";

  cout << "please enter the member you are trying to search (careCard #): ";
  getline(cin >> ws, careCard);
  
  if(theMembers->search(careCard))
    cout << "has been found." << endl;
  return;
}


void leave(List * theMembers){
  string careCard = "";

  cout << "please enter the members careCard you are trying to remove: ";
  getline(cin >> ws, careCard);
  
  Patient theMember(careCard);

  if(theMembers->remove(careCard))
    cout << "member has been removed." << endl;

  return;
}

//uses the search function to get a pointer to a specific pateint, then gives the option to modify
void modify(List * theMembers) {
	string careCard = "";
  char input;
  string choice;
  cout << "please enter the member you are trying to modify (careCard #): ";
  getline(cin >> ws, careCard);
  
  Patient* Member;

  Member = theMembers->search(careCard);
  cout << "To change your Name\t  enter: a" << endl;
  cout << "To change your Address\t  enter: b" << endl;
  cout << "To change your Phone\t  enter: c" << endl;
  cout << "To change your Email\t  enter: d" << endl;
    cin >> input;
  
  cout << "what is the new entry? :";
    cin >> choice;
    input = tolower(input);
    
    switch(input) {
      case 'a': Member->setName(choice); break;
      case 'b': Member->setAddress(choice); break;
      case 'c': Member->setPhone(choice); break;
      case 'd': Member->setEmail(choice); break;

  }


  //go to memeber - set address name etc.
  return;
}

void print(List * theMembers){
  cout << "Printing valid members..." << endl;
  theMembers->printList();
  return;
}

int main(void){


 // Variables declaration
  List* members = new List(); 
  bool done = false;
  char input = 0;


  // Keep doing what the user selects until the user exits
  while (not done) {
    // Print menu to user 
    cout << "\n----Welcome to the walkIn!\n" << endl;
    cout << "To join the network and create a profile  enter: a" << endl;
    cout << "To leave the network\t\t\t  enter: b" << endl;
    cout << "To modify your profile\t\t\t  enter: c" << endl;
    cout << "To search for someone on the network\t  enter: d" << endl;
    cout << "To see a list of existing patients\t  enter: e" << endl;
    cout << "To exit the walkIn\t\t\t  enter: x\n" << endl;

    cout << "Your choice: ";
    cin >> input;
    input = tolower(input);
    
    switch(input) {
      case 'a': join(members); break;
      case 'b': leave(members); break;
      case 'c': modify(members); break;
      case 'd': search(members); break;
      case 'e': print(members); break;
      case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
      default: cout << "Not sure what you mean! Please, try again!" << endl;
    }
    //cout << printlist() << endl;
    cout << "There are now " << members->getElementCount() << " members in the walkIn" << endl; 
    
  }

  delete members;

  return 0;
}
