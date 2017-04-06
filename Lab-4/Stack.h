/* -----------------------------------------------------------------------------
 *
 * 	File Name: Stack.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The Stack.h file which will define the Stack class, and give it its varibles and functions
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */

#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"

template <typename T>
class Stack : public StackInterface<T>
{
  public:
      /** @pre None.
  	*   @post An empty Stack is created.
  	*/
  	Stack();

  	/** @pre None.
  	*   @post Deletes all nodes in the Stack.
  	*/
  	~Stack();

    /*
     @return if the true Stack is empty otherwise return false
    */
    bool isEmpty() const;

    /*
     @param value is placed at the top of the Stack
     @throw PreconditionViolationException if the push cant occur (the Stack is full)
    */
    void push(const T value) throw(PreconditionViolationException);

    /*
    removes the top of the Stack
    @throw PreconditionViolationException if attempted on an empty Stack
    */
    void pop() throw(PreconditionViolationException);

    /*
     @return the value at the top of the Stack
     @throw PreconditionViolationException if attempted on an empty Stack
    */
     T peek() const throw(PreconditionViolationException);

    private:
       	Node<T>* m_front;
       	int m_length;

};

#include "Stack.hpp"

#endif
