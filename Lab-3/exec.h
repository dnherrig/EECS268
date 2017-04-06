/* -----------------------------------------------------------------------------
 *
 * 	File Name: exec.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 3
	Description: The exec.h file which will define the exec class, and give it its varibles and functions
	Last Changed: 9/22/16
 *
 ---------------------------------------------------------------------------- */
#ifndef EXEC_H
#define EXEC_H
#include "MathTools.h"
#include <string>
#include <iostream>

class exec //makes a class for exec
{
	private:

	public:

		MathTools n;//creats a object of type mathtools called n

		double* roots = 0; //makes a roots pointer
		double** xy = nullptr; //makes a xy pointer

		exec();//constructor
		~exec();//destructor



		void run();//defines the run function

};

#endif
