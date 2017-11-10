//============================================================================
// Name        : HashTEST.cpp
// Author      : Altin & Erik the great
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

//Function Prototypes

int main()
{

	//*
	  HashTable ht;
	    Book pp("Pride and Prejudice", "Jane Austen", 4.95, 1234567);
	    Book c("Contact", "Carl Sagan", 9.95, 99993339);
	    Book hg("The Hunger Games", "Suzanne Collins",13.55, 12388888);
	    Book hp("Harry Potter", "J.K. Rowlings", 55555678, 12.99);
	    Book mhc("The Man in the High Castle", "Philip K Dick",15.95, 95959595);
	    Book bh("Bleak House", "Charles Dickens", 8.00, 473890238);

	    ht.insert(pp);
	    ht.insert(c);
	    ht.insert(hg);
	    ht.insert(mhc);
	    ht.insert(bh);
cout << "Hello WorldZ" << endl;
	    ht.printBucket(cout, 9);
	    ht.remove(mhc);
	    ht.printTable(cout);
	    cout << "found at index: "<<ht.search(hg) << endl;
	    cout << "found at index: "<<ht.search(mhc) << endl;
	    //*/


}

//Function Definitions
