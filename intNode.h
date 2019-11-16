#ifndef INTNODE_H
#define INTNODE_H

#include <iostream>

using namespace std;

class intNode
{
        public:
            intNode();
            intNode(int n);
            intNode *left;
            intNode *right;
            int number;
    
        private:
    
    
    
};

intNode::intNode()
{
    left = NULL;
    right = NULL;
}

intNode::intNode(int n)
{
    left = NULL;
    right = NULL;
    number = n;
}




#endif /* INTNODE_H */

