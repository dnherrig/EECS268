/* -----------------------------------------------------------------------------
 *
 * 	File Name: exec.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 2
	Description: The city.h file which will define the city class
	Last Changed: 9/14/16  
 *
 ---------------------------------------------------------------------------- */
#ifndef city_H
#define city_H
#include "LinkedList.h"
#include "Node.h"
#include <string>
#include <iostream>

class city //defines the templeted city's varibles and functions
{
	private:
		std::string m_name;
		int m_pop;
		int m_lvl; 



	public:
		city();
		void setName(std::string n);
		std::string getName();
		void setLvl(int lvl);
		int getLvl();
		void setPop(int pop);
		int getPop();
		
};
#endif
