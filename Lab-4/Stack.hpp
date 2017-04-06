/* -----------------------------------------------------------------------------
 *
 * 	File Name: Stack.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The Stack.cpp file which will define the function that are a part of the Stack class
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */
#include "PreconditionViolationException.h"
#include "Node.h"
#include <iostream>
#include <string>

template <typename T>
Stack<T> :: Stack()
{
  m_front = nullptr;//sets the front initally to nullptr
  m_length = 0;
}



template <typename T>
Stack<T> :: ~Stack()
{
  while(m_front != nullptr)//calls on the pop as long as m-front is not nullptr
  {
    pop();
  }
}


template <typename T>
bool Stack<T> :: isEmpty() const//check to see if the stack is empty
{
  if (m_front == nullptr)//if it is empty then return true otherwise return false
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

template <typename T>
void Stack<T> :: push(const T value) throw(PreconditionViolationException)
{
  if(m_length == 7)//if the elevator is at capasity then throw an exception that the elevator is full
  {
    throw PreconditionViolationException("Elevator is full!\n");
  }

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
  m_length++;


}

template <typename T>
void Stack<T> :: pop() throw(PreconditionViolationException)
{
    if(isEmpty() == true)//checks to see that the Stack exists
  	{
  		throw PreconditionViolationException("The elevator is empty so no one will get off.\n");
  	}
    else
    {
      T entry = m_front -> getData();
      Node<T>* temp = m_front -> getNext();
      m_front -> setNext(nullptr);
      delete m_front;
      m_front = temp;
      m_length --;

    }

}

template <typename T>
T Stack<T> :: peek() const throw(PreconditionViolationException)
{
    if(isEmpty() == true)
    {
      throw PreconditionViolationException("No one is in the elevator.\n");
    }

    int tempPos = m_length;
  	Node<T>* tempPtr = m_front;

  	while((tempPtr -> getNext()) != nullptr)//progresses through the Stack
  		{

  			tempPtr = tempPtr -> getNext();
  			tempPos++;
  		}

  	return(tempPtr->getData());//gets the data from the entry

}
