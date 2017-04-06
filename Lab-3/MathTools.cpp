/* -----------------------------------------------------------------------------
 *
 * 	File Name: MathTools.cpp
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 3
	Description: The MathTools.cpp file which will
	Last Changed: 9/22/16
 *
 ---------------------------------------------------------------------------- */
#include "MathTools.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"
#include "NegativeDiscriminant.h"
#include <iostream>
#include <string>
#include <cmath>

//MathTools :: MathTools()
//{
//  double* iroots = new double[2];

//}

//MathTools :: ~MathTools()
//{
//  delete[] iroots;

//}


int MathTools :: intersectLineUnitCircle(double d, double e, double f, double* xy[2])throw (NoIntersection)
{

  //instanciates new varibles to be used in this function
  double* iroots = new double[2];//makes an array that will be used to pass values between the functions
  double a = 0.0;
  double b = 0.0;
  double c = 0.0;
  int numRoot1 = 0;
  double x1 = 0.0;
  double x2 = 0.0;
  double y1 = 0.0;
  double y2 = 0.0;

  //solves for the values a, b and c that will be used in the quadratic equation

  a = ((d*d)+(e*e));
  b = (2*e*f);
  c = ((f*f)-(d*d));

  try//trys the quadratic function and proceeds if it works otherwise it throws an exception
  {


    numRoot1 = solveQuadratic(a, b, c, iroots);//calls to hte solveQuadratic function


     if(numRoot1 == 1)//if there is one root
       {
         //set the y values to those given by the quadratic solver
         y1 = iroots[1];
         y2 = iroots[1];

         if( ((-(y1*y1))+1) < 0)//solves the proble of taking the sqrt of a negative number
         {
           delete[] iroots;//delets the array if an exception must be thrown
           throw NoIntersection("No Intersection!\n");
         }
         if( ((-(y2*y2))+1) < 0)//solves the proble of taking the sqrt of a negative number
         {
           delete[] iroots;//delets the array if an exception must be thrown
           throw NoIntersection("No Intersection!\n");
         }

         //calculate the x values
         x1 = sqrt((-(y1*y1))+1);
         x2 = sqrt((-(y2*y2))+1);


         if (((d*y1)+(e*(x1))+f) != 0)// if the x value does not solve the original equation then reverse it becasue it must be + or -
         {
           x1 = x1*(-1);
         }


         if (((d*y2)+(e*(x2))+f) != 0)// if the x value does not solve the original equation then reverse it becasue it must be + or -
         {
           x2 = x2*(-1);
         }

         //std::cout << x1<<'\n';--was used to check that values were working correctly
         //std::cout << x2<<'\n';--was used to check that values were working correctly

         //Set the array values to the calculated x and y values
         xy[1][2] = y1;
         xy[2][2] = y2;
         xy[1][1] = x1;
         xy[2][1] = x2;

         //delete the temp array then return that there is one intersection
         delete[] iroots;
         return(1);

       }
      else if(numRoot1 == 2)// if there are two roots
       {

         //set the y values to those given by the quadratic solver
         y1 = iroots[1];
         y2 = iroots[2];

         if( ((-(y1*y1))+1) < 0)//solves the proble of taking the sqrt of a negative number
         {
           delete[] iroots;//delets the array if an exception must be thrown
           throw NoIntersection("No Intersection!\n");
         }
         if( ((-(y2*y2))+1) < 0)//solves the proble of taking the sqrt of a negative number
         {
           delete[] iroots;//delets the array if an exception must be thrown
           throw NoIntersection("No Intersection!\n");
         }

         //calculate the x values
         x1 = sqrt((-((y1)*(y1)))+1);
         x2 = sqrt((-((y2)*(y2)))+1);

         //std::cout << ((d*(y1))+(e*(x1))+f) << '\n';--was used to check that values were working correctly

         if (((d*(y1))+(e*(x1))+f) != 0)// if the x value does not solve the original equation then reverse it becasue it must be + or -
         {
           x1 = x1*(-1);
         }

         //std::cout << ((d*(y2))+(e*(x2))+f) << '\n';--was used to check that values were working correctly

         if (((d*(y2))+(e*(x2))+f) != 0)// if the x value does not solve the original equation then reverse it becasue it must be + or -
         {
           x2 = x2*(-1);
         }

         //Set the array values to the calculated x and y values
         xy[1][2] = y1;
         xy[2][2] = y2;
         xy[1][1] = x1;
         xy[2][1] = x2;

         //delete the tempoary array then return that there are two roots
         delete[] iroots;
         return (2);



       }

  }
  catch(NegativeDiscriminant e)//catch if the quadratic can not be solves
  {
    delete[] iroots;//delets the array if an exception must be thrown
    throw NoIntersection("No Intersection!\n");//throw that there is no intersection as a result of the quadratice not being solvable

  }

    return(0);

}


void MathTools :: roomDimensions(double Area, double Extra, double minRequiredLength, double& width, double& length)  throw (CannotDetermineRoomDimensions)
{
  //instanciate the variables that will be used
  double* jroots = new double[2];
  double l = 0.0;
  bool check = true;
  int numRoot2 = 0;
  double num = 1;
  double negArea = (-1)*Area;

  //std::cout << Area;--was used to check that values were working correctly


  try//try and use the solvequadratic function
  {
   numRoot2 = solveQuadratic(num, Extra, negArea, jroots);



    double one = jroots[1];

    double two = jroots[2];

    //this if else statement will set the larger of the two solutions of the quadratic function to the varible l
   if (numRoot2 == 1)
   {
      l = one;
   }
   else if (numRoot2 == 2)
   {
      if(one < two)
      {
        l = two;
      }
      else
      {
        l = one;
      }
   }

   delete[] jroots;//delete the tempoary jroots array

  }
  catch(NegativeDiscriminant e)//if the quadratic function can not be solved then you will set the check to false
  {
    check = false;
  }

  if ((l< minRequiredLength) || check == false)// if the minlength required is less then the calculated length, or quadratic function threw a error then this occurs
  {
    delete[] jroots;//delets the array if an exception must be thrown
    throw CannotDetermineRoomDimensions("Cannot Determine Room Dimensions!\n");//throws an exception that the room demensions cannot be determined
  }

  //set the length that was passed by refrence to l
  length = l;
  //set the width to the length plus the extra
  width = length + Extra;

}


int MathTools :: solveQuadratic(double a, double b, double c, double roots[]) throw (NegativeDiscriminant)
{
  //instanciates vatibles
  double root1 = 0.0;
  double root2 =0.0;


  double disc = (b*b)-(4*a*c);//solves for the discriminate

  root1 = (-b + sqrt(disc))/(2*a);//sets the first root to be one solution of the quadratic equation

  root2 = (-b - sqrt(disc))/(2*a);//sets the first root to be the other solution of the quadratic equation

  if (disc > 0)//if the disctiminate is greater than 0 then there will be two unique roots
    {
        //sets the parts of the passed array to the calculated root values
        roots[1] = root1;
        roots[2] = root2;

        return (2);//return that there are two roots

    }
  else if(disc == 0)//if the discriminate is equal to zero then there will only be one root
    {
      // set the two equalvant roots to the calculated results. place them in the array
      roots[1] = root1;
      roots[2] = root2;

      return(1);//return that there is one root

    }

  else//if the Discriminate is negitive then throw a negitive Discriminate error
    {
     throw NegativeDiscriminant("Negitive Discriminate!\n");
    }


}
