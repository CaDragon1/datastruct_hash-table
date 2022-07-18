/*********************
* Author: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Hash Table
* Purpose: This program creates a hashtable object that efficiently and effectively stores data structs using an array of linkedlists.
*          This is the "hashtable.h" file, which contains all of the headers, includes, method prototypes, and other code for the hashtable.
**********************/
#ifndef HASHTABLE_H
#define HASHTABLE_H

// Include the linkedlist, which also includes "data.h", string, and iostream 
#include "linkedlist.h"

#define SIZE 15

class HashTable {
public:
	// Constructor
	HashTable();
	// Destructor
	~HashTable();

	bool insertEntry(int, string*);
	string* getData(int);
	bool removeEntry(int);
	int getCount();
	void printTable();

private:
	int count;	// The amount of items in the hash table
	LinkedList* hashTable[SIZE];	// The array that forms the hash table

	int hash(int);
};

#endif // !HASHTABLE_H