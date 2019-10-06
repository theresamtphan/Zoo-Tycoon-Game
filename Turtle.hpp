/***************************************************************
** Name: Theresa PHan
** Date: July 15, 2019
** Description: This is the header file for the turtle class.
***************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"
#include <iostream>

class Turtle : public Animal
{
    public:
        //Default constructor
        Turtle();

        //Constructor that passes an int, double, int, double, and double
        Turtle(int, double, int, double, double);

        //Constructor that passes an int
        Turtle(int);

        //Method
        void toString();
};
#endif