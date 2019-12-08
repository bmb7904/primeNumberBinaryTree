/*
 * Author and Programmer: Brett Bernardi
 * December 8, 2019
 */


#include <iostream>
#include "intTree.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>


using namespace std;

int main()
{
    intTree myBinaryTree;
    
    int numberOfInts = 10000;
    
    int userNum;
    bool loopVar = true;
    
    int primeCounter = 0;
    

    
    srand(time(NULL));
    int randNumber;
    
    // start at 2, 1 is not prime and a special case
    for(int i = 1; i <numberOfInts; i++)
    {
        int counter = 0;
        randNumber = (rand()%10000) + 1;
        
        // we can save a lot of computation by starting j at (int)sqrt(randNumber)
        // any composite number (randNumber) will have at least 1 factor between 1 - sqrt(randNumber)
        for(int j = ((int)sqrt(randNumber)); j > 1; j --)
        {
            if((randNumber % j) == 0)
            {
                counter ++;
            }
        }
        
            // at this point a prime number should have no factors
            // we are excluding 1 and the number itself
            if((counter == 0) && (randNumber != 1))
            {
                
                myBinaryTree.addNode(randNumber);
                primeCounter ++;
            }
        
        
       }

    myBinaryTree.printNodes();
    
    cout << endl << endl << primeCounter << " randomly generated prime numbers were added to a binary tree" << endl << endl;
    cout << "These primes are now ordered from lowest to highest" << endl << endl;
    cout << "The primes are found between the range of 1 - 10,000" << endl << endl;
    
    
    
    cout << "You can now search for a prime number by entering it below and seeing if it is in the tree." << endl << endl << endl;
    
    while(loopVar == true)
    {

        cout << "Enter number to search (-1 to quit):";
        cin >> userNum;
        
        if(userNum != -1)
        {
            myBinaryTree.searchNodes(userNum);
        }
        
        else
        {
            loopVar = false;
        }
                
    }
    
    cout << "Programmer: Brett Bernardi" << endl;
    
    return 0;
}