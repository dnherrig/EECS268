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

#include "Node.h"
#include "PreconditionViolationException.h"


template <typename T>
Queue<T> :: Queue()
{
  m_front = nullptr;//sets the front initally to nullptr
  m_length = 0;
}



template <typename T>
Queue<T> :: ~Queue()
{
  while(m_front != nullptr)//calls on the pop as long as m-front is not nullptr
  {
    dequeue();
  }
}

template <typename T>
bool Queue<T> :: isEmpty()const//return that the queue is empty or not
{
  if (m_front == nullptr)
	{
		return(true);
	}
	else
	{
		return(false);
	}

}

template <typename T>
void Queue<T> :: enqueue(const T value)
{
    Node<T>* back = new Node<T>(value);

  	if(m_front == nullptr)//sets back to m_front
  	{
  		m_front = back;
  	}
  	else//progresses down the node until it reaches the back then sets the back function to a new value
  	{
  		Node<T>* temp = m_front;

  		while (temp -> getNext() != nullptr)
  		{
  			temp = temp -> getNext();
  		}

  		temp -> setNext(back);

  	}

}

template <typename T>
void Queue<T> :: dequeue() throw(PreconditionViolationException)
{
  if (m_front != nullptr)
	{
		Node<T>* temp = m_front;
		m_front = temp -> getNext();
		delete temp;//deletes the temp that was looking at the next node
	}
	else
	{
		throw PreconditionViolationException("No one will enter as there is no one in line.");
	}
}

template <typename T>
T Queue<T> :: peekFront() const throw(PreconditionViolationException)
{
  //initalizes the varibles
  Node<T>* tempPtr = m_front;

  if (m_front != nullptr)
	{
		return(tempPtr->getData());//gets the data from the entry
	}
	else
	{
		throw PreconditionViolationException("There is no one in line.");
	}

}
