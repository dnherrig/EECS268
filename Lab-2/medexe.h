/* -----------------------------------------------------------------------------
 *
 * 	File Name: exec.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 2
	Description: The medexe.h file which will define the medexe class
	Last Changed: 9/14/16  
 *
 ---------------------------------------------------------------------------- */
#ifndef medexe_H
#define medexe_H
#include "city.h"
#include "LinkedList.h"
#include "Node.h"
#include <string>
#include <iostream>

class medexe //defines the templeted medexe's varibles and functions
{
	private:
		city mycity();
		LinkedList<city> clist;
		LinkedList<city> qclist;
		int m_length;
		
	public:
		medexe(std::string fileName);
		~medexe();
		void tosort(city newcity);
		void run();
	

};

#endif
