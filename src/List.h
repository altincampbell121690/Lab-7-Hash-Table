/*
ListTest.cpp
*created by Altin Campbell and Erik Rackley
*CIS 22C, Lab 2
*Oct 9, 2017
*11:40:02 PM
*/

#ifndef LIST_H_
#define LIST_H_
#include <cstddef> //for NULL
#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

template <class listdata>
class List {//start of linked list

private:
    struct Node {//struct creating node data type
        listdata data;
        Node* linknext;
        Node* prevlink;

        Node(listdata newData){//node constructor - to initialize node
            this->data = newData;
            linknext = NULL;
            prevlink = NULL;
        }
    };

    Node* start; //head pointer (node)
    Node* stop; //Tail pointer (node)
    Node* iterator;
    int size; // length of list

    void reversePrint(Node* node) const;
            //Helper function for the public reversePrint() function.
            //Recursively prints the data in a List in reverse.

    bool isSorted(Node* node) const;
            //Helper function for the public isSorted() function.
            //Recursively determines whether a list is sorted in ascending order.

    int binarySearch(int low, int high, listdata data) const;
    //Recursively search the list by dividing the search space in half
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List
    //Post: The iterator location has not been changed

public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: empty list (start->NULL && stop->Null)
    ~List();

    List(const List &list);
    //copy constructor create new list that is an identical to  original list
    //Postcondition: new copy of the list

    /**Accessors*/

    listdata getStart() const;
    //Returns the first data in the list
    //Precondition: List must not be empty!||node must have a value

    listdata getStop() const;
    //Returns the last data in the list
    //Precondition: List must not be empty||node must have a value

    bool isEmpty() const;
    //Determines whether a list is empty


    int getSize() const;
    //Returns the size of the list
    /////////////////////////////////////////////////////////////////////////////////////////////
    int linearSearch(listdata data) const;
    //Searchs the list, element by element, from the start of the List to the end of the List
    //Returns the index of the element, if it is found in the List
    //Calls the above indexing functions in its implementation
    //Returns -1 if the element is not in the List
    //Pre: length != 0
    //Post: The iterator location has not been changed

    /////////////////////////////////////////////////////////////////////////////////////////////
    int binarySearch(listdata data) const;
    //Returns the index where data is located in the list
    //Calls the private helper function binarySearch to preform the search
    //Pre: length != 0
    //Pre: List is sorted (must test on a sorted list)
    //Post: The iterator location has not been changed

    ///////////////////////////////////////////////////////////////////////////////
    int getIndex() const;
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered starting at 1 through the size of the list
    //Pre: size != 0
    //Pre: !offEnd()
   //////////////////////////////////////////////////////////////////////////////

    /**Manipulation Procedures*/
    ///////////////////////////////////////////////////////////////////////////////////////
    void advanceToIndex(int index);
    //Moves the iterator to the node whose index number is specified in the parameter
    //Nodes are numbered starting at 1 through the size of the List
    //Pre: size != 0
    //Pre: index <= size
   ///////////////////////////////////////////////////////////////////////////////////////
    void removeStop();
    //Removes the value of the last data in the list
    //Precondition: List must not be empty|| there must be a at least one node
    //Postcondition: Tail/stop will be set to the previous node

    void removeStart();
    //Removes the value of the first data in the list
    //Precondition: List must not be empty||there must be at least one node
    //Postcondition: Head will be sit to next node|| previous head will be deleted && if iterator is == to start it resets iterator to start

