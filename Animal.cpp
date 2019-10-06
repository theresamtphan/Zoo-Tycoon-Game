/*******************************************************************************
** Name: Theresa PHan
** Date: July 13, 2019
** Description: This file contains the method definitions for the Animal class.
*******************************************************************************/

#include "Animal.hpp"
#include <iostream>

//Default constructor 
//Initialize variables to zero. 
Animal::Animal(){
    age = 0;
    cost = 0;
    numBabies = 0;
    baseFood = 0;
    payoff = 0;
}

//Constructor that takes in 5 parameters to initialize the objects.
Animal::Animal(int newAge, double newCost, int newNumBabies, double newBaseFood, double newPayoff){
    age = newAge;
    cost = newCost;
    numBabies = newNumBabies;
    baseFood = newBaseFood;
    payoff = newPayoff;
}

//Getter methods for each data member
//return age of animal
int Animal::getAge(){
    return age;
}

//return cost of animal
double Animal::getCost(){
    return cost;
}

//return number of babies of animal
int Animal::getNumBabies(){
    return numBabies;
}

//return base food cost of animal 
double Animal::getBaseFood(){
    return baseFood;
}

//return payoff
double Animal::getPayoff(){
    return payoff;
}

//Setter methods for each data member
void Animal::setAge(int newAge){
    age = newAge;
}

void Animal::setCost(double newCost){
    cost = newCost;
}

void Animal::setNumBabies(int newNumBabies){
    numBabies = newNumBabies;
}

void Animal::setBaseFood(double newBaseFood){
    baseFood = newBaseFood;
}

void Animal::setPayoff(double newPayoff){
    payoff = newPayoff;
}