/* -----------------------------------------------------------------------------
 *
 * 	File Name: voterreg.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 1
	Description: The voterreg.h file which will create the voterreg class and define all of the functions and varibles it will use
	Last Changed: 9/6/16  
 *
 ---------------------------------------------------------------------------- */
#ifndef voterreg_H
#define voterreg_H
#include <string>
#include <iostream>

class voterreg
{
	private:
	
		//declare varibles for the voterreg class
		std::string m_firstName;
		std::string m_lastName;
		std::string m_affil;
		std::string m_voteReg;
		int m_age;
		int tempInt;
		std::string tempString;

		

	public:

		//functions for the voterreg class
		std::string getFirstName();
		void setFirstName(std::string fn);
		std::string getLastName();
		void setLastName(std::string ln);
		std::string getAffil();
		void setAffil(std::string af);		
		int getAge();
		void setAge(int a);

};

#endif 

