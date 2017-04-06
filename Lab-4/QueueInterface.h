/* -----------------------------------------------------------------------------
 *
 * 	File Name: QueueInterface.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The QueueInterface.h file which will outline the virtual functions of the class
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */
// QueueInterface.h - An interface for various mathematical tools

#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H
//#include "Node.h"
#include "PreconditionViolationException.h"

template <typename T>
class QueueInterface
{
  public:

    	 /*
        @return if the true queue is empty otherwise return false
    	 */
    	virtual bool isEmpty() const = 0;

    	 /*
        @param value is placed at the back of the queue
    	 */
    	virtual void enqueue(const T value) = 0;

      /*
      removes the front of the queue
      @throw PreconditionViolationException if attempted on an empty queue
      */
      virtual void dequeue() throw(PreconditionViolationException) = 0;

      /*
        @return the value at the front of the queue
        @throw PreconditionViolationException if attempted on an empty queue
      */
      virtual T peekFront() const throw(PreconditionViolationException) = 0;

  	  virtual ~QueueInterface(){};

};

#endif
