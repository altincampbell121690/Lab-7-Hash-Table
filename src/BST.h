/*
 * BST.h
 *
 *  Created on: Oct 31, 2017
 *      Author: jetci_000
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <string>
#include <assert.h>

using namespace std;
template<typename bstdata>
class BST {
private:
	struct Node {
		bstdata data;
		Node* leftchild;
		Node* rightchild;

		Node(bstdata newdata) { // NODE constructor
			data = newdata;
			leftchild = NULL;
			rightchild = NULL;
		}
	};

	Node* root;

	/**Private helper functions*/
	void insertNode(Node* root, bstdata data); //DONE
	//private helper function for insert
	//recursively inserts a value into the BST

	void inOrderPrint(ostream& out, Node* root) const; //DONE
	//private helper function for inOrderPrint
	//recursively prints tree values in order from smallest to largest

	void preOrderPrint(ostream& out, Node* root) const;
	//private helper function for preOrderPrint
	//recursively prints tree values in pre order

	void postOrderPrint(ostream &out, Node* root) const; //DONE
	//private helper function for postOrderPrint
	//recursively prints tree values in post order

	void copyNode(Node* copy);
	//recursive helper function to the copy constructor

	void freeNode(Node* root); //DONE
	//private helper function for the destructor
	//recursively frees the memory in the BST

	bool searchNode(Node* root, bstdata data) const;
	//recursive helper function to search
	//returns whether the value is found in the tree

	bstdata minimum(Node* root) const;
	//recursive helper function to minimum
	//returns the minimum value in the tree

	bstdata maximum(Node* root) const;
	//recursive helper function to maximum
	//returns the maximum value in the tree

	Node* deleteNode(Node* root, bstdata data);
	//recursive helper function to remove
	//removes data from the tree

	void getSize(Node* root, int& size) const; //DONE
	//recursive helper function to the size function
	//calculates the size of the tree
	//stores the result in size

	int getHeight(Node* root) const;
	//recursive helper function to the height function
	//returns the height of the tree

public:

	/**constructors and destructor*/

	BST();    //DONE
	//Instantiates a new BST

	BST(const BST &bst);
	//copy constructor

	//DECONSTRUCTOR
	~BST(); ///DONE
	//deallocates the tree memory

	/**access functions*/

	bstdata minimum() const;
	//returns the minimum value in the BST
	//pre: !empty()

	bstdata maximum() const;
	//returns the maximum value in the BST
	//pre: !empty()

	bool isEmpty() const; //DONE
	//determines whether the BST is empty

	int getSize() const; //DONE
	//returns the size of the tree

	bstdata getRoot() const;
	//returns the value stored at the root of the BST
	//pre: !isEmpty()

	int getHeight() const;
	//returns the height of the tree

	bool search(bstdata data) const;
	//returns whether the data is found in the tree
	//pre: !isEmpty()

	/**manipulation procedures*/

	void insert(bstdata data);    //DONE
	//inserts new data into the BST

	void remove(bstdata data);
	//removes the specified value from the tree
	//pre: data is located in the tree
	//pre: !isEmpty()

	/**additional functions*/

	void inOrderPrint(ostream& out) const; //DONE
	//void inOrderPrint() const;
	//calls the inOrderPrint function to print out the values
	//stored in the BST

	void preOrderPrint(ostream& out) const;
	//calls the reOrderPrint function to print out the values
	//stored in the BST

	void postOrderPrint(ostream& out) const; //DONE
	//calls the postOrderPrint function to print out the values
	//stored in the BST
};
#endif /* BST_H_ */
//CONSTRUCTORS
//private helper function for insert
//recursively inserts a value into the BST
template<typename bstdata>
BST<bstdata>::BST() {
	root = NULL;
}

