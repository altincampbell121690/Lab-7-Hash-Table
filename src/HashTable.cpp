//============================================================================
// Name        : Hashtable.cpp
// Author      : Altin & Erik the great
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ostream>
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
	for (unsigned int i = 0; i < key.length(); i++){
		sum += (int)key[i];
	}
	return (sum % SIZE);
}
//counts the number of Books at this index
//returns the count
//pre: 0<= index < SIZE
int HashTable::countBucket(int index) const{
	assert((0 <= index) && (index < SIZE));
	return Table[index].getSize();
}
//Searches for b in the table
//returns the index at which b is located
//returns -1 if b is not in the table
int HashTable::search(Book b) const{
	string key = b.get_author() + b.get_title();
	if (Table[hash(key)].linearSearch(b) > -1)
	return hash(key);
	else return -1;
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

//Prints all the books at index
//pre: 0<= index < SIZE
//Should print according to the following formula:
//Prints each book at that index in the format:
//<title> by <author>
//$<X.XX>
//ISBN#: <isbn>
//followed by a blank line
void HashTable::printBucket(ostream& out, int index) const{
	assert((0 <= index) && (index < SIZE));
	Table[index].print();
	/**
	Table[index].pointIterator();
	while (!Table[index].offend()){
		out << Table[index].getIterator();
		Table[index].advanceIterator();
		}
	//*/
}

//Prints the first book at each index
//along with a count of the total books
//at each index by calling count_bucket
//as a helper function
//Prints in the format:
//Books in the Catalogue:
//<new line>
//Group <bucket>
//<title> by <author>
//$<X.XX>
//ISBN: <isbn>
//+<number of elements at this index> -1 more similar book(s)
//<new line><new line><new line>
void HashTable::printTable(ostream& out) const{
	out << "Books in the Catalogue:\n" << endl;
	for(int i = 0; i < SIZE; i++){
		if(!Table[i].isEmpty()){
		out << "Group: " << i+1;
		out << Table[i].getStart();
		out << '+' << countBucket(i)-1 << " or more similar book(s)\n" << endl;
		}
	}
}
