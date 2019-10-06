/*************************************************************************
** Name: Theresa Phan
** Date: July 16, 2019
** Description: This file contains the definitions for the Penguin class.
*************************************************************************/
#include "Penguin.hpp"
#include <iostream>

//Penguin constructor that uses a constructor from its parent class
Penguin::Penguin() : Animal(1, 1000.00, 5, 10, 1000.00 * 0.1){
}

//Penguin constructor that passes an int adult age and uses Animal constructor
Penguin::Penguin(int adultAge) : Animal(adultAge, 1000.00, 5, 10, 1000.00 * 0.1){
}

//Prints out that the animal is a penguin and its age
void Penguin::toString(){
    std::cout << "PENGUIN: Age: " << getAge() << "." << std::endl;
}