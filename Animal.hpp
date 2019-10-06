/*******************************************************************
** Name: Theresa Phan
** Date: July 13, 2019
** Description: This is the header file for the animal class. 
********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    private:
        int age;
        double cost;
        int numBabies;
        double baseFood;
        double payoff;

    public:
        //Default constructor
        Animal();
        //Constructor that passes an int, double, int, double, and double.
        Animal(int, double, int, double, double);

        // //Methods
        // void feed();
        // void addBabies();
        // void death();

        //Getters
        virtual int getAge();
        virtual double getCost();
        virtual int getNumBabies();
        virtual double getBaseFood();
        virtual double getPayoff();

        //Setters
        virtual void setAge(int);
        virtual void setCost(double);
        virtual void setNumBabies(int);
        virtual void setBaseFood(double);
        virtual void setPayoff(double);
};
#endif
