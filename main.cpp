#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;
vector<int> intArray;
// Function to insert an item into the front of a linked list
template< class T>
void insert( Node<T>* &headPtr , T& entry )
{
	// Create a new node and have the next pointer point to current front
	Node<T> *newNodePtr = new Node<T>( entry , headPtr );
	// Current front now becomes this new node
	headPtr = newNodePtr;
}

// Recursive function to remove an item from a linked list
// Returns true if the operation was done; false, otherwise
template< typename T >
bool remove( Node<T>* &nodePtr , T target )
{
	// YOUR CODE GOES HERE
	Node<T> *currPtr = nodePtr; //headPtr
	Node<T> *prePtr = nullptr;
	
	if (currPtr->getItem() == target) 
	{
	  // cout << currPtr->getItem() <<endl;
	    prePtr = currPtr;
	   if(currPtr->getNext() !=nullptr)
	     prePtr->setNext(currPtr->getNext());   
	   currPtr = nullptr;
	   delete currPtr;
	      
	   
	   return true;
	} else {
	   currPtr = currPtr->getNext();
	   return remove(currPtr, target);
	}
	return false;
}

// Recursive function to display the contents of a linked list
// in the reverse order.
template< class T >
void display( Node<T> *currNodePtr )
{
	// YOUR CODE GOES HERE - CHECK YOUR NOTES!
// 	cout << "Entering MyClass::display() ..." << endl;
   
	if (currNodePtr) 
	{
	  intArray.push_back(currNodePtr->getItem());
	  //cout << currNodePtr->getItem() << " ";
	  currNodePtr = currNodePtr->getNext();
	   
	  return display(currNodePtr);
	}
// 	cout << "Leaving MyClass::display() ..." << endl;
}

int main()
{
	// (1) Declare an empty linked list of unsigned values
	//     based on the Node class and call it myList
	std::cout << "start here" << std::endl;
   Node<int> *myList = nullptr;
   vector<int> remList;
	
	// (2) Read in values from standard input. Non-negative
	//     values are inserted into myList and a negative
	//     value terminates input.
	int input, temp;
	int num_remove;
 	input=0;
	
	bool flag = true;
   while (flag) {
      cin >> input;
      if (input >= 0) {
         insert(myList, input);
      } else {
         while (1) {
            cin >> num_remove;
            if(num_remove<0){
               break;
            }
            remList.push_back(num_remove);
         }
         flag = false;
      }
   }

	
	// (3) Display the contents of the linked list myList
	//     in the order they were entered (hence, the display()
	//     function displays myList in reverse order!
   cout << "Contents: " << endl;
   display(myList);
   for(int i= intArray.size()-1; i>=0;i--){
      cout << intArray[i] << " ";
   }
   cout << endl;

	
	// (4) Read in values from standard input. Non-negative
	//     values are removed from myList and a negative
	//     value terminates input.
	
	for (int i=0; i<remList.size(); i++){
	  //cout << remList[i] << endl;
	  remove(myList, remList[i]);
	}

   


	// (5) Display the contents of the linked list myList
	//     in the order they were entered (hence, the display()
	//     function displays myList in reverse order!
   cout << "After remove() operation" << endl;
   intArray.clear();
   display(myList);
   for(int i= intArray.size()-1; i>=0;i--){
      cout << intArray[i] << " ";
   }
   cout << endl;



	return 0;
}
