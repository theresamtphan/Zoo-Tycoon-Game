/**********************************************************************
** Name: Theresa PHan
** Date: July 12, 2019
** Description: This file contains the definitions for the Zoo class.
************************************************************************/
#include "Zoo.hpp"
#include <iostream>
#include <stdlib.h>

/*********************************************************************
* This function dynamically allocates an array for each type of animal.  
* The size of the dynamic array is initialized to a base of 10. 
* In addition, the initial money is initialized to $100000, profit to 0, 
* and each animal count to zero. 
************************************************************************/
Zoo::Zoo()
{
    //Tigers 
    tigerCapacity = 10;
    tigerArray = new Tiger[tigerCapacity];

    //Penguins
    penguinCapacity = 10;
    penguinArray = new Penguin[penguinCapacity];

    //Turtles
    turtleCapacity = 10;
    turtleArray = new Turtle[turtleCapacity];
    
    money = 100000.00;
    tigerNum = 0;
    penguinNum = 0;
    turtleNum = 0;
    // Animal *arr = new Animal[10];
}

/***************************************************
This function increments the age of the animals. 
****************************************************/
void Zoo::incrementAge()
{   
    //Increment the age of tigers.
    for(int i = 0; i < tigerNum; i++){
        tigerArray[i].setAge(tigerArray[i].getAge() + 1);
        //animalArr[i].setAge(animal.Arr[i].getAge() + 1)
    }

    //Increment the age of penguins
    for(int i = 0; i < penguinNum; i++){
        penguinArray[i].setAge(penguinArray[i].getAge() + 1);
    }

    //Increment the age of turtles.
    for(int i = 0; i < turtleNum; i++){
        turtleArray[i].setAge(turtleArray[i].getAge() + 1);
    }
}

/********************************************************
* This function will generate a random event.
* 1. A sickness occurs to an animal in the zoo.
* 2. A boom in zoo attendance occurs.
* 3. A baby animal is born
* 4. Nothing happens. 
*********************************************************/
void Zoo::randomEvent()
{
    // This will generate a random number in the range 1 to 4.
    //Reference: http://www.cplusplus.com/reference/cstdlib/rand/
    int randomEvent = rand() % 4 + 1;

    std::cout << "Random Event: ";

    switch(randomEvent){
    case 1:{
        int randNum = rand() % 3 + 1; 

        std::cout << "Oh no! A deadly infectious disease is spreading!" << std::endl;

        //Tigers
        if(randNum == 1){
            //No tigers to remove.
            if(tigerNum == 0){
                std::cout << "No tigers were affected because there are none left." << std::endl;
            }
            else{
                std::cout << "Uh-oh! One of the tigers was infected with canine distemper virus (CDV)!\n" << std::endl;
                std::cout << "A tiger has died." << std::endl;
                removeTiger();
            }
        }
        //Penguins 
        if(randNum == 2){
            //No penguins to remove.
            if(penguinNum == 0){
                std::cout << "No penguins were affected because there are none left." << std::endl;
            }
            else{
                std::cout << "Uh-oh! One of the penguins was infected with Newcastle disease virus (NDV)!\n" << std::endl;
                std::cout << "A penguin has died." << std::endl;
                removePenguin();
            }
        }
        //Turtles
        if(randNum == 3){
            //No turtles to remove.
            if(turtleNum == 0){
                std::cout << "No penguins were affected because there are none left." << std::endl;
            }
            else{
                std::cout << "Uh-oh! One of the turtles got pneumonia!" << std::endl;
                std::cout << "A turtle has died.\n" << std::endl;
                removeTurtle();
            }
        }
        break;
    }
    
    case 2: {
        std::cout << "Congratulations! A boom in zoo attendance has occured!" << std::endl;
        if(tigerNum > 0){
            int tigerBonus = rand() % 251 + 250;
            std::cout << "You will receive a bonus of $" << tigerBonus << " for each tiger you currently have in your zoo.\n" << std::endl;
            money += tigerNum * tigerBonus;
        }
        break;
    }

    case 3: {
        //Babies are born
        //Checking prerequesites for which animals are capable of giving birth
        //capabilityNumber will represent the combinations of whether the animal can give birth or not
        //0 = No animals are capable
        //1 = Only tiger
        //3 = Only penguin
        //5 = Only turtle
        //4 tiger and penguin
        //6 = tiger and turtle
        //8 = penguin and turtle
        //9 = all 3 animals
        int capabilityNumber = 0;
        for(int i = 0; i < tigerNum; i++){
            if(tigerArray[i].getAge() > 2){
                capabilityNumber += 1;
                break;
            }
        }
        for(int i = 0; i < penguinNum; i++){
            if(penguinArray[i].getAge() > 2){
                capabilityNumber += 3;
                break;
            }
        }
        for(int i = 0; i < turtleNum; i++){
            if(turtleArray[i].getAge() > 2){
                capabilityNumber += 5;
                break;
            }
        }

        //randBaby will end up being a number 1-3, based on the animals eligible to have babies (capabilityNumber)
        int randBaby;

        switch(capabilityNumber){
            case 0:{
                randBaby = 0;
                break;
            }
            case 1:{
                randBaby = 1;
                break;
            }
            case 3:{
                randBaby = 2;
                break;
            }
            case 5:{
                randBaby = 3;
                break;
            }
            case 4:{
                randBaby = rand() %2 + 1;
                break;
            }
            case 6:{
                randBaby = rand() %2 + 1;
                if(randBaby == 2){
                    randBaby = 3;
                }
                break;
            }
            case 8:{
                randBaby = rand() %2 + 2;
                break;
            }
            case 9:{
                randBaby = rand() %3 + 1;
            }
        }
        switch(randBaby){
            case 0:{
                std::cout << "No animals are eligible to be born" << std::endl;
                break;
            }
            case 1:{
                //Tigers are born
                std::cout << "Tiger is born\n" << std::endl;
                if(tigerNum + 1 >= tigerCapacity){
                    doubleTigerArray();
                }
                addTiger(0);
                break;
            }
            case 2:{
                //Penguins are born
                std::cout << "Penguins are born\n" << std::endl;
                if(penguinNum + 5 >= penguinCapacity){
                    doublePenguinArray();
                }
                for(int i = 0; i < 5; i++){
                    addPenguin(0);
                }
                break;
            }
            case 3:{
                //Turtles are born
                std::cout << "Turtles are born\n" << std::endl;
                if(turtleNum + 10 >= turtleCapacity){
                    doubleTurtleArray();
                }
                for(int i = 0; i < 10; i++){
                    addTurtle(0);
                }
                break;
            }
        }
        break;
    }
    case 4: {
        std::cout << "Nothing happens.\n" << std::endl;
        break;
    }
    std::cout << std::endl;
    }
}


