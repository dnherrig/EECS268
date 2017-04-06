/* -----------------------------------------------------------------------------
 *
 * 	File Name: exec.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 2
	Description: The main.cpp file which will handle the constructer, and interact with the user, take I/O to the terminal
	Last Changed: 9/14/16  
 *
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "city.h" 
#include "medexe.h"
#include "LinkedList.h" 
#include "Node.h"


int main( int argc, char** argv)
	{

 		if(argc == 2)//checks that the user game two comand line inputs
   		 {  
     			std::string fileName="";
     			fileName = argv[1];
      			medexe mymedexe(fileName);
    			mymedexe.run();//runs the program

  		 }
    		else
    		{
        		std :: cout << "Sorry, you gave the wrong number of command line arguments.\n"; 
			std :: cout << "Your second argument should be in this form: yourfile.txt \n";// tells the user if they gave bad input and how to fix it
		}    


		return(0);
	}
