/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates allowed).
 *                   - Position-oriented list.
 * Date: 2/4/22
 * Author: Anil Bronson
 */
#include <iostream>
#include "Patient.h"
#include "List.h"
#include<list>

//Constructors
List::List(){
elementCount = 0; 
capacity = INITIAL_CAPACITY;
}

int List::getElementCount() const{
    return elementCount;
}

bool List::insert(const Patient& newElement){
   
   bool ableToInsert = (elementCount < capacity) && (elementCount >=1);
   
   //doesnt let the user enter same careCard but kinda just deletes the whole user
   for(int i = 0; i <= elementCount; i++){
        if(elements[i] == newElement){
            cout << "cannot have identical careCards..." << endl;
            return false;
        }
    } 

    if(ableToInsert)
    {   

        //gets index of where to insert the newElement based on careCard # (bigger/smaller)
        int index;
        for(int i = 0; i <= elementCount+1; i++){
            if(elements[i] > newElement){
                index = i;
                break;
            }
        }
        //referenced code from friendsbook to insert newElement in to array
        for(int pos = elementCount; pos >= index; pos--){
            elements[pos] = elements[pos-1];
        }
        elements[index] = newElement;
        elementCount++;
    
    }
    //if there are no elements just put it in the first spot
   if(elementCount == 0){
        elements[0] = newElement;
        elementCount++; 
    }
    
    return ableToInsert;

}    

bool List::remove(const Patient& toBeRemoved){
     
     //counter to keep track of position to shift list later
     int index;

     for(int i = 0; i < elementCount; i++){
         if(elements[i] == toBeRemoved)
            index = i;
     }
   
    // code refenced from friendsbook to shift array to needed position to fill in removed element  
    for(int j = index, k = j-1; j < elementCount ; j++,k++){
         elements[k] = elements[j];
    }

    elementCount--;
    return true;
}    

void List::removeAll(){
    elementCount = 0;
}
	
Patient* List::search(const Patient& target){
         
    for(int i = 0; i <= elementCount; i++){
       
        if (elements[i] == target)
            return &elements[i];        
    }
    return NULL;
 }

void List::printList(){
    //prints list lol
    for(int i = 0; i < elementCount; i++){
        cout << elements[i] << " " << endl;
    }
}

List::~List(){}

