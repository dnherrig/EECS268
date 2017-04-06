/* -----------------------------------------------------------------------------
 *
 * 	File Name: main.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The main.cpp file which will handel the comand ling arguments, and take them into the file, it will also call the run function
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <fstream>
#include "BuildingExecutive.h"


int main(int argc, char** argv)
	{

 		if(argc == 2)//checks that the user game two comand line inputs
   		 {
     			std::string fileName="";  
     			fileName = argv[1];
					BuildingExecutive myexec;//makes an isnstance of the function
    			myexec.run(fileName);//runs the program and passes the file name to the compilier
  		 }
    	else
    	{
       		std :: cout << "Sorry, you didn't give the right number of command line arguments. 2 are REQUIRED.\n";
			      std :: cout << "The second should be the  in the format yourfile.txt \n";// tells the user if they gave bad input and how to fix it
			}


		return(0);
	}
