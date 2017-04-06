/* -----------------------------------------------------------------------------
 *
 * 	File Name: Queue.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The Queue.h file which will define the Queue class, and give it its varibles and functions
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */

#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include "QueueInterface.h"
#include "PreconditionViolationException.h"

template <typename T>
class Queue : public QueueInterface<T>
{
public:
    /** @pre None.
    *   @post An empty Queue is created.
    */
    Queue();

    /** @pre None.
    *   @post Deletes all nodes in the Queue.
    */
    ~Queue();
	   /*
      @return if the true Queue is empty otherwise return false
  	 */
    bool isEmpty() const;

  	 /*
      @param value is placed at the back of the Queue
  	 */
     void enqueue(const T value);

    /*
    removes the front of the queue
    @throw PreconditionViolationException if attempted on an empty queue
    */
    void dequeue() throw(PreconditionViolationException);

    /*
      @return the value at the front of the queue
      @throw PreconditionViolationException if attempted on an empty queue
    */
    T peekFront() const throw(PreconditionViolationException);

private:
	Node<T>* m_front;
	int m_length;
};

#include "Queue.hpp"

#endif
