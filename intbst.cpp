// intbst.cpp
// Implements class IntBST
// Lucas Zhou, 1/20/2026

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
  if (n == nullptr) { //base case, no more nodes to delete
    return; //exit
  }
  clear(n->left); //left
  clear(n->right); //right
  delete n; // delete node!
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
    root->parent = nullptr; //no garbage parent
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
      n->left->parent = n; //make sure parent isn't garbage
      return true; //we added
    }
    return insert(value, n->left); //insert left (go all the way)
  } else if (value > n->info) { //greater case
    if (n->right == nullptr) { //can't recurse anymore
      n->right = new Node; //free mem
      n->right->info = value; //val
      n->right->parent = n; //parent make sure no garbage!
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
  return sum(root); //start root
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
  if (n == nullptr) { //null node 
    return 0; //don't do anything (sum stays zero)
  }
  return sum(n->left) + n->info + sum(n->right); //in order! (add info for sum)
}

// return count of values
int IntBST::count() const {
  return count(root); //start root
}

// recursive helper for count
int IntBST::count(Node *n) const {
  if (n == nullptr) { //null node
    return 0; //no count to update
  }
  return count(n->left) + 1 + count(n->right); //in order! (add 1 for count)
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
  if (n == nullptr) { //null node
    return nullptr; // null
  }
  if (value == n->info) { //value is that node's value!
    return n; //found!
  } else if (value < n->info) {//less?
    return getNodeFor(value, n->left); //go left!
  } else { //greater?
    return getNodeFor(value, n->right);
  }
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
  Node* n = getNodeFor(value, root); //make n be the node that has the value starting from root
  if (n == nullptr) { //null node
    return false; //value isn't inside the bst
  } else { //non null
    return true; // value is in the tree!
  }
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
  Node* n = getNodeFor(value, root); //get node
  if (n == nullptr) { //empty list
    return nullptr; //no predecessor
  }
  Node* p = n->parent; //assign p as n's parent (garbage!)
  if (n->left != nullptr) { //if it has a left child
    n = n->left; //update n to the first left child
    while (n->right != nullptr) { //starting from the left child, go all the way down until reach tail
      n = n->right; //move
    }
    return n; //n is now at the predecessor
  } else { //no left child
    while (p != nullptr && n == p->left) { //parent exists, and parent's left child is you
      n = p; //update n with parent
      p = p->parent; //move parent up
    }
    return p; //parent is predecessor
  }
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
  Node* pred = getPredecessorNode(value); //call helper
  if (pred == nullptr) { //no predecessor?
    return 0; //0
  } else { //there is a predecessor
    return pred->info; //return value of pred
  }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
  Node* n = getNodeFor(value, root); //get node
  if (n == nullptr) { //empty
    return nullptr; //no successor
  }
  Node* p = n->parent; //assign p as n's parent
  if (n->right != nullptr) { //n has a right child
    n = n->right; //move n to first right child
    while (n->left != nullptr) { //set up for going left
      n = n->left; //move down left
    }
    return n; //n is successor (leftmost of right subtree)
  } else { //no right child
    while (p != nullptr && n == p->right) { //parent exists, and parent's right child is you
      n = p; //update n with parent
      p = p->parent; //move parent up
    }
    return p; //now, parent is successor
  }
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
  Node* succ = getSuccessorNode(value); //get helper
  if (succ == nullptr) { //no successor
    return 0; //0
  } else { //there is a successor
    return succ->info; //return its value
  }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
  Node* n = getNodeFor(value, root); //get the node to be deleted
  if (n==nullptr) { //empty list
    return false; //node doesn't exist
  } 
  Node* p = n->parent; //parent node of n assigned
  if (n->left == nullptr && n->right == nullptr) { //no children
    if (n == root) { //n is the root
      delete n; //just delete that one node
    } else if (p->left == n) { //if parent's left is n
      p->left = nullptr; //parent's left links to nullptr
      delete n; //n is deleted
      return true; //true
    } else if (p->right == n) { //parent's right is n
      p->right = nullptr; //parent's right to null
      delete n; //delete the intended node
      return true; //true
    }
  } else if (n->left != nullptr && n->right == nullptr) { //one child, left case
    if (n == root) { //n is the root?
      Node* lc = n->left; //left child
      n->info = lc->info; //update the current node data with data of left child
      n->left = lc->left; //link n's left pointer to one after lc
      delete lc; //delete lc (n is already updated)
    } else if (p->left == n) { //p's left needs to be n to be in a "straight" line
      p->left = n->left; //p's left is connected to n's left
      delete n; //can delete n safely
      return true; //true
    } else if (p->right == n) {  //n is to the right of p
      p->right = n->left; //reconnect p's right to n's left
      delete n; // safe delete n
      return true; //deleted
    }
  } else if (n->left == nullptr && n->right != nullptr) { //one child, right case
    if (n == root) { //n is root
      Node* rc = n->right; //save right child
      n->info = rc->info; //update current node's value with right child's value
      n->right = rc->right; //link n's right pointer to one after right child
      delete rc; //delete rc (n already updated)
    } else if (p->right == n) { //p's right needs to be n to be in a "straight" line
      p->right = n->right; //p's right links to right node after n;
      delete n; //n safely deleted
      return true; //true
    } else if (p->left == n) { //n still has right child, but parent's left is still n
      p->left = n->right; //relink parent to n's child
      delete n; //safe delete n
      return true; //successful delete
    }
  } else { //two children case
    Node* s_rem = getSuccessorNode(n->info); //save a successor node to be deleted (make it value)
    n->info = s_rem->info; //replace n's info with successor's info
    Node* c = s_rem->right; //min in right subtree has right child (could be null)
    Node* s_parent = s_rem->parent; //parent of successor
    if (s_parent->left == s_rem) { //parent's left is successor
      s_parent->left = c; //relink parent to child
    } else { //parent's right is successor
      s_parent->right = c; //unlink the parent's right pointer to child (could be n)
    }
    if (c != nullptr) { //child isn't null
      c->parent = s_parent; //link child back to parent
    }
    delete s_rem; //safely remove s pointer
    return true; //true returned
  }
}