/*************************************************
* This function removes a tiger due to sickness.
**************************************************/
void Zoo::removeTiger()
{
    Tiger *newArray = new Tiger[tigerCapacity];
    for(int i = 0; i < (tigerNum-1); i++){
        newArray[i] = tigerArray[i];
    }
    tigerNum -= 1;
    delete[] tigerArray;
    tigerArray = newArray;
}

/*****************************************************
* This function removes penguins due to sickness.
*******************************************************/
void Zoo::removePenguin()
{
    Penguin *newArray = new Penguin[penguinCapacity];
    for(int i = 0; i < (penguinNum-1); i++){
        newArray[i] = penguinArray[i];
    }
    penguinNum -= 1;
    delete[] penguinArray;
    penguinArray = newArray;
}

/***************************************************
* This function removes turtles due to sickness.
****************************************************/
void Zoo::removeTurtle()
{
    Turtle *newArray = new Turtle[turtleCapacity];
    for(int i = 0; i < (turtleNum-1); i++){
        newArray[i] = turtleArray[i];
    }
    turtleNum -= 1;
    delete[] turtleArray;
    turtleArray = newArray;
}

/*****************************************************
* This function adds baby tigers for a random event.
******************************************************/
void Zoo::addTiger(int age)
{
    tigerArray[tigerNum] = Tiger(age);
    tigerNum += 1;
}
/*****************************************************
* This function adds baby penguins for a random event.
******************************************************/
void Zoo::addPenguin(int age)
{
    penguinArray[penguinNum] = Penguin(age);
    penguinNum += 1;
}
/*****************************************************
* This function adds baby turtles for a random event.
******************************************************/
void Zoo::addTurtle(int age)
{
    turtleArray[turtleNum] = Turtle(age);
    turtleNum += 1;
}

/****************************************************************************
*This function doubles the capacity of the dynamic Tiger array if needed
*before the baby is born
*****************************************************************************/
void Zoo::doubleTigerArray(){

    //Reference: http://www.cplusplus.com/forum/general/11111/ and from the CS1 assignment transformArray.cpp
    //Creates new dynamic array of double size
    Tiger *newArray = new Tiger[tigerCapacity * 2];

    //Populate new array with values of the pass-in array, followed by those 
    //values doubled.
    for(int i = 0; i < (tigerCapacity / 2); i++){
        newArray[i] = tigerArray[i];
    }

    //Free up the passed-in pointer reference, and set it to our new dynamic array.
    delete []tigerArray;
    tigerArray = newArray;

    tigerCapacity = tigerCapacity * 2;
}

