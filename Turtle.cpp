/************************************************************************
** Name: Theresa Phan
** Date: July 16, 2019
** Description: This file contains the definitions for the Turtle class.
************************************************************************/
#include "Turtle.hpp"
#include <iostream>

//Turtle constructor that uses a constructor from its parent class
Turtle::Turtle() : Animal(1, 100.00, 10, 5, 100.00 * 0.05){
}

//Turtle constructor that passes an int adult age and uses Animal constructor
Turtle::Turtle(int adultAge) : Animal(adultAge, 100.00, 10, 5, 100.00 * 0.05){
}

//prints out that the animal is a turtle and its age
void Turtle::toString(){
    std::cout << "TURTLE: Age: " << getAge() << "." << std::endl;
}