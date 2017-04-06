/* -----------------------------------------------------------------------------
 *
 * 	File Name: exec.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com 
	Assignment Number: Lab 1
	Description: The exec.cpp file which will handel the constructer, and interact with the user, take I/O to the terminal
	Last Changed: 9/6/16  
 *
 ---------------------------------------------------------------------------- */


#include "voterreg.h"
#include "exec.h"
#include <string>
#include <fstream>
#include <iostream>
#include <limits>

exec :: exec(std::string fileName)
	{
		//creates the varibles to be used
		std::string tempString;
		int tempInt = 0;
		m_num = 0;

		std::ifstream inFile; //make an output file stream object

		inFile.open(fileName); //open the file

		if( inFile.is_open() ) //See if the file is open
		{
			inFile >> m_num; //read in the count of entries in the file

			people = new voterreg [m_num];//populate the array with voterreg classes
		
		}

		else
		{
			std::cout << " An error occured, the file could not be opened";//handles the issue if the file defined by the user doesn't exist in the folder
			exit (0);
		}	
		 
		for (int i = 0; i < m_num ; i++)//takes input from the file and assigns it to each voterreg class in the array
		{
	
			inFile >> tempString;
			people[i].setFirstName(tempString);

			inFile >> tempString;
			people[i].setLastName(tempString);

			inFile >> tempInt;
			people[i].setAge(tempInt);

			inFile >> tempString;
			people[i].setAffil(tempString);

		} 
	


		inFile.close(); //close the file


	}

exec:: ~exec()//destructor to prevent leaks
	{
		delete[] people;//deletes the array
	}

void exec:: run()//main program that handles everything
	{

		//defines varibles
		int choice = 0;
		std::string tempString;		

		while (choice != 5)// allows the user to keep making choices as long as they do not exit the program (select 5)
		{ 

			//asks user for a selection
			std :: cout << "1: Query last name\n";
			std :: cout << "2: Query age range\n";
			std :: cout << "3: Query affiliations\n";
			std :: cout << "4: Report number of people with affiliation\n";
			std :: cout << "5: Quit\n";
			std :: cin >> choice;

			if (choice == 1)//handles choice 1

				{

					bool z = false;//sets z to equal false so on multiple searches it will still tell if there is no one found
					
					std:: cout << "Enter last name:";//takes in last name from the user
					std:: cin >> tempString;
					

					for(int i = 0; i< m_num ; i++)//checks for names that match the user input
					{
						if ( people[i].getLastName() == tempString )
						{
							//prints out the record of the users that match the criteria
							std::cout << "Record: ";
							std::cout << people[i].getFirstName() << " " << people[i].getLastName() << ";";
							std::cout << " age " << people[i].getAge() << ";";
							std::cout << " Registered as " << people[i].getAffil();
							std::cout << '\n';
							z = true;//allows the skipping of the line explaining that no one is found
					
						}
						
					}

					if ( z == false )//if no one is found then it will print this fact
					{
						std::cout << "No one with this last name was found.\n";
					}
 
				std::cout << '\n';

				}

			else if(choice == 2)//handles choice 2
				{
					int low = 0;
					int high = 0;
					int age1 = 0;
					int age2 = 0;
					bool x = false;//sets x to equal false so on multiple searches it will still tell if there is no one found

					std:: cout << "Enter one age: ";//asks user for the age		
					std:: cin >> age1;
					
					std:: cout << "Enter the second age: ";//asks the user for a second age		
					std:: cin >> age2;
					
					if( age1 < age2)//sets the larger age to high and the smaller age to low, if they are the same then it picks one
					{
						high = age2;
						low = age1;


					}
					else
					{
						low = age2;
						high = age1;

					}

					for(int i = 0; i< m_num ; i++)
					{

						if ( (people[i].getAge() <= high)&&(people[i].getAge() >= low) )//finds all the voters that are between the age range, to get all the people at one specific age enter the age for both
						{
							//prints out the record of the users that match the criteria
							std::cout << "Record: ";
							std::cout << people[i].getFirstName() << " " << people[i].getLastName() << ";";
							std::cout << " age " << people[i].getAge() << ";";
							std::cout << " Registered as " << people[i].getAffil();
							std::cout << '\n';
							x = true;//allows the skipping of the line explaining that no one is found
						}
					}
						
					if ( x == false )//if no one is found then it will print this fact
					{
						std::cout << "No one with this age was found.\n";
					}

					
					std::cout << '\n';
				}

			else if(choice == 3)//handles choice 3
				{
					std::cout << '\n';
					std:: cout << "Enter Party affiliation:";//takes an input for the party affliation from the user		
					std:: cin >> tempString;
					bool t = false;//sets t to equal false so on multiple searches it will still tell if there is no one found
				
					for(int i = 0; i< m_num ; i++)
					{
						if ( people[i].getAffil() == tempString )//checks the voters for those of the party entered
						{
							//prints out the record of the users that match the criteria
							std::cout << "Record: ";
							std::cout << people[i].getFirstName() << " " << people[i].getLastName() << ";";
							std::cout << " age " << people[i].getAge() << ";";
							std::cout << " Registered as " << people[i].getAffil();
							std::cout << '\n';
							t = true;//allows the skipping of the line explaining that no one is found
						}
						
					}
					if ( t == false )//if no one is found then it will print this fact
					{
						std::cout << "No one with this affiliation was found.\n";
					}

					std::cout << '\n';
				}

			else if(choice == 4)//handles choice 4
				{
					std::cout << '\n';
					std:: cout << "Enter Party affiliation: ";//asks the user for the party they want to count		
					std:: cin >> tempString;
					int count = 0;

					for(int i = 0; i< m_num ; i++)
					{
						if ( people[i].getAffil() == tempString )//every time an entry is of that party it adds one to the count
						{
							count = count + 1;
						}
					}
					std::cout << count;//prints total count
					std::cout << '\n';
					std::cout << '\n';
				}

			else if(choice == 5)// exits the program if 5 is chosen
				{	
					exit(0);
				}
			else //if the user gives something that isnt a vaild input it will tell them it is invalid and restart
				{
					if( std::cin.fail() )//checks for bad input, by checking that it is the correct type,then checking it was a option listed
	    				{
	      					  std::cin.clear(); // unset failbit
	      					  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
						  std::cout << '\n';
	     					  std::cout << "Sorry, your input was not a number, try again\n";
						  std::cout << '\n';
	   				}
					else if((choice > 5) || (choice <= 0))//checks that it is a valid numerical input
					{
						std:: cout << "Invaid input, try again \n";
						std::cout << '\n';
					}

				}

		}
	}
