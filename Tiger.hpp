/***************************************************************
** Name: Theresa PHan
** Date: July 15, 2019
** Description: This is the header file for the tiger class.
***************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"
#include <iostream>

class Tiger : public Animal
{
    public:
        //Default constructor 
        Tiger();

        //Constructor that passes an int, double, int, double, and double
        Tiger(int, double, int, double, double);

        //Constructor that passes an int
        Tiger(int);

        //Method
        void toString();
};
#endif
