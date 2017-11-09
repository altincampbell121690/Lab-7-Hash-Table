//============================================================================
// Name        : Hashtable.cpp
// Author      : Altin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include "Hashtable.h"
#include "List.h"
#include "Book.h"
using namespace std;
//returns the hash value for the given key
//the hash value is the sum of
//of the ASCII values of each char in the key
//% the size the of the table
//Key for this table: title + author
int HashTable::hash(string key) const{
	int sum=0;
	for (int i = 0; i < key.length(); i++){
		sum += (int)key[i];
	}
	return (sum % SIZE);
}
//counts the number of Books at this index
//returns the count
//pre: 0<= index < SIZE
int HashTable::countBucket(int index) const{
	return Table[index].getSize();
}
//Searches for b in the table
//returns the index at which b is located
//returns -1 if b is not in the table
int HashTable::search(Book b) const{
	string key = b.get_author() + b.get_title();
	return Table[hash(key)].linearSearch(b);
}

//inserts a new book into the table
//calls the hash function on the key to determine
//the correct bucket
void HashTable::insert(Book b){
	string key = b.get_author() + b.get_title();
	Table[hash(key)].insertStop(b);
}

//removes b from the table
//calls the hash function on the key to determine
//the correct bucket
//pre: b is in the table
void HashTable::remove(Book b){
	string key = b.get_author() + b.get_title();
	assert(Table[hash(key)].linearSearch(b)!= -1);
	int index = Table[hash(key)].linearSearch(b);
	Table[hash(key)].advanceToIndex(index);
	Table[hash(key)].deleteIterator();
}