template<typename bstdata>
BST<bstdata>::~BST() {
	assert(!isEmpty());
	freeNode(root);
}
/*
 * free node: checks if not null
 * 			if not then it calls recursive step left (adds to the stack)
 *               checks if leftchild is null
 *                    calls recursive step on left again (adds to the stack
 *                         it is null then it returns
 *                  now it calls recursive step on right child (adds to the stack
 *                       checks if its null
 *                           if its not it checks its leftchild(adds to stack) null
 *                           then checks its right child (adds to stack)  null
 *                         if both are null then delete is added to the stack
 *                         pops them off as it goes back up deleting
 * */
template<typename bstdata>
void BST<bstdata>::freeNode(Node *thisRoot) {
	if (thisRoot == NULL) { //Base case once null return
		return;
	} else if (thisRoot != NULL) {
		freeNode(thisRoot->leftchild);
		freeNode(thisRoot->rightchild);
		delete thisRoot;
	}

}
template<typename bstdata>
BST<bstdata>::BST(const BST &bst) {
	if (bst.root == NULL) {
		root = NULL;
	} else {
		root = new Node(bst.root->data);
		copyNode(bst.root);
	}
}

template<typename bstdata>
void BST<bstdata>::copyNode(Node* copy) {
	if (copy == NULL) { // base case
		return;
	} else {
		insert(copy->data);

		/*if (copy->leftchild != NULL) {
		 copyNode(copy->leftchild);
		 }
		 else if (copy->rightchild != NULL) {
		 copyNode(copy->rightchild);
		 }*/
		//cout << "root data: " << root->data << endl;
		copyNode(copy->leftchild);
		copyNode(copy->rightchild);

	}
}

template<typename bstdata>
void BST<bstdata>::remove(bstdata data) {
	assert(!isEmpty());
	assert(search(data));
	deleteNode(root, data);
}

template<typename bstdata>
typename BST<bstdata>::Node* BST<bstdata>::deleteNode(Node* root,
		bstdata data) {
	int nodeData;
	if (root == NULL) {
		return root;
	} else if (data < root->data) {
		root->leftchild = deleteNode(root->leftchild, data);
	} else if (data > root->data) {
		root->rightchild = deleteNode(root->rightchild, data);
	} else {
		if (root->leftchild == NULL && root->rightchild == NULL) {
			delete root;
			root = NULL;
		} else if (root->leftchild != NULL && root->rightchild == NULL) {
			root->leftchild = root;
			delete root;
		} else if (root->leftchild == NULL && root->rightchild != NULL) {
			root->rightchild = root;
			delete root;
		} else {
			nodeData = minimum(root->rightchild);
			root->data = nodeData;
			root->rightchild = deleteNode(root->rightchild,
					minimum(root->rightchild));
		}
	}
	return root;
}

template<typename bstdata>
void BST<bstdata>::insert(bstdata data) {
	if (root == NULL) // if root is empty
	{
		root = new Node(data); //if the tree is empty insert the value at the root
	} else {
		insertNode(root, data); //otherwise call the helper function, passing it the root
	}
}
template<typename bstdata>
void BST<bstdata>::insertNode(Node* root, bstdata data) {
	if (data == root->data)
		return;
	else if (data < root->data) { // should node go to the left
		if (root->leftchild == NULL) //if so is the left slot empty?
			root->leftchild = new Node(data);

		else
			return insertNode(root->leftchild, data); // start process over starting with left child
	} else {
		if (root->rightchild == NULL)
			root->rightchild = new Node(data);
		else
			return insertNode(root->rightchild, data);
	}
}
template<typename bstdata>
//void BST<bstdata>::inOrderPrint() const{
void BST<bstdata>::inOrderPrint(ostream& out) const {
	if (root == NULL)
		cout << "empty";
	else
		//inOrderPrint(root);
		inOrderPrint(out, root);
	cout << endl;
}
template<typename bstdata>
//void BST <bstdata>::inOrderPrint(Node* root) const{
void BST<bstdata>::inOrderPrint(ostream &out, Node* thisRoot) const {
	if (thisRoot == NULL) { //Base case once null return
		return;
	} else if (thisRoot != NULL) {
		inOrderPrint(out, thisRoot->leftchild); // go down left tree until null BECAUSE ITS A STACK THE LAST ONE ON IS FIRST OOUT
		out << thisRoot->data << " ";
		inOrderPrint(out, thisRoot->rightchild); // go down right tree until null
	}

}

