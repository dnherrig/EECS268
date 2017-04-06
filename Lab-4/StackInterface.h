/* -----------------------------------------------------------------------------
 *
 * 	File Name: StackInterface.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The StackInterface.h file which will outline the virtual functions of the class
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */
// StackInterface.h - An interface for various mathematical tools

#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
//#include "Node.h"
#include "PreconditionViolationException.h"

template <typename T>
class StackInterface
{
  public:

    /*
     @return if the true Stack is empty otherwise return false
    */
   virtual bool isEmpty() const = 0;

    /*
     @param value is placed at the top of the Stack
     @throw PreconditionViolation if the push cant occur (the Stack is full)
    */
   virtual void push(const T value) throw(PreconditionViolationException) = 0;

   /*
   removes the top of the Stack
   @throw PreconditionViolation if attempted on an empty Stack
   */
   virtual void pop() throw(PreconditionViolationException) = 0;

   /*
     @return the value at the top of the Stack
     @throw PreconditionViolation if attempted on an empty Stack
   */
   virtual T peek() const throw(PreconditionViolationException) = 0;

   virtual ~StackInterface(){};

};

#endif
