/* -----------------------------------------------------------------------------
 *
 * 	File Name: exec.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 3
	Description: The exec.cpp file which will handle the constructer, and interact with the user
	Last Changed: 9/22/16
 *
 ---------------------------------------------------------------------------- */

#include "exec.h"
#include "MathTools.h"
#include <iostream>
#include <limits>
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"
#include "NegativeDiscriminant.h"


exec :: exec()//creats two arrays that will be passed between functions
  {

		roots = new double[2];

    xy = new double*[2];

    for(int i = 0; i<= 2; i++)//makes a 2d array
    {
      xy[i] = new double [2];
    }

  }

exec :: ~exec()//delets the two arrays that were created in the constructor
  {
    delete[] roots;

    for (int i = 0; i < 2; i++) //delete the array
  		{
  			delete[] xy[i];
  		}

  }

void exec :: run()//run function that will handle user input
  {
    int choice  = 0;


    while(choice != 4)
    {
        //gives the user a set of options to pick from

        std::cout << "Make a selection:\n";
        std::cout << "1. Enter A, B, C for the quardratic equation to be solved\n";
        std::cout << "2. Enter the d, e, and f parameters for a line to be intersected with a unit circle\n";
        std::cout << "3. Enter Area, Extra, and minRequiredLength for a ballroom\n";
        std::cout << "4. Quit\n";
        std::cin >> choice;

        try//trys all the functions that the user may choose
          {
            if(choice == 1)//used if the user is looking to solve a quadratic
            {

              double A = 0.0;
              double B = 0.0;
              double C = 0.0;
              int rootsnum = 0;

              //takes in user input for coefficients.

              std::cout << "You have chosen a quadratic equation.\n";
              std::cout << "Please enter A: ";
              std::cin >> A;
              std::cout << "Please enter B: ";
              std::cin >> B;
              std::cout << "Please enter C:";
              std::cin >> C;
              std::cout << "---------------------------\n";

              //solves the quadratic using the user values and edits the array to the results, then returns the number of roots

              rootsnum = n.solveQuadratic(A, B, C, roots);

              if (rootsnum == 1)//prints one root if there is one root
              {
                std::cout << "The one root is " << roots[1] << "\n";
              }
              else if (rootsnum == 2)//prints the two roots if there are two roots
              {
                std::cout << "One root is " << roots[1] << "\n";
                std::cout << "The other root is " << roots[2] << '\n';
              }
              std::cout << "---------------------------\n";


            }
            else if(choice == 2)//used if the user is trying to find where the quadratic intersects the unit circle
            {

              double d = 0.0;
              double e = 0.0;
              double f = 0.0;
              int intersectionsnum = 0;

              //takes in user input for each coefficient of the equation

              std::cout << "You have chosen to find the points at which a line intresects the unit circle.\n";
              std::cout << "Please enter d: ";
              std::cin >> d;
              std::cout << "Please enter e: ";
              std::cin >> e;
              std::cout << "Please enter f: ";
              std::cin >> f;

              std::cout << "---------------------------\n";

              //checks if the provided equation will intersect the circle , and places the results in the array. then returns the number of points

              intersectionsnum = n.intersectLineUnitCircle(d, e, f, xy);

              if(intersectionsnum == 1)//if there is one intersection then this will run and print out the values of x and y for that point
              {
                std::cout << "There are one point of intersection!\n";
                std::cout << "It is at: (" << xy[1][1] << "," << xy[1][2] << ")\n";
                std::cout << "---------------------------\n";
              }
              else if(intersectionsnum == 2)// if there are two intersecting points then this will run and print the x and y values at those points
              {
                std::cout << "There are two points of intersection!\n";
                std::cout << "One is at: (" << xy[1][1] << "," << xy[1][2] << ")\n";
                std::cout << "The second is at: (" << xy[2][1] << "," << xy[2][2] << ")\n";
                std::cout << "---------------------------\n";

              }

            }
            else if(choice == 3)//used if the user is trying to find the dimensions of a room
            {

              double Area = 0.0;
              double Extra = 0.0;
              double minRequiredLength = 0.0;
              double length = 0.0;
              double width = 0.0;

              //takes in the user input for each required specification

              std::cout << "You have chosen a ballroom.\n";
              std::cout << "Please enter Area: ";
              std::cin >> Area;
              std::cout << "Please enter how much longer the width needs to be than the length: ";
              std::cin >> Extra;
              std::cout << "Please enter min required length: ";
              std::cin >> minRequiredLength;
              std::cout << "---------------------------\n";

              //uses these inputs by calling the room demensions class, and passes both width and length by refrence so they can be modified by the function

              n.roomDimensions(Area, Extra, minRequiredLength, width, length);


              std::cout << "Lenght of the ballroom: " << length << '\n';//prints the length of the result as modified by the function
              std::cout << "Width of the ballroom: " << width << '\n';//prints the width of the result as modified by the function
              std::cout << "---------------------------\n";

            }
            else if(choice == 4)//lets the user out of the for loop, and allows them to exit the program
            {
              std::cout << "Goodbye!\n";

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
              else if((choice > 4) || (choice <= 0))//checks that it is a valid numerical input
                {
                  std:: cout << "Invaid input, try again \n";
                  std::cout << '\n';
                }
            }

          }
          catch(NegativeDiscriminant& e)//catches a negitive descriminate error
          {
              //prints out an error meaningful to the context of the operation that failed

            std::cout << "This attempt failed to be solved becasue the discriminate produced from your equation was negitive, therefore the answer is imaginary.\n";
            std::cout << "---------------------------\n";
            //std::cout << e.what();
            std::cout <<'\n';
          }
          catch(NoIntersection& e) //catches a no intersection error
          {
            //prints out an error meaningful to the context of the operation that failed

            std::cout << "This attempt failed to be solved becasue there are is no place where your line intersects the unit circle.\n";
            std::cout << "---------------------------\n";

            //std::cout << e.what();
            std::cout <<'\n';
          }
          catch(CannotDetermineRoomDimensions& e)//catches a Cannot Determine Room dimensions exception
          {
            //prints out an error meaningful to the context of the operation that failed
            std::cout << "This attempt failed to be solved becasue your minimum length could not be satisfied.\n";
            std::cout << "---------------------------\n";

            //std::cout << e.what();
            std::cout <<'\n';
          }



      }

    }
