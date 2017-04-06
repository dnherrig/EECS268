/* -----------------------------------------------------------------------------
 *
 * 	File Name: exec.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 1
	Description: The exec.h file which will define the exec class, and give it its varibles and functions
	Last Changed: 9/6/16  
 *
 ---------------------------------------------------------------------------- */
#ifndef exec_H
#define exec_H
#include "voterreg.h"
#include <string>
#include <iostream>

class exec//creates exec class
{
	private:
		voterreg* people; //sets people to be an array of voterreg classes
		int m_num;

	public:
		exec(std::string fileName);//constructor takes a file name
		~exec();
		void run();//defines the run function

};

#endif
