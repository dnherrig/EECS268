/**
*	LinkedList.hpp
*	Dylan Herrig	
*	9/14/16
*	A hpp file for templated LinkedList class
*/


#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>


template <typename T>

LinkedList<T> :: LinkedList()
{

        m_front = nullptr;//sets the front initally to nullptr
	m_length = 0;

}



template <typename T>

LinkedList<T> :: ~LinkedList()
{
	
        while(m_front != nullptr)//calls on the removeback as long as m-front is not nullptr
	{
		removeBack();
	}

}



template <typename T>

bool LinkedList<T> :: isEmpty() const//checks to see if the list is empty by checking nullptr
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

int LinkedList<T> :: getLength() const//returns the value of the member varible of length from the function
{
	
		return(m_length);

}



template <typename T>

int LinkedList<T> :: positionOf(T value) const
{
	if(m_front == nullptr)//checks that it isnt the first pointer
	{
		return (0);
	}
	else
	{
		int pos = 1;
		Node<T>* temp = m_front;
		while(temp -> getData() != value)
		{
			temp = temp -> getNext();
			pos++;
		}
		return(pos);//returns the position basd on the number of times you progressed
	}
}



template <typename T>

void LinkedList<T> :: addBack(T value)
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

void LinkedList<T> :: addFront(T value)
{
	Node<T>* temp = new Node<T>(value);
	
	if (m_front == nullptr)
	{
		m_front = temp;//sets the temp to m_front
	}
	
	else//uses setNext to set the temp to m_front
	{
		temp -> setNext(m_front);
		m_front = temp;
	}
	
	m_length++;	

}

template <typename T>

bool LinkedList<T> :: insert(int position, T value)
{
	Node<T>* temp = new Node<T>(value); 
	
	if(position < 1 || position > m_length + 1)//returns false if the position is outside of the length
	{
		return(false);
	}
	else if(position == 1)//at position one it takes a diffrent action
	{
		temp -> setNext(m_front);//sets temp to be the first node front
		
		m_front = temp;
		m_length++;
		return(true);
	}
	else
	{
		//initalizes varibles to be used

		Node<T>* tempPtr = m_front; 
		int tempPos = 1;

		while(tempPos < position-2)//progresses down the list
		{
			
			tempPtr = tempPtr -> getNext();
			tempPos++;
		}
		if(tempPtr->getNext() != nullptr)//makes sure that you are not setting someting as nullptr
		{
			temp-> setNext(tempPtr->getNext());
		}
		
		

		tempPtr->setNext(temp);//sets the tempPtr to look at the next node
		m_length++;//increases the length of the node by 1
		return(true);
	}

}



template <typename T>

bool LinkedList<T> :: removeBack()
{
	if(m_front == nullptr)//checks to see that the list exists
	{
		return (false);
	}
	else if(m_length)//if the given node is the last one of this length then it deletes
	{
		Node<T>* temp = m_front;
		delete temp;
		m_front = nullptr;
		m_length--;//reduces the know size of the list
		return(true);
	}
	else
	{
		Node<T>* temp = m_front;
		while(temp -> getNext() -> getNext() != nullptr)//moves through the linked list
		{
			temp = temp -> getNext();
		}
		Node<T>* temp2 = temp -> getNext();
		delete temp2;//deletes the get next
		temp = nullptr;
		m_length --;//reduces the know size of the list
		return(true);
	}
}



template <typename T>

bool LinkedList<T> :: removeFront()
{
	if (m_front != nullptr)
	{
		Node<T>* temp = m_front;
		m_front = temp -> getNext();
		delete temp;//deletes the temp that was looking at the next node
		return (true);
	}
	else
	{
		return(false);
	}

}



template <typename T>

bool LinkedList<T> :: removeAt(int position)
{
	Node<T>* tempptr = m_front;
	
	int temppos = 1;
	
	bool wasremoved = false;

	if (tempptr != nullptr)//checks that there is a list
	{

		while ((tempptr ->setNext() != nullptr) && !(wasremoved))
		{
			if (temppos == position - 1)
			{

			}
			else if ( position == 1)
			{
				removeFront();//uses the remove front function if we are at the begining
				m_length--;
				wasremoved = (true);
			}

			tempptr = tempptr -> getNext();//moves through the list
			temppos++;

		}
	}

	return(wasremoved);


}



template <typename T>

void LinkedList<T> :: setEntry(int position, T value)
{
	//initalizes the varibles
	int tempPos = 1;
	Node<T>* tempPtr = m_front;

	
	if (position > m_length || isEmpty())//checks that the given position exists
	{
		std::cout << "Position does not exist";
	}
	else
	{
		while(tempPos < position-1)//progresses through the  list
		{
			
			tempPtr = tempPtr -> getNext();
			tempPos++;
		}

		tempPtr->setData(value); //sets the node to a value using setData
			
		
	}

}



template <typename T>

T LinkedList<T> :: getEntry( int position ) const
{
	//initalizes the varibles
	int tempPos = 1;
	Node<T>* tempPtr = m_front;

	
	while(tempPos < position-1)//progresses through the linked list
		{
			
			tempPtr = tempPtr -> getNext();
			tempPos++;
		}

	return(tempPtr->getData());//gets the data from the entry
	


}


