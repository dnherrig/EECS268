/**
*	LinkedList.h
*	Dylan Herrig	
*	9/14/16
*	A header file for templated Node class
*/

#ifndef Node_H
#define Node_H
#include <string>
#include <iostream>


template <typename T>
class Node //defines the templeted node's varibles and functions
{
	public:
	
	Node(T value);

	T getData() const;
	Node<T>* getNext() const;
	void setData(T data);
	void setNext(Node<T>* p);
	


	private:
	T m_data;
	Node<T>* m_next;


};

#include "Node.hpp" 

#endif
