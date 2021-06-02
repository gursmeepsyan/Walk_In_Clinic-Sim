/*
 * List.cpp
 *
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - List will not allow insertion of new elements once the list is full
 *										 (however, it will continue to allow overwriting of existing elements with updated information)
 *					 				 - Maximum 100 entries in the list
 *
 * Author: Sehajvir Singh Pannu(301386534) , Gursmeep Singh Syan (301386570)
 * Date: 3rd October 2019
 */

#include<iostream>
#include <string>
#include "Patient.h"
#include "List.h" // Header file

using namespace std;


// Default constructor

List::List() : elementCount(0) , capacity(List::MAX_ELEMENTS) {}

// Description: Returns the total element count currently stored in List.


int List :: getElementCount() const
{
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.

bool List::insert(const Patient& newElement)
{
		bool notDuplicate = true;
		bool ableToInsert = true;
		int index = 0;
		while (notDuplicate && index < elementCount)
		{

			if (newElement.getCareCard() == elements[index].getCareCard()) // Check whether newElement is a duplicate, if so:
			{
			  elements[index] = newElement;									// Overwrite with most current version of the entry
				notDuplicate = false;													// Return duplicate
			}
			index++;															// Increment index
		}
		// Also check whether there is room in the array before inserting
		ableToInsert = (notDuplicate && elementCount < MAX_ELEMENTS);
		if (ableToInsert)
		{
				elements[elementCount] = newElement;
				elementCount++;	// Increment element count

				// Position element so as to maintain descending Care Card order immediately following insertion into the list
				Patient temp;
				for (int i = elementCount-1; i > 0; i--)
				{
						if (elements[i] > elements[i-1])
						{
								temp = elements[i];
								elements[i] = elements[i-1];
								elements[i-1] = temp;
							}
				}
		}
		return (ableToInsert);
}

// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.

bool List::remove( const Patient& toBeRemoved )
{
			if (search(toBeRemoved) != NULL)
			{ 							// Check whether searched element is in the list, if so:
					Patient *targetPointer = search(toBeRemoved); 			// Identify location of element
					Patient *lastPointer = &elements[elementCount-1];		// Identify the location of the last element in the list
					for (Patient *pointer = targetPointer; pointer < lastPointer; pointer++)
					{
							*pointer = *(pointer+1);							// Shift all alements after location of element left by one
					}
			elementCount--; 										// Decrement elementCount
			return true;
			}
			else
				return false;
}

// Description: Remove all elements.

void List::removeAll()
{
		elementCount = 0;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.

Patient* List::search(const Patient& target)
{
		if(this->elementCount>0)
		{
				bool found = false;
				int searchIndex = 0;
				int matchIndex = -1;
				// Traverse list until a match is found or until the end of the list
				while (found == false && searchIndex < elementCount)
				{
						if (elements[searchIndex] == target)
						{
								found = true;
								matchIndex = searchIndex;
						}
						else
								searchIndex++;
				}
				if (found)
					return &elements[matchIndex];
				else
					return NULL;

			}
	}


// Description: Prints all elements stored in List by descending order of care card numbers.

void List::printList() {

	   for (int index = 0; index < elementCount; index++) {
		  cout << elements[index] << endl;
	   }
	   return;
	}
// end List.cpp
