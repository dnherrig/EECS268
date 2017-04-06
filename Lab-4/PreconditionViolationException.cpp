/* -----------------------------------------------------------------------------
 *
 * 	File Name: PreconditionViolation.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The PreconditionViolation.cpp file which will which will describe a custom error
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */
#include <iostream>
#include "PreconditionViolationException.h"


PreconditionViolationException :: PreconditionViolationException(const std::string& msg): std::runtime_error(msg)//defines the message that will be thrown
{


}
