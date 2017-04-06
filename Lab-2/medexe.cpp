/* -----------------------------------------------------------------------------
 *
 * 	File Name: exec.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 2
	Description: The medexe.cpp file which will interact with the user and call classes accordingly
	Last Changed: 9/14/16  
 *
 ---------------------------------------------------------------------------- */
#include "city.h"
#include "medexe.h"
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream> 



medexe :: medexe(std::string fileName)
	{
	
		//opens the file

		std::string tempString;
		
		std::ifstream inFile;
		
		inFile.open(fileName);

		if( inFile.is_open())
		{

			while(!inFile.eof())//checks for the end of the file
			{
				std::string name = "";
				std::string pop = "";
				std::string lvl = "";

				// these functions takes in lines of information from the file as their respective types

				
				//std::cout <<"A: " << name << '\n';
				std::getline(inFile, name, ',');
				//std::cout <<"B: "<< name << '\n';

				std::getline(inFile, pop, ',');
				int tempval1 = atoi(pop.c_str());
				//std::cout << tempval1 << '\n';

				std::getline(inFile, lvl, '\n');
				int tempval2 = atoi(lvl.c_str());
				//std::cout << tempval2 << '\n';
				
				

				if(name == "")//ignores an enrty with no name
				{

				}
				else
				{
					//assigns the taken in values to each class
					city mycity = city();
					mycity.setName(name);
					mycity.setPop(tempval1);
					mycity.setLvl(tempval2);
					tosort(mycity);
					//std::cout << "SAVING THIS: "<< name << tempval1 << tempval2 << '\n';

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

medexe :: ~medexe()
	{

		
	
	}


void medexe::tosort(city newcity)//sorts the citys by population
	{
		{	

	
			if (clist.isEmpty())//if the list is empty it will place the first class in the front
			{
				clist.addFront(newcity);
				//std::cout << "Inserting city with pop: "<< newcity.getPop() << '\n';
			}
			else
			{
				int currentPosition = 1;
				//std::cout << "CurrentCity Pop "<< clist.getEntry(currentPosition).getPop() << '\n';
					
				
					while(newcity.getPop() < (clist.getEntry(currentPosition).getPop()))//checks the population of each class and increments untill the new city is in the correct spot
					{
										
						currentPosition++;
						if(currentPosition > clist.getLength())
						{
							break;
						}
						
					}
				

					clist.insert(currentPosition, newcity);// inserts the newcity class in the correct place

					//std::cout << "Inserting city with pop: "<< newcity.getPop() << " at position " << currentPosition << '\n';
					//std::cout << "CurrentCity Pop in list: " << clist.getEntry(currentPosition).getPop() << '\n';	
					
				
				 	
				
			}	
			
		}
	}





void medexe::run()
	{
		int choice = 0;


		//manages user input
		while (choice != 6)
		{

			std::string temp = "";

			std::cout << '\n';
			std::cout << "Make a selection:\n";
			std:: cout << "1) Increase the infection level of all cities\n";
			std:: cout << "2) Increase the infection level of a specific city\n";
			std:: cout << "3) Print status of a specific city\n";
			std:: cout << "4) Create a quarantine log and print it to a file\n";
			std:: cout << "5) Print all cities above an infection level\n";
			std:: cout << "6) Exit\n";
			std:: cout << "Choice: ";
			std::getline(std::cin, temp);//takes user input
			choice = atoi(temp.c_str());//converts it to an int
		

			if (choice == 1)
			{
				int currentPosition = 2;
					
				/*
				std::cout << "City Name: "<< clist.getEntry(1).getName() << " at position " << "1" << '\n';	
				std::cout << "City infection level: "<< clist.getEntry(1).getLvl() << " at position " << "1" << '\n';
				
				std::cout << "City Name: "<< clist.getEntry(2).getName() << " at position " << "2" << '\n';
				std::cout << "City infection level: "<< clist.getEntry(2).getLvl() << " at position " << "2" << '\n';


				std::cout << "City Name: "<< clist.getEntry(3).getName() << " at position " << "3" << '\n';
				std::cout << "City infection level: "<< clist.getEntry(3).getLvl() << " at position " << "3" << '\n';			
				*/
				
					while(currentPosition < clist.getLength())
					{
						clist.getEntry(currentPosition).setLvl(clist.getEntry(currentPosition).getLvl()+1);//sets the infection level to the previous level plus 1
						currentPosition++;						
					}
				
				/*
				std::cout << "City Name: "<< clist.getEntry(1).getName() << " at position " << "1" << '\n';	
				std::cout << "City infection level: "<< clist.getEntry(1).getLvl() << " at position " << "1" << '\n';
				
				std::cout << "City Name: "<< clist.getEntry(2).getName() << " at position " << "2" << '\n';
				std::cout << "City infection level: "<< clist.getEntry(2).getLvl() << " at position " << "2" << '\n';


				std::cout << "City Name: "<< clist.getEntry(3).getName() << " at position " << "3" << '\n';
				std::cout << "City infection level: "<< clist.getEntry(3).getLvl() << " at position " << "3" << '\n';			
				*/


				std::cout <<'\n';
				std::cout << "Infection levels for all cities has been increased \n";
				
			}

			else if(choice == 2)//Increases the infection level of a city
			{
				std::string cname = "";
				std::cout << "Which city would you like to infect?: ";
				std::getline(std::cin, cname);//takes in the user input and allows for citys with spaces in names

				int currentPosition = 2;
				bool check = false;

				while(currentPosition < clist.getLength())//increments the citys infection level by 1
					{
						if( cname == clist.getEntry(currentPosition).getName())
						{
							clist.getEntry(currentPosition).setLvl(clist.getEntry(currentPosition).getLvl()+1);
							check = true;
						}
						currentPosition++;
						
						
					}
				
				if(check == false)// tells the user if their city is not in the list
				{
					std::cout << "Sorry " << cname<< " was not a city in the list\n"; 
				}

				
				
				std::cout << "Infection level for "<< cname << "increased by 1\n";
				std::cout << '\n';
			}

			else if(choice == 3)//Prints the status of a specified city
			{
				
				std::string cname = "";
				std::cout << "Define the city by name: ";
				std::getline(std::cin, cname);//takes in a user defined city
			
				int currentPosition = 2;
				bool check = false;

				while(currentPosition < clist.getLength()+1)//searches the linked list for a city with the name
					{
						if( cname == clist.getEntry(currentPosition).getName())//increments the city of the given name
						{
							std::cout << "City Population: "<< clist.getEntry(currentPosition).getPop() << '\n' << "City infection level: " << clist.getEntry(currentPosition).getLvl() << '\n';
							check = true;
						}
						
						currentPosition++;
						
						
					}
				if(check == false)// tells the user if their city is not in the list
				{
					std::cout << "Sorry " << cname<< " was not a city in the list\n"; 
				}
			
						

	
			}

			else if(choice == 4)
			{
				std::string fname = "";
				std::cout << "Name the file you want to output to: ";//asks the user for the name of the file they want to make
				std::getline(std::cin, fname);
				

				std::ofstream outFile;
				outFile.open(fname);//opens the created file
			
				int currentPosition = 2;

				while(currentPosition <= clist.getLength())//moves through the linked list
					{
						//prints each part of each class to the new file
						outFile << clist.getEntry(currentPosition).getName() << ", ";
						outFile << clist.getEntry(currentPosition).getPop() << ", ";
						outFile << clist.getEntry(currentPosition).getLvl() << "\n";

						currentPosition++;
						
						
					}
				outFile.close();

				std::cout << "Done\n";				



			}

			else if(choice == 5)
			{
				int currentPosition = 2;
				int userlv = 0;
				std::string temp;
				bool check = false;
				std::cout << "What infection level are you looking for?: "; //asks user of the infection level they are looking for
				std::getline(std::cin, temp);
				userlv = atoi(temp.c_str());
				
				std::cout << "The cities above this level are: \n";
			
	
				while(currentPosition <= clist.getLength())//moves through the linked list
					{
						

						if(userlv < clist.getEntry(currentPosition).getLvl())
						{
							std::cout << clist.getEntry(currentPosition).getName() << '\n';
							check = true;
						}

						currentPosition++;
					}

				if(check == false)
				{
					std::cout << "None";
				} 
			}

			else if(choice == 6)
			{
				std::cout << "Goodbye!\n" << '\n'; //exits the program
				exit(0);
			}

			else
			{
				if( std::cin.fail() )//checks for bad input, by checking that it is the correct type,then checking it was a option listed
	    				{
	      					  std::cin.clear(); // unset failbit
	      					  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
						  std::cout << '\n';
	     					  std::cout << "Sorry, your input was not a number, try again\n";
						  std::cout << '\n';
	   				}
					else if((choice > 6) || (choice <= 0))//checks that it is a valid numerical input
					{
						std:: cout << "Invaid input, try again \n";
						std::cout << '\n';
					}
			}



		}		


	}
