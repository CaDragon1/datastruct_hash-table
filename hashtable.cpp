/*********************
* Author: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Hash Table
* Purpose: This program creates a hashtable object that efficiently and effectively stores data structs using an array of linkedlists.
*          This is the "hashtable.cpp" file, which contains all of the hashtable methods.
**********************/
#include "hashtable.h"

HashTable::HashTable() {
	count = 0;
	for (int i = 0; i < SIZE; i++) {
		hashTable[i] = new LinkedList;
	}
}

HashTable::~HashTable() {
	for (int i = 0; i < SIZE; i++) {
		hashTable[i]->clearList();
		delete hashTable[i];
	}
}

bool HashTable::insertEntry(int id, string* data) {
	bool inserted = false;

	if (id > 0 && *data != "") {

		int hashVal = hash(id);

		inserted = hashTable[hashVal]->addNode(id, data);
		if (inserted) {
			count++;
		}
	}
	return inserted;
}

string* HashTable::getData(int id) {
	int hashVal = hash(id);
	Data* data = new Data;
	string* dataReturn = new string;
	*dataReturn = "";

	if (id > 0) {
		if (hashTable[hashVal]->getNode(id, data)) {
			dataReturn = &data->data;
		}
	}
	
	return dataReturn;
}

bool HashTable::removeEntry(int id) {
	bool removed = false;
	if (id > 0) {				// Make sure the id is a valid positive int
		int hashVal = hash(id);
		removed = hashTable[hashVal]->deleteNode(id);
		if (removed) {
			count--;
		}
	}
	
	return removed;
}

int HashTable::getCount() {
	return count;
}

void HashTable::printTable() {
	for (int i = 0; i < SIZE; i++) {
		std::cout << "Entry " << (i + 1) << ": ";
		if (hashTable[i]->getCount() == 0) {
			std::cout << "EMPTY" << std::endl;
		}
		else {
			hashTable[i]->printList();
		}
	}
}

int HashTable::hash(int id) {
	return id % SIZE;;
}