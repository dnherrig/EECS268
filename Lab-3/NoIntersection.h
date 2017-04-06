/* -----------------------------------------------------------------------------
 *
 * 	File Name: NoIntersection.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 3
	Description: The NoIntersection.h file which will define the NoIntersection class, and give it its function ( in the form of a constructor)
	Last Changed: 9/22/16
 *
 ---------------------------------------------------------------------------- */
 #ifndef NOINTERSECTION_H
 #define NOINTERSECTION_H
 #include <string>
 #include <iostream>

 class NoIntersection: public std::runtime_error//creates NoIntersection class
 {
 	private:


 	public:

 		NoIntersection(const std::string& msg = "");//constructor

 };

 #endif
