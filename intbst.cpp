// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
  root = nullptr; //root null
}

// destructor deletes all nodes
IntBST::~IntBST() {
  clear(root); //clear starting from root
  root = nullptr; //root null
}

// recursive helper for destructor
void IntBST::clear(Node *n) {

}

// insert value in tree; return false if duplicate
/*
You don’t have root, so make new root node, give it a value.

Then:
for all other values to be inserted, check if it’s greater than or less than the current parent. If less, insert left. If greater, insert right.
*/
bool IntBST::insert(int value) {
  if (root == nullptr) { //root null
    root = new Node; //allocate memory
    root->info = value; //give it value
    return true; //added to empty tree
  }
  return insert(value, root); //start from root
}
// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
  if (value < n->info) { //left child case
    if (n->left == nullptr) { //oops can't go down
      n->left = new Node; //allocate mem
      n->left->info = value; //give val
      return true; //we added
    }
    return insert(value, n->left); //insert left (go all the way)
  } else if (value > n->info) { //greater case
    if (n->right == nullptr) { //can't recurse anymore
      n->right = new Node; //free mem
      n->right->info = value; //val
      return true; //addded
    }
    return insert(value, n->right); //go down right all the way
  } else { //duplicate case
    return false; //false
  }
} 
  


// print tree data pre-order
void IntBST::printPreOrder() const {
  printPreOrder(root); //start from root
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
  if (n == nullptr) { //null node
    return; //exit
  }
  cout << n->info << " "; //node
  printPreOrder(n->left); //left
  printPreOrder(n->right); //right
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
  printInOrder(root); //start from root
}
void IntBST::printInOrder(Node *n) const {
  if (n == nullptr) { //null node
    return; //exit
  }
  printInOrder(n->left); //left
  cout << n->info << " "; //node
  printInOrder(n->right); //right
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
  printPostOrder(root); //from root
}

void IntBST::printPostOrder(Node *n) const {
  if (n == nullptr) { //null node! (base case)
    return; //exit
  }
  printPostOrder(n->left); //left
  printPostOrder(n->right); //right
  cout << n->info << " "; //node
}

// return sum of values in tree
int IntBST::sum() const {
    return -1; // REPLACE THIS NON-SOLUTION
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    return -1; // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
    return -1; // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int IntBST::count(Node *n) const {
    return -1; // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return false; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    return -1; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    return -1; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    return false; // REPLACE THIS NON-SOLUTION
}
