/* -----------------------------------------------------------------------------
 *
 * 	File Name: BuildingExecutive.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The BuildingExecutive.cpp file which will handel the constructer, and interact with the user, take I/O to the terminal
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */

#include "BuildingExecutive.h"
#include <string>
#include <fstream>
#include <iostream>



void BuildingExecutive :: run(std::string fileName)
  {
		std::ifstream inFile;
		inFile.open(fileName);


		//initalize varibles
		std::string tempString1;
		std::string tempString2;
		std::string nextIn;
		int tempNum = 0;

		//check that the file was correctly opeed in the compilier
		if( inFile.is_open())
		{
			//continues to run the program as long at the end of the file has not been reached
			while(!inFile.eof())
			{
				inFile >> tempString1;//takes in the first part of a line

				if (tempString1 == "WAIT")// if that command is wait then this will run
				{
					inFile >> tempString2;//take in the name
					//std::cout << tempString2 << " gets in line.\n";
					line.enqueue(tempString2);//enqueue that person
          tempString1 = "";//resets the tempString1 selector to nothing


				}
				else if(tempString1 == "PICK_UP")// if that command is pick_up then this will run
				{
					while(line.isEmpty() == false)
					{
						try
						{
							nextIn = line.peekFront();//can throw an exception
						}
						catch(PreconditionViolationException& e)
						{
							std::cout << e.what();//print the exception, then break out of the while loop
							break;
						}

						try
						{
							elevator.push(nextIn);//can throw an exception
							line.dequeue();//can throw an exception
						//	std::cout << nextIn << " gets out of line.\n";
						//	std::cout << nextIn << " gets into the elevator.\n";

						}
						catch(PreconditionViolationException& e)
						{
							//std::cout << e.what();//print the exception, then break out of the while loop
							break;//break out of the while loop if the elevator is full

						}
					}
            tempString1 = "";//resets the tempString1 selector to nothing

				}
				else if(tempString1 == "DROP_OFF")// if that command is drop off then this will run
				{
					inFile >> tempString2;//takes in the num that is placed after the drop off
					tempNum = std::stoi(tempString2);

					//std::cout << tempNum << "\n";

					for (int i = 0; i<tempNum ; i++)
					{
						try
						{
							elevator.pop();//can throw an exception
						//	std::cout << "Someone gets off the elevator.\n";
						}
						catch(PreconditionViolationException& e)
						{
							std::cout << e.what();//print the exception
              break;//breaks out of the loop if there is no one on the elevator
						}
					}
          tempString1 = "";//resets the tempString1 selector to nothing


				}
				else if(tempString1 == "INSPECTION")// if that command is inspection then this will run
				{
					std::cout << "----------------------------------\n";//used to split up the elevator status reports
					std::cout << "Elevator status: \n";


					if (elevator.isEmpty() == true)//report the elevator status of being empty or not
						{
							std::cout << "The elevator is empty.\n";
						}
					else
						{
							std::cout << "The elevator is not empty.\n";
						}

						try
						{
							std::cout << elevator.peek() << " will be the next person to leave the elevator.\n";//can throw an exception
						}
						catch(PreconditionViolationException& e)//catches the exception if there is no one in the elevator and repots this
						{
							std::cout << e.what();
						}

						try
						{
							std::cout << line.peekFront() << " will be the next person to get on the elevator.\n";//can throw an exception
						}
						catch(PreconditionViolationException& e)//catches the exception if there is no one in line and reports this
						{
							std::cout << e.what() << '\n';
						}

						std::cout << "----------------------------------\n";//used to split up the elevator status reports

            tempString1 = "";//resets the tempString1 selector to nothing

				}



			}

		}
		else
		{
			std::cout << " An error occured, the file could not be opened";//handles the issue if the file defined by the user doesn't exist in the folder
			exit (0);
		}

		inFile.close();//closes the file

  }
