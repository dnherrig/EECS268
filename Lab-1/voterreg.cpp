/* -----------------------------------------------------------------------------
 *
 * 	File Name: voterreg.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 1
	Description: The voterreg.cpp file which will handle all of the functions for the run function
	Last Changed: 9/6/16  
 *
 ---------------------------------------------------------------------------- */
#include "voterreg.h"
#include "exec.h"
#include <string>
#include <iostream>

/*
These functions take input and assign it to each classes private varibles
*/


	void voterreg::setFirstName(std::string fn)
	{
		m_firstName = fn;

	}

	void voterreg::setLastName(std::string ln)
	{
		m_lastName = ln;
	}

	void voterreg::setAffil(std::string af)
	{
		m_affil = af;
	}		

	void voterreg::setAge(int a)
	{
		m_age = a;
	}


/*
These functions all get the stored varible in the class when they are called and  then return a string or int respectivly as an output.
*/

	std::string voterreg::getFirstName()
	{
		tempString = m_firstName;
		return(tempString);
	}

	std::string voterreg::getLastName()
	{
		tempString = m_lastName;
		return(tempString);
	}

	std::string voterreg::getAffil()
	{
		tempString = m_affil;
		return(tempString);
	}
	int voterreg::getAge()
	{
		tempInt = m_age;
		return(tempInt);
	}