/****************************************************************************
*This function doubles the capacity of the dynamic Penguin array if needed
*before the babies are born
*****************************************************************************/
void Zoo::doublePenguinArray(){

    //Reference: http://www.cplusplus.com/forum/general/11111/ and from the CS1 assignment transformArray.cpp
    //Creates new dynamic array of double size
    Penguin *newArray = new Penguin[penguinCapacity * 2];

    //Populate new array with values of the pass-in array, followed by those 
    //values doubled.
    for(int i = 0; i < (penguinCapacity / 2); i++){
        newArray[i] = penguinArray[i];
    }

    //Free up the passed-in pointer reference, and set it to our new dynamic array.
    delete []penguinArray;
    penguinArray = newArray;

    penguinCapacity = penguinCapacity * 2;
}

/****************************************************************************
*This function doubles the capacity of the dynamic Turtle array if needed
*before the babies are born
*****************************************************************************/
void Zoo::doubleTurtleArray(){

    //Reference: http://www.cplusplus.com/forum/general/11111/ and from the CS1 assignment transformArray.cpp
    //Creates new dynamic array of double size
    Turtle *newArray = new Turtle[turtleCapacity * 2];

    //Populate new array with values of the pass-in array, followed by those 
    //values doubled.
    for(int i = 0; i < turtleCapacity; i++){
        newArray[i] = turtleArray[i];
    }
    //Free up the passed-in pointer reference, and set it to our new dynamic array.
    delete []turtleArray;
    turtleArray = newArray;

    turtleCapacity = turtleCapacity * 2;
}

/****************************************************************************
*This function returns the number of Tigers the zoo currently has
*****************************************************************************/
int Zoo::getTigerNum(){
    return tigerNum;
}

/****************************************************************************
*This function returns the number of Penguins the zoo currently has
*****************************************************************************/
int Zoo::getPenguinNum(){
    return penguinNum;
}

/****************************************************************************
*This function returns the number of Turtles the zoo currently has
*****************************************************************************/
int Zoo::getTurtleNum(){
    return turtleNum;
}

/****************************************************************************
*This function returns the amount of money in the bank
*****************************************************************************/
int Zoo::getMoney(){
    return money;
}

/****************************************************************************
*This function subtracts money from the bank
*****************************************************************************/
void Zoo::subtractMoney(int moneySubtracted){
    money -= moneySubtracted;
}

/****************************************************************************
*This function adds money to the bank
*****************************************************************************/
void Zoo::addMoney(int moneyAdded){
    money += moneyAdded;
}

/****************************************************************************
*This function calculates the total amount of money needed to feed the zoo
*and subtracts it from the bank
*****************************************************************************/
void Zoo::feedZoo(){
    int total = 0;
    for(int i = 0; i < (tigerNum); i++){
        total += tigerArray[i].getBaseFood();
    }
    for(int i = 0; i < (penguinNum); i++){
        total += penguinArray[i].getBaseFood();
    }
    for(int i = 0; i < (turtleNum); i++){
        total += turtleArray[i].getBaseFood();
    }
    std::cout << "\nFeeding your animals costed $" << total << " today\n" << std::endl;
    money -= total;
}

/****************************************************************************
*This function calculates the total payoff of the animals in the zoo and 
*adds it to the bank
*****************************************************************************/
void Zoo::addPayoff(){
    int total = 0;
    for(int i = 0; i < (tigerNum); i++){
        total += tigerArray[i].getPayoff();
    }
    for(int i = 0; i < (penguinNum); i++){
        total += penguinArray[i].getPayoff();
    }
    for(int i = 0; i < (turtleNum); i++){
        total += turtleArray[i].getPayoff();
    }
    std::cout << "You made $" << total << " off of your animals today!" << std::endl;
    money += total;
}

/****************************************************************************
*This function prints out all of the animals in the zoo with their age
*****************************************************************************/
void Zoo::printAllAnimals(){
    for(int i = 0; i < (tigerNum); i++){
        tigerArray[i].toString();
    }
    for(int i = 0; i < (penguinNum); i++){
        penguinArray[i].toString();
    }
    for(int i = 0; i < (turtleNum); i++){
        turtleArray[i].toString();
    }
}