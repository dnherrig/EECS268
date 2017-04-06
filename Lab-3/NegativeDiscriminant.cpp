/* -----------------------------------------------------------------------------
 *
 * 	File Name: NegativeDiscriminant.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 3
	Description: The NegativeDiscriminant.cpp file which will which will describe a custom error
	Last Changed: 9/22/16
 *
 ---------------------------------------------------------------------------- */
#include <iostream>
#include "NegativeDiscriminant.h"


NegativeDiscriminant :: NegativeDiscriminant(const std::string& msg): std::runtime_error("Exception defined by programer: " + msg)//defines the message that will be thrown
{


}
