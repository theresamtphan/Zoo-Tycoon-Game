/*******************************************************************
** Name: Theresa Phan
** Date: July 13, 2019
** Description: This is the header file for the Zoo class. 
********************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

class Zoo
{
    private:
        int tigerCapacity;
        int penguinCapacity;
        int turtleCapacity;
        Tiger *tigerArray;
        Penguin *penguinArray;
        Turtle *turtleArray;
        double money;
        int tigerNum;
        int penguinNum;
        int turtleNum;
    
    public:
        //Default Zoo constructor
        Zoo();

        //Methods
        void incrementAge();
        void randomEvent();
        void removeTiger();
        void removePenguin();
        void removeTurtle();
        void addTiger(int);
        void addPenguin(int);
        void addTurtle(int);
        void doubleTigerArray();
        void doublePenguinArray();
        void doubleTurtleArray();

        //Getters
        int getTigerNum();
        int getPenguinNum();
        int getTurtleNum();
        int getMoney();

        //Methods
        void subtractMoney(int);
        void addMoney(int);

        void feedZoo();
        void addPayoff();

        void printAllAnimals();
};
#endif