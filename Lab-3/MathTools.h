/* -----------------------------------------------------------------------------
 *
 * 	File Name: MathTools.h
	Author: Dylan Herrig
        KUID: 2837256
	Email Address: dylan.herrig@gmail.com
	Assignment Number: Lab 3
	Description: The MathTools.h file which will define the exec class, and give it its varibles and functions
	Last Changed: 9/22/16
 *
 ---------------------------------------------------------------------------- */
// MathTools.h - An interface for various mathematical tools

#ifndef MathTools_H
#define MathTools_H

#include "CannotDetermineRoomDimensions.h"
#include "NoIntersection.h"
#include "NegativeDiscriminant.h"

class MathTools
{
public:

//	double* iroots = 0;

	/** Compute the points of intersection between the line "dx + ey + f = 0" and
	 *  a unit circle at the origin.
	 *  @param d the coefficient on the x term
	 *  @param e the coefficient on the y term
	 *  @param f the constant term
	 *  @param xy an array of length [2][2] that will hold the one or two points of intersection
	 *  @throw NoIntersection if the line does not intersect the circle
	 *  @return the number of roots found (1 if the discriminant is zero; 2 otherwise)
	 */
int intersectLineUnitCircle(double d, double e, double f, double* xy[2])
			throw (NoIntersection);

	/** Compute the dimensions of a rectangular room such that the area of the room is "Area",
		and the width of the room is "Extra" larger than the length.
	 *  @param Area the desired area of the room
	 *  @param Extra the difference between the length and the width: width = length + Extra
	 *  @param minRequiredLength the minimum length that can be allowed
	 *  @param width the computed width
	 *  @param length the computed length
	 *  @throw CannotDetermineRoomDimensions if no possible room dimensions satisfy the constraints
	 */
void roomDimensions(double Area, double Extra, double minRequiredLength,
			double& width, double& length) throw (CannotDetermineRoomDimensions);

	/** Solve the quadratic equation "ax^2 + bx + c = 0" deterined by the given parameters.
	 *  @param a the coefficient on x^2
	 *  @param b the coefficient on the x term
	 *  @param c the constant term
	 *  @param roots an array of length 2 that will hold the one or two roots
	 *  @throw NegativeDiscriminant if the the discriminant is negative
	 *  @return the number of roots found (1 if the discriminant is zero; 2 otherwise)
	 */
int solveQuadratic(double a, double b, double c, double roots[])
			throw (NegativeDiscriminant);

//MathTools();
//~MathTools();


};

#endif
