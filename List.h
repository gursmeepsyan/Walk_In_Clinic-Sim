/*
 * List.h
 *
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (For you to fill: Add a statement about the another characteristic of this List.)
 *
 * Author: Sehajvir Singh Pannu(301386534), Gursmeep Singh Syan(301386570)
 * Date: 16/09/2019
 */

#pragma once
#include <string>
#include "Patient.h"

using namespace std;


class List  {

private:

	int capacity;                                             // Actual maximum capacity of element array
	static const int MAX_ELEMENTS = 100;                       // MAX_ELEMENTS
	Patient elements[MAX_ELEMENTS];      // Data structure of element with capacity of MAX_ELEMENTS
	int elementCount;                                         // Current element count in element array


public:

	// Default constructor.
	List();

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.
	// Postcondition: newElement inserted and elementCount has been incremented.
	bool insert(const Patient& newElement);

	// Description: Remove an element.
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.
	bool remove( const Patient& toBeRemoved );

	// Description: Remove all elements.
	void removeAll();

	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);

	// Description: Prints all elements stored in List by descending order of care card numbers.
	void printList();

}; // end List.h
