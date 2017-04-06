/**
*	Node.hpp
*	Dylan Herrig	
*	9/14/16
*	A hpp file for the Node class to set and get values
*/

#include "Node.h"
#include <string>
#include <iostream>

template <typename T>
Node<T>:: Node(T value)
{
	m_data = value;
	m_next = nullptr;
}

/*
These functions take input and assign it to each classes private varibles
*/

template <typename T>
void Node<T>::setData(T data)
{
	m_data = data;
}

template <typename T>
void Node <T>::setNext(Node<T>* p)
{
	m_next = p;
}

/*
These functions all get the stored varible in the class when they are called and  then return a string or int respectivly as an output.
*/

template <typename T>
T Node<T> :: getData() const
{
	return(m_data);
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
	return(m_next);
}





