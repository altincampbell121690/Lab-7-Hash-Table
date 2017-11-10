//============================================================================
// Name        : Book.cpp
// Author      : Altin & Erik the great
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book():title(""), author(""), price(0.0), isbn(0){};

Book::Book(string t, string a, double p, unsigned i) {
    title = t;
    author = a;
    price = p;
    isbn = i;
}

/**Access Functions*/

string Book::get_title() {
    return title;
}

string Book::get_author() {
    return author;
}

unsigned Book::get_isbn() {
    return isbn;
}

double Book::get_price() {
    return price;
}

/**Manipulation Procedures*/

void Book::set_title(string t){
    title = t;
}

void Book::set_author(string a) {
    author = a;
}

void Book::set_isbn(unsigned i) {
    isbn = i;
}

void Book::set_price(double p) {
    price = p;
}

/**Additional Functions*/


bool Book::operator==(const Book& book) {
    return (this->title == book.title && this->author==book.author);
}
//compares two books to determine if one comes before the other
//alphabetically by title and secondarily by author if the two
//books contain the same title
//returns false if the two books are the same
bool Book::operator < (const Book& book) {
    if (this->title < book.title)
    	return true;
    else if(this->title == book.title)
    	 return (this->author < book.author);
    else
    	return false;
    /*if (this->title < book.title || this->author < book.author
     */
}
//compares two books to determine if one comes after the other
//alphabetically by title and secondarily by author if the two
//books contain the same title
//returns false if the two books are the same
bool Book::operator > (const Book& book) {
    if (this->title > book.title)
    	return true;
    else if(this->title == book.title)
    	 return (this->author < book.author);
    else
    	return false;
}
//prints out a book to the designated stream in the following format
//<title> by <author>
//$<price>
//ISBN#: <isbn>
//note that the << is required to be a friend function, not a member function
//note2: do not print out the <> as part of the output
ostream& operator<<(ostream& os, const Book& book){
 os << endl;
 os <<  book.title << " by " << book.author << endl;
 os << "$"<<book.price << endl;
 os << "ISBN#: " << book.isbn << endl;
 return os;
}
