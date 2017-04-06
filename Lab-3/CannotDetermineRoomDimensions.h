/* -----------------------------------------------------------------------------
 *
 * 	File Name: CannotDetermineRoomDimensions.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 3
	Description: The CannotDetermineRoomDimensions.h file which will define the CannotDetermineRoomDimensions class, and give it its function ( in the form of a constructor)
	Last Changed: 9/22/16
 *
 ---------------------------------------------------------------------------- */
 #ifndef CANNOTDETERMINEROOMDIMENSIONS_H
 #define CANNOTDETERMINEROOMDIMENSIONS_H
 #include <string>
 #include <iostream>

 class CannotDetermineRoomDimensions: public std::runtime_error//creates CannotDetermineRoomDimensions class
 {
 	private:


 	public:
 		CannotDetermineRoomDimensions(const std::string& msg = "");//constructor

 };

 #endif
