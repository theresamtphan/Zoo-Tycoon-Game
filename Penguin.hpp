/***************************************************************
** Name: Theresa PHan
** Date: July 15, 2019
** Description: This is the header file for the penguin class.
***************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"
#include <iostream>

class Penguin : public Animal
{
    public:
        //Default constructor 
        Penguin();

        //Constructor that passes an int, double, int, double, and double
        Penguin(int, double, int, double, double);

        //Constructor that passes an int
        Penguin(int);

        //Method
        void toString();
};
#endif