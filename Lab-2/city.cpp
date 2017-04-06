/* -----------------------------------------------------------------------------
 *
 * 	File Name: exec.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 2
	Description: The city.cpp file which will retrive the information for specific cities
	Last Changed: 9/14/16  
 *
 ---------------------------------------------------------------------------- */
#include "city.h"
#include "LinkedList.h"
#include "Node.h"
#include <string>
#include <iostream>

/*
These functions take input and assign it to each classes private varibles
*/

city :: city()
{
	m_name = "";
	m_lvl = 0;
	m_pop = 0;
}

void city::setName(std::string n)
{
	m_name = n;
}

void city::setLvl(int lvl)
{
	m_lvl = lvl;
}

void city::setPop(int pop)
{
	m_pop = pop;
}


/*
These functions all get the stored varible in the class when they are called and  then return a string or int respectivly as an output.
*/



std::string city::getName()
	{
		std::string tempString = m_name;
		return(tempString);
	}

int city::getLvl()
	{
		int tempInt = m_lvl;
		return(tempInt);
	}

int city::getPop()
	{
		int tempInt = m_pop;
		return(tempInt);
	}






