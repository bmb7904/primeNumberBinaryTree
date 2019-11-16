#ifndef INTTREE_H
#define INTTREE_H
#include <iostream>
#include "intNode.h"

using namespace std;

class intTree
{
    
        public:
            intTree();
            void addNode(int n);
            void searchNodes(int n);
            void printNodes();
            
            
            
    
        private:
            intNode *root;
            void placeNode(intNode *&current, int num);
            void searchNode(intNode *&current, int num);
            void printNode(intNode *&current);
    
};

intTree::intTree()
{
    root = NULL;
}

void intTree::addNode(int n)
{
    placeNode(root, n);
    return;
}

// this function is has arguments of an int called num
// and a reference to a pointer 
// this means the pointer can be changed from within the function and affect
// the outside
void intTree::placeNode(intNode *&current, int num)
{
    // the key to understanding this function is that each single call of the 
    // function produces a new stack frame which has its own current pointer
    // there are many different current pointers, and when current == root is the 
    // first call and last executed function call LI-FO on the stack
    // this is the base case of the recursively defined function
    if(current == NULL)
    {
        current = new intNode(num);
        return;
    }
    
    // if the number argument is less than the number the current pointer is
    // pointing at. AGAIN, depending on the stack frame the current pointer will 
    // vary. This is recursion. There are lots of different currents!
    if(num < current->number)
    {
        // new call to the function
        // input current's left as argument
        // same number
        placeNode(current ->left, num);
    }
    
    // else if num is greater than or equal to current -> number
    else
    {
        placeNode(current->right, num);
    }
    
    return;
    
    
}

// this function is has arguments of an int called num
// and a reference to a pointer 
// this means the pointer can be changed from within the function and affect
// the outside
void intTree::searchNode(intNode *&current, int num)
{
    if(current == NULL)
    {
        // 1 of 2 base cases of recursively defined function
        cout << endl << num << " is not found in tree!" << endl << endl;
        return;
    }
    
    // if the number pointed at by current = the num from argument
    // ends current function call
    // 1 of 2 base cases of recursive function
    if(current->number == num)
    {
        cout << endl << current->number << " is found!" << endl << endl;
        return;
    }
    
    // prints # every level of tree traversed
    cout << "# ";
    
    if(num < current ->number)
    {
        // recursion with a new current pointer input into the new function call
        searchNode(current->left, num);
    }
    
    else
    {
        // recursion with new function.
        // new current pointer set to currents right
        searchNode(current->right, num);
    }
    
    return;
}

// used to interact outside of class
void intTree::searchNodes(int n)
{
    //creates temporary current pointer that points to root of tree
    intNode *curr = root;
    searchNode(curr, n);
    return;
}

void intTree::printNodes()
{
    // input root pointer into printNode (private member function)
    printNode(root);
    return;
}

void intTree::printNode(intNode*& current)
{
    // base case
    // terminates the recursion
    if (current == NULL)
    {
        return;
    }
    
    if(current ->left != NULL)
    {
        printNode(current ->left);
    }
    
    cout <<  current ->number << endl;
    
    if(current ->right != NULL)
    {
        printNode(current ->right);
    }
    
    return;
    
    
    
    
}




#endif /* INTTREE_H */

