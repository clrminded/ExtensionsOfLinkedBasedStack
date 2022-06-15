#ifndef STACK
#define STACK
#include "Node.h"
#include "StackInterface.h"
#include <cassert>

template <class T>
class Stack : public StackInterface<T>
{
private:
	/**
	 * Pointer to first node in the chain;
	 * This node contains the stack's top
	 */
	Node<T>* topPtr; 

public:
	/**
	 * The Big 3
	 * Default constructor
	 * Copy constructor
	 * Destructor
	 */
	Stack();
	Stack(const Stack<T>& aStack);
	virtual ~Stack();

    /**
	 * Stack operations:
	 */
	bool isEmpty() const;
	bool push(const T& newItem);
	bool pop();
	T peek() const;

	/**
	 * max, mean, and operator+ 
	 */
	T max() const;
	T mean() const;
	Stack<T> operator+(const Stack<T>& other);
}; 
// end LinkedStack

/* -----------------IMPLEMENTATIONS FOR STACK.H--------------------*/
template < class T>
Stack<T>::Stack() : topPtr(nullptr) {}

template < class T>
Stack<T>::Stack(const Stack<T>& aStack) {
	Node<T>* originalPtr = aStack.topPtr;
	if (originalPtr == nullptr) {
		topPtr = nullptr;
	}
	else {
		topPtr = new Node<T>(originalPtr->getItem());
		Node<T>* newChainPtr = topPtr;
		originalPtr = originalPtr->getNext();
		newChainPtr->setNext(originalPtr);
		while (originalPtr != nullptr) {
			T item = originalPtr->getItem();
			Node<T>* newNode = new Node<T>(item);
			newChainPtr->setNext(newNode);
			newChainPtr = newChainPtr->getNext();
			originalPtr = originalPtr->getNext();
		}
		newChainPtr = nullptr;
	}
}   
// end copy constructor 

template < class T>
Stack<T>:: ~Stack() {
	while (!isEmpty())
		pop();
} 
// end ~Stack()

template <class T>
bool Stack<T>::isEmpty() const {
	return topPtr == nullptr;
} 
//end isEmpty()

/**
 *
 */
template <class T>
bool Stack<T>::push(const T& newItem) {
	Node<T>* myNewNode = new Node<T>(newItem, topPtr);
	topPtr = myNewNode;
	myNewNode = nullptr;

	return true;
}
//end push(const T& newItem)

template < class T>
bool Stack<T>::pop() {
	// Start with result = false 
	bool result = false; 
	// Check to make sure the stack has at least one item.
	if (!isEmpty()) { 
		// Store topPtr into another one
		Node <T>* myFirstNode = topPtr; 
		topPtr = topPtr->getNext();
		myFirstNode->setNext(nullptr);
		// End myFirstNode
		delete myFirstNode;  
		// Set it equal to nullptr
		myFirstNode = nullptr; 
		// Make it = true again
		result = true;  
	}
	// return the final result
	return result; 
} 
//end pop()

template < class T>
T Stack<T>::peek() const {
	// Check to make sure it has items inside
	assert(!isEmpty());  
	return topPtr->getItem();
} 
// end peak() 

/*----------IMPLEMENTATIONS FOR MAX, MEAN, AND +OPERATOR--------------*/
template<class T>
T Stack<T>::max() const {
	assert(!isEmpty()); // make sure it has items inside 
	Node<T>* thisNode = topPtr; // new node that stores topPtr inside a different Node 
	T maxItem = thisNode->getItem(); //maxItem is full 

	while (thisNode != nullptr) { // move through all the stack 
		if (thisNode->getItem() > maxItem) { //if maxItem's value is more than the current one 
			maxItem = thisNode->getItem(); // then we need to change the value of maxItem to the new one 
		}
		thisNode = thisNode->getNext(); // change the node to the next one 
	}
	return maxItem; // return the value of maxItem
} // end max()

template<class T>
T Stack<T>::mean() const {
	assert(!isEmpty()); // make sure it has items inside 
	Node<T>* myOtherNode = topPtr; //store topPtr pointer inside another 

	// variables to track the addition and itemCount of nodes 
	// set them = 0 to start with 
	T addition = 0;
	T itemCount = 0;

	// while loop 
	// it moves through all nodes inside the stack
	while (myOtherNode != nullptr) {
		addition += myOtherNode->getItem();  // now, sum has a value
		itemCount++; // add a value to count
		myOtherNode = myOtherNode->getNext(); // move to the next node 
	}
	return addition / itemCount; // the mean value is sum / count. return it
} 
// end mean()


/**
 * operator+ overload, this will allow us to add two Stack classes together
 * This is what will give us alot of options to do operations on class instances.
 */
template<class T>
Stack<T>Stack<T>::operator+(const Stack<T>& other) {
	//get the pointer of the top of two stacks. stack1 and stack2
	Node<T>* stack1 = this->topPtr;
	Node<T>* stack2 = other.topPtr;
	//make 2 empty stacks named temp and temp1
	Stack<T> temp; 
	Stack<T> temp1; 

	// move through the stack 
	while (stack1 != nullptr) { 
		// push the item of stack1 and stack2 to the next one
		temp.push(stack1->getItem()); 
		temp.push(stack2->getItem());

		//move to the next node 
		stack1 = stack1->getNext(); 
		stack2 = stack2->getNext();
	}
	Node<T>* myStack = temp.topPtr; 

	//move through the stack
	while (myStack != nullptr) {
		temp1.push(myStack->getItem()); //move to the next new stack
		myStack = myStack->getNext();
	}
	return temp1;
} 
// end +operator 
#endif