template<typename bstdata>
void BST<bstdata>::postOrderPrint(ostream& out) const {
	if (root == NULL)
		cout << "empty";
	else
		postOrderPrint(out, root);
	cout << endl;
}
template<typename bstdata>
void BST<bstdata>::postOrderPrint(ostream &out, Node* thisRoot) const {
	if (thisRoot == NULL) { //Base case once null return
		return;
	} else if (thisRoot != NULL) {
		postOrderPrint(out, thisRoot->leftchild); // go down left tree until null BECAUSE ITS A STACK THE LAST ONE ON IS FIRST OOUT
		postOrderPrint(out, thisRoot->rightchild); // go down right tree until null
		out << thisRoot->data << " "; //print in order as it pops off the stack
	}
}

template<typename bstdata>
void BST<bstdata>::preOrderPrint(ostream& out) const {
	if (root == NULL) {
		return;
	} else {
		preOrderPrint(out, root);
		cout << endl;
	}
}

template<typename bstdata>
void BST<bstdata>::preOrderPrint(ostream& out, Node* root) const {
	if (root == NULL) {
		return;
	} else {
		out << root->data << " ";
		preOrderPrint(out, root->leftchild);
		preOrderPrint(out, root->rightchild);
	}
}
template<typename bstdata>
int BST<bstdata>::getSize() const {
	int size = 0;
	if (root == NULL)
		return size;
	else
		getSize(root, size);
	return size;
}
template<typename bstdata>
void BST<bstdata>::getSize(Node* thisRoot, int& size) const {
	if (thisRoot == NULL) {
		return;
	} else if (thisRoot != NULL) {
		getSize(thisRoot->leftchild, size);
		size++;
		getSize(thisRoot->rightchild, size);
	}

}
template<typename bstdata>
bool BST<bstdata>::isEmpty() const {
	if (getSize() > 0)
		return false;
	else
		return true;
}
template<typename bstdata>
bool BST<bstdata>::search(bstdata data) const {
	assert(!isEmpty());
	if (root->data == data)
		return true;
	else
		return searchNode(root, data);
}
template<typename bstdata>
bool BST<bstdata>::searchNode(Node* thisRoot, bstdata data) const {
	if (thisRoot->data == data)
		return true;
	else if (data < thisRoot->data) {
		if (thisRoot->leftchild == NULL)
			return false;
		else
			searchNode(thisRoot->leftchild, data);
	} else {
		if (thisRoot->rightchild == NULL)
			return false;
		else
			searchNode(thisRoot->rightchild, data);
	}
}

template<typename bstdata>
bstdata BST<bstdata>::minimum() const {
	assert(!isEmpty());
	return minimum(root);
}

template<typename bstdata>
bstdata BST<bstdata>::minimum(Node* root) const {
	if (root->leftchild != NULL) {
		return minimum(root->leftchild);
	} else {
		return root->data;
	}
}

template<typename bstdata>
bstdata BST<bstdata>::maximum() const {
	assert(!isEmpty());
	return maximum(root);
}

template<typename bstdata>
bstdata BST<bstdata>::maximum(Node* root) const {
	if (root->rightchild != NULL)
		return maximum(root->rightchild);
	else
		return root->data;
}

template<typename bstdata>
int BST<bstdata>::getHeight() const {
	return getHeight(root);
}

template<typename bstdata>
int BST<bstdata>::getHeight(Node* root) const {
	int left, right;
	if (root == NULL)
		return -1;
	else {
		left = getHeight(root->leftchild);
		right = getHeight(root->rightchild);
		if (left > right)
			return (left + 1);
		else
			return (right + 1);
	}

}
/*
 * BST.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Ewreck
 */

#ifndef BST_H_
#define BST_H_

#endif /* BST_H_ */
