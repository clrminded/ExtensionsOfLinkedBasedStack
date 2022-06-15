#ifndef STACK_INTERFACE
#define STACK_INTERFACE

template <class T> 
class StackInterface {
public: 

	/**
	 * Check if the stack is empty 
	 * if yes, return true
	 * if not, return false 
	 */
	virtual bool isEmpty() const = 0;
		
	/**
	 * Adds a new object to the top of the stack 
	 * if the entry is added successfully 
	 * new Entry is at the top of the stack 
	 */ 
	virtual bool push(const T& newEntry) = 0;

	/** 
	 * Removes the top of the stack 
	 * if its successful, the top os the stack is removed 
	 */
	virtual bool pop() = 0;

	/** 
	 * Returns a copy of the stack
	 * without changing it
	 */
	virtual T peek() const = 0;

	/**
	 * Destroys this stack and frees its assigned memory
	 */
	virtual ~StackInterface() {}
	
	/**
	 * Adds a pure funciton method for max()
	 */ 
	virtual T max() const = 0;

	/**
	 * Adds a pure funciton method for mean()
	 */
	virtual T mean() const = 0;
}; 
// end StackInterface class 
#endif // STACK_INTERFACE