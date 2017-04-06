/* -----------------------------------------------------------------------------
 *
 * 	File Name: BuildingExecutive.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 4
	Description: The BuildingExecutive.h file which will define the BuildingExecutive class, and give it its varibles and functions
	Last Changed: 9/28/16
 *
 ---------------------------------------------------------------------------- */
#ifndef BUILDING_EXECUTIVE_H
#define BUILDING_EXECUTIVE_H

#include <string>
#include <fstream>
#include <iostream>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

class BuildingExecutive //creates BuildingExecutive class
{

  public:
    void run(std::string fileName);//defines the run function and is passed a file name


  private:
		Queue<std::string> line;//creates the line from the queue class
		Stack<std::string> elevator;//creates the elevator from the stack class


};

#endif