    void insertStop (listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: new node is added to the list|| Tail points to new node

    void insertStart(listdata data);
    //Inserts a new data at the start of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: new node is added to the list || head points to new node

    void print() const;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty
    void printNumberedList() const;
    //prints the contents of the linked list to the screen in the format #: <element> followed by a newline
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty


/*********Additional List Operations*******************/
    void pointIterator();
    //moves the iterator to start of list
    //Postcondition: Iterator is set at start

    void deleteIterator();
       //deletes node iterator is pointing too
       //Precondition: List must not be empty||(!offend()) Iterator != start || iterator !=stop
       //Postcondition: size-- && deallocation of memory && ITERATOR == NULL

    listdata getIterator() const;
       //Returns the data of the node iterator is pointing to
       //Precondition: List must not be empty!|| (!offend())
    void insertIterator(listdata data);
       //inserts an element after the node currently pointed to by the iterator
       // precondition: (!offend())
       //Postcondition: new node is added to the list
    void advanceIterator();
          //moves the iterator to the next node towards the last node
          // precondition: (!offend())
          //Postcondition: Iterator moves to next node
    void reverseIterator();
              //moves the iterator to the next node towards the last node
              // precondition: (!offend())
              //Postcondition: Iterator moves to next node

    bool offend() const;
    //Determines whether a the iterator is -> NULL

    bool operator == (const List &list);
    //compares 2 lists to determine whether their contents are equal
    //Postcondition: returns 1 if lists are equal and 0 if they arent

    void reversePrint() const;
    //Wrapper function that calls the reverse helper function to print a list in reverse
    //prints nothing if the List is empty

        /**Access Functions*/

     bool isSorted() const;
     //Wrapper function that calls the isSorted helper function to determine whether
     //a list is sorted in ascending order.
     //We will consider that a list is trivially sorted if it is empty.
     //Therefore, no precondition is needed for this function


};
#endif /* LIST_H_ */


/**************************************/
/* #include <iostream>
 * #include "List.h
 * #include <cstdlib>
 * #include <assert.h>
 *************************************/

//Function Prototypes
template<class listdata>
List<listdata>::List() {
    start = NULL;//head pointer
    stop = NULL; // tail pointer
    iterator = NULL;
    size = 0;
}

//Function Definitions
template<class listdata>
List<listdata>::~List()
{
    Node* b = start; //node pointer B
    Node* a = NULL; //a stands for "after" (i.e. after b) AKA Next node A
    while (b != NULL) //while nodePtr not = to tail(end of list)
    {
        a = b->linknext; //move a to node after b (next node A is pointing to what node b is pointing to)
        delete b; //remove b (you know it is not NULL from if)
        b = a; //b "catches up" with a (both point to same place in list)
    }
}
template<class listdata>
List<listdata>::List(const List &list1)
{
	if(list1.start == NULL){
		start = stop = iterator = NULL;
	    size = 0;
	}
	else {
		start = new Node(list1.start->data);
		  Node* temp = list1.start;  //set a temporary node pointer to point at the first of the original list
		    iterator = start; //set iterator to point to first node of the new list
		        while(temp->linknext != NULL) // while temps pointer is not pointing to the node tail pointer is pointing to
		        {

		            temp = temp->linknext; // continue to point to the next node
		            iterator->linknext = new Node(temp->data);
		            iterator = iterator->linknext;
		        }
		        stop = iterator;//sets tail of list
		        iterator = NULL; // sets the node->linknext that temp was pointing to - to NULL
		        size=list1.size; //decrement size



	}
    //body of constructor
}

template<class listdata>
void List<listdata>::print() const
{
    Node* temp = start; //create a temporary iterator
    while (temp != NULL) {

       cout << temp->data << " "; //prints data to console

    	temp = temp->linknext; // traverses the list
    }

    cout << endl; //what does this do?

}
template<class listdata>
void List<listdata>::printNumberedList() const
{
    Node* temp = start; //create a temporary iterator
    int elem = 0;
    while (temp != NULL) {
       elem++;
       cout << elem<<": " << temp->data << endl; //prints data to console

    	temp = temp->linknext; // traverses the list
    }

    cout << endl; //what does this do?

}

template<class listdata>
void List<listdata>::insertStart(listdata data)
{
    Node* N = new Node(data);
    if (size == 0)
    {
       iterator = start = stop = N;
        N->linknext = NULL;
        N->prevlink = NULL;
    }
    else
    {
        N->linknext = start;
        start->prevlink = N;
        start = N;
    }
    size++;

}
template<class listdata>
void List<listdata>::insertStop(listdata data)
{
    Node* N = new Node(data);
    if (size == 0)
    {
        start = N;
        stop = N;
        N->linknext = NULL; // not necessary
    }
    else
    {
        N->linknext = NULL;
        N->prevlink = stop;
        stop->linknext = N;
        stop = N;
    }
    size++;

}
template<class listdata>
void List<listdata>::removeStart()
{
   assert(size != 0);
    if(size == 1) // if one node in list
    {
        delete start;
        iterator = start = stop = NULL;
        size = 0;
    }
    else // List has more than one node
    {
        Node* temp = start;
        if (iterator == start)
        	iterator = start->linknext; // logically iterator can only be pointed at start anyway so this seems appropriate
        start = start->linknext;
        delete temp;
        start->prevlink = NULL;
        size--;
    }
}
template<class listdata>
void List<listdata>::removeStop()
{
    assert (!isEmpty());

    if (size == 1) {

    	delete stop;
    	       start = stop = NULL;
    	       size = 0;

    } else {
        Node* temp = stop;
        if (iterator == stop)
        	iterator = NULL;
        stop = stop->prevlink;
        delete temp; // delete what stop is pointing too
        stop->linknext = NULL; // sets the node->linknext that temp was pointing to - to NULL
        size--; //decrement size
    }

}

template<class listdata>
bool List<listdata>::isEmpty() const
{
	return (size == 0);
}


template<class listdata>
int List<listdata>::getSize() const
{
	return size;
}


template<class listdata>
listdata List<listdata>::getStart() const
{
	//if(size > 0)
	 assert(size != 0); //#include <assert.h>
	return start->data;

}
template<class listdata>
listdata List<listdata>::getStop() const
{
	assert(size != 0);
	return stop->data;

}

/*********************************************/
template<class listdata>
bool List<listdata>::offend() const //check
{
	return (iterator == NULL);
}
template<class listdata>
void List<listdata>::pointIterator()
{
    iterator = start;
}
template<class listdata>
listdata List<listdata>::getIterator() const
{
	//if(size > 0)
	 assert(!offend()); //#include <assert.h>
	return iterator->data;

}

template<class listdata>
void List<listdata>::advanceIterator()
{
	 assert(!offend()); //#include <assert.h>
	 iterator = iterator->linknext;
}

template<class listdata>
void List<listdata>::reverseIterator()
{
	 assert(!offend()); //#include <assert.h>
	 //assert(iterator != start)
	assert(iterator != start);
	 iterator = iterator->prevlink;
}


template<class listdata>
void List<listdata>::insertIterator(listdata data)
{
  assert(!offend()); // ALERT iS HERE BUT I THOUGHT IT WOULD WORK BETTER IF INSERT STOP WAS CALLED
/*
 * insertStart(data);
 *	  pointIterator();
 *	  }
 * }
 */

 if (iterator == stop)
   		insertStop(data);
   else {
	Node* N = new Node(data);
        N->linknext = iterator->linknext;//node's next is pointing to node next to iterator
        N->prevlink = iterator; // node points back at iterator
        iterator->linknext->prevlink = N; //node infront of iterator now points back to new node
        iterator->linknext = N; // iterator now points to new node
        size++; //MOVED INSIDE TO ACCOUNT FOR INSERT START
   }



}

template<class listdata>
void List<listdata>::deleteIterator()
{
    assert (!offend());
    //assert (iterator != start);
    //assert (iterator != stop);

    if (size == 1) {

    	delete iterator;
    	       iterator = start = stop = NULL;
    	       size = 0;

    }
    else if (iterator == start) {
    	removeStart();
    	pointIterator();
      }
    else if (iterator == stop) {
        	removeStop();
          }


    else {
        /*Node* temp = start;
        while(temp->linknext != stop) // while temps pointer is not pointing to the node tail pointer is pointing to
        {
            temp = temp->linknext; // continue to point to the next node
        }
        delete stop; // delete what stop is pointing too
        stop = temp; // sets stop to point to temp
        stop->linknext = NULL;*/ // sets the node->linknext that temp was pointing to - to NULL
    	iterator->prevlink->linknext=iterator->linknext;
    	iterator->linknext->prevlink = iterator->prevlink;
    	delete iterator;
        size--; //decrement size
    }



}


template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(size != list.size){ // check to see if lists hvae the same number of nodes
    	//cout << "Lists are unequal!\n";
        return false;
    }
    Node* temp1 = start; //set to start of first list
    Node* temp2 = list.start; // set to start of second
    while(temp1 != NULL) //while first temp iterator is not offend || NULL
    {
        if(temp1->data != temp2->data) { // check if they are not equal
        	//cout << "Lists are unequal!\n";
        	return false;
        }
        temp1 = temp1->linknext; // if they arent continue to the next node to compare
        temp2 = temp2->linknext;
    }
    //cout << "Lists are equal!\n";
    return true; // return true if the any of the above conditions (are true which would return false).
}
///////////////////////////////////////////////////////////////////////////////
template <class listdata>
void List <listdata>:: reversePrint() const {
	if (size == 0)
		return;
	else{
		Node* temp = stop;
		reversePrint(temp);
		//reversePrint(stop);
	}
}
template <class listdata>
void List<listdata>::reversePrint(Node* node) const{
	if (node == NULL){
		cout << endl;
		return;
	}
	else{
		cout << node->data << " ";
		reversePrint(node->prevlink);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class listdata>
bool List<listdata>::isSorted() const{
	if (size == 0||size == 1)
		return true;
	else
		return isSorted(start);
}
template<class listdata>
bool List<listdata>::isSorted(Node* node) const{
	if (node->linknext == NULL)
		return true;
	else if ((node->data >  node->linknext->data))
	   return false;
	else
		return isSorted(node->linknext);
}
////////////////////////////////////////////////////////////////////////////
template <class listdata>
int List<listdata>::getIndex() const{
assert (!offend());
	int index = size;
	Node* temp = stop;
	while (temp != iterator){
		temp = temp->prevlink;
		index--;
	}
	return index;

}
//////////////////////////////////////////////////////////////////////////
template <class listdata>
void List<listdata>::advanceToIndex(int index){
	assert(size != 0);
    assert(index <= size);
    if (index == 1)
    pointIterator();
    else{
    	pointIterator();
    	  for (int i = 1; i != index; i++){ //<=??
    		iterator = iterator->linknext;
    	  }
      }

}
//////////////////////////////////////////////////////////////////////////////////
template <class listdata>
int List<listdata>:: linearSearch(listdata data) const{
assert(!isEmpty());
int found = -1;
	Node* temp = start;
	int counter = 1;
    //pointIterator();
	while(temp->linknext != NULL && (temp->data != data)){
		temp = temp->linknext;
		counter++;
		//advanceIterator();
		if (temp->data == data)
			return counter;
	}
	cout << "not found: ";
return found;
}
//////////////////////////////////////////////////////////////////////////////////////
template <class listdata>
int List<listdata>::binarySearch(listdata data) const {
	assert(size!= 0);
	assert(isSorted());

	return binarySearch(start->data,stop->data, data);

}
//////////////////////////////////////////////////////////////////////////////////////
template <class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data) const {
	int mid = low + (high-low)/2;
	if (high < low) {
		cout << "Not Found: ";
		return -1;
	}
	//int mid = low + (high-low)/2;
	if (mid == data)
		return linearSearch(mid); /// we cant return the index since its const
		//return mid;
	else if (data < mid)
		return binarySearch(low, mid-1, data);
	else
		return binarySearch(mid+1, high, data);
}
//}
