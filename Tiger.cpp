/************************************************************************
** Name: Theresa Phan
** Date: July 16, 2019
** Description: This file contains the definitions for the Tiger class.
************************************************************************/
#include "Tiger.hpp"
#include <iostream>

//Tiger constructor that uses a constructor from its parent class
Tiger::Tiger() : Animal(1, 10000.00, 1, 50, 10000.00 * 0.2){
}

//Tiger constructor that passes an int adult age and uses Animal constructor
Tiger::Tiger(int adultAge) : Animal(adultAge, 10000.00, 1, 50, 10000.00 * 0.2){
}

//Prints out that the animal is a tiger and its age
void Tiger::toString(){
    std::cout << "TIGER: Age: " << getAge() << "." << std::endl;
}