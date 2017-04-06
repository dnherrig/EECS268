/* -----------------------------------------------------------------------------
 *
 * 	File Name: PreconditionViolationException.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The PreconditionViolationException.h file which will define the PreconditionViolationException class, and give it its  function ( in the form of a constructor)
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */
 #ifndef PRECONDITIONVIOLATIONEXCEPTION_H
 #define PRECONDITIONVIOLATIONEXCEPTION_H
 #include <string>
 #include <iostream>
  #include <stdexcept>

 class PreconditionViolationException: public std::runtime_error//creates PreconditionViolationException class
 {

 	public:
 		PreconditionViolationException(const std::string& msg = "");//constructor

 };

 #endif
