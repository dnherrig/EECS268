/* -----------------------------------------------------------------------------
 *
 * 	File Name: main.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 1
	Description: The main.cpp file which will handel the comand ling arguments, and take them into the file, it will also call the run function
	Last Changed: 9/6/16  
 *
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "exec.h"
#include "voterreg.h"


int main(int argc, char** argv)
	{

 		if(argc == 2)//checks that the user game two comand line inputs
   		 {  
     			std::string fileName="";
     			fileName = argv[1];
      			exec myexec(fileName);
    			myexec.run();//runs the program

  		 }
    		else
    		{
        		std :: cout << "Sorry, you didn't give the right number of command line arguments. 2 are REQUIRED.\n"; 
			std :: cout << "The second should be the  in the format yourfile.txt \n";// tells the user if they gave bad input and how to fix it
		}    


		return(0);
	}





