/* -----------------------------------------------------------------------------
 *
 * 	File Name: NegativeDiscriminant.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 3
	Description: The NegativeDiscriminant.h file which will define the NegativeDiscriminant class, and give it its  function ( in the form of a constructor)
	Last Changed: 9/22/16
 *
 ---------------------------------------------------------------------------- */
 #ifndef NEGATIVEDISCRIMINANT_H
 #define NEGATIVEDISCRIMINANT_H
 #include <string>
 #include <iostream>
  #include <stdexcept>

 class NegativeDiscriminant: public std::runtime_error//creates NegativeDiscriminant class
 {

 	public:
 		NegativeDiscriminant(const std::string& msg = "");//constructor

 };

 #endif
