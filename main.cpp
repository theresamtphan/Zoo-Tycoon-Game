/**********************************************************************
** Name: Theresa Phan
** Date: July 13, 2019
** Description: This program runs the Zoo Tycoon simulation.
** The player begins the game with a certain amount of money in the bank.
** They have the option to buy animals (tigers, penguins, or turtles)
** and must pay the related upkeep costs for their animals such as 
** food and random events (sickness, boom in zoo attendance, and baby
** animal is born). Players have the opportunity to keep playing until
** they run out of money or if they wish to stop playing.
**********************************************************************/
#include <iostream> 
#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <sstream>
#include <stdlib.h>

/**********************************************************************************
* Validate Menu input
* Cited Source: http://www.cplusplus.com/forum/beginner/58833/
*Edited to fit program needs. Reprompts if user enters anything besides 1 or 2
***********************************************************************************/
int validateMenuInput(std::string prompt)
{
	int ret_integer;
	std::string str_number;

	while(true) {

		std::cout << prompt;
        std::cin >> str_number;
		std::stringstream convert(str_number); //turns the string into a stream

		//checks for complete conversion to integer, then returns 1 or 2
		if(convert >> ret_integer && !(convert >> str_number)){
            if(ret_integer == 1){
                return 1;
            }else if(ret_integer == 2){
                return 2;
            }
        }
        std::cout << "Invalid input. Please try again.\n";
		std::cin.clear(); //just in case an error occurs with cin (eof(), etc)
	}
}

/**********************************************************************************
* Validate Animal buying choice (1 to 3)
* Cited Source: http://www.cplusplus.com/forum/beginner/58833/
* Edited to fit program needs. Reprompts if user enters anything besides 1 or 2
***********************************************************************************/
int validateAnimalBuyingChoice(std::string prompt)
{
	int ret_integer;
	std::string str_number;

	while(true) {

		std::cout << prompt;
        std::cin >> str_number;
		std::stringstream convert(str_number); //turns the string into a stream

		//checks for complete conversion to integer, then returns 1 or 2
		if(convert >> ret_integer && !(convert >> str_number)){
            if(ret_integer == 1){
                return 1;
            }else if(ret_integer == 2){
                return 2;
            }else if(ret_integer == 3){
                return 3;
            }
        }
        std::cout << "Invalid input. Please try again.\n";
		std::cin.clear(); //just in case an error occurs with cin (eof(), etc)
	}
}
/**********************************************************************************
* Validate input for type of die
* Cited Source: http://www.cplusplus.com/forum/beginner/58833/
* Edited to fit program needs. Reprompts if user enters anything besides 'n' or 'l'
***********************************************************************************/
char validateYesNo(std::string prompt){
    while(true){

        char input;
        std::string strInput;

        std::cout << prompt;
        std::cin >> strInput;
        std::stringstream convert(strInput); //turns the input into a stream

        //checks for complete conversion to char, then goes to switch statement
        if(!(convert >> input)){
            std::cout << "Invalid Input. Please try again.\n";
        }else{
            switch(tolower(input)){
                case 'y': return 'y';
                                break;
                case 'n': return 'n';
                                break;
                default:{
                    std::cout << "Invalid Input. Please try again.\n";
                }
            }
        }
    }
}

int main(){

    bool selectionFlag = true;

    //Introduction to the game.
    std::cout << "**** Introduction ****\n" << std::endl;
    std::cout << "Welcome to Zoo Tycoon!" << std::endl;
    std::cout << "In this game, you will be playing as an entrepreneur who recently bought a failing zoo from the previous owner." << std::endl;
    std::cout << "You will be given a lump sum of $100,000 to start over and turn this zoo into a profit-making business." << std::endl;
    std::cout << "Are you up for the challenge?\n" << std::endl;

    //Initializing zoo object
    Zoo zoo;

    while(selectionFlag){
        //Prompts user to start or exit game. 
        int selection = validateMenuInput("\nEnter the number 1 or 2 for your selection.\n1: Play Game \n2: Exit Game\n");

        if(selection == 1){
            std::cout << "\nToday is the start of a brand new day." << std::endl;
            std::cout << "What is a zoo without animals?" << std::endl;
            std::cout << "Let's buy animals for your zoo" << std::endl;

            //Player buys tiger(s).
            int tigerChoice = validateMenuInput("\nEnter a number of tigers to buy (1 or 2): ");

            for(int i = 0; i < tigerChoice; i++){
                //Statements to add tigers and subtract the cost from the bank
                zoo.addTiger(1);
                zoo.subtractMoney(10000);
            }

            //Player buys penguin(s)
            int penguinChoice = validateMenuInput("Enter a number of penguins to buy (1 or 2): ");

            for(int i = 0; i < penguinChoice; i++){
                //Statments to add penguins and subtract the cost from the bank
                zoo.addPenguin(1);
                zoo.subtractMoney(1000);
            }

            //Player buys 
            int turtleChoice = validateMenuInput("Enter a number of turtles to buy (1 or 2): ");

            for(int i = 0; i < turtleChoice; i++){
                //Statments to add turtles and subtract the cost from the bank
                zoo.addTurtle(1);
                zoo.subtractMoney(100);
            }

            std::cout << "Lets start the game!\n" << std::endl;
            //Do while loop loops through the "day" at least once before user can quit
            do{
                //Increments the age of all the animals
                zoo.incrementAge();

                //Subtracts food cost from all animals from bank for "feeding"
                zoo.feedZoo();

                //Random event
                zoo.randomEvent(); 

                //Payoff from all of the animals
                zoo.addPayoff();

                //Prints out all the animals in the zoo with their age
                zoo.printAllAnimals();

                //Shows user how much money they have at the end of the day
                std::cout << "\nMoney at the end of the day: $" << zoo.getMoney() << std::endl;

                //Asks the user if an animal would like to be purchased
                char purchaseChoice = validateYesNo("\nWould you like to purchase an adult animal now? 'y' for yes. 'n' for no: \n");
                if(purchaseChoice == 'y'){
                    //Prompts user to pick type of animal to buy
                    int animalChoice = validateAnimalBuyingChoice("\nEnter 1 for a tiger ($10000), 2 for a penguin ($1000), or 3 for a turtle ($100): ");
                    //Switch statement for the type of animal user chose to buy. Updates the user what the bank total is
                    switch(animalChoice){
                        case 1:{
                            std::cout << "You bought a tiger. Your bank total is now: $" << (zoo.getMoney() - 10000) << std::endl;
                            zoo.subtractMoney(10000);
                            zoo.addTiger(3);
                            break;
                        }
                        case 2:{
                            std::cout << "You bought a penguin. Your bank total is now: $" << (zoo.getMoney() - 1000) << std::endl;
                            zoo.subtractMoney(1000);
                            zoo.addPenguin(3);
                            break;
                        }
                        case 3:{
                            std::cout << "You bought a turtle. Your bank total is now: $" << (zoo.getMoney() - 100) << std::endl;
                            zoo.subtractMoney(100);
                            zoo.addTurtle(3);
                            break;
                        }
                    }
                }

                //Continue game prompt
                char continueGame = validateYesNo("\nWould you like to continue the game? ('y' or 'n'): \n");
                if(continueGame == 'n'){
                    selectionFlag = false;
                    std::cout << "Quitting Game..." << std::endl;
                }

            }while(selectionFlag == true);

        //Quits the game if user manually quits or bank reaches 0
        }else if(selection == 2 || zoo.getMoney() <= 0){
            if(selection == 2){
                std::cout << "\nQuitting Game..." << std::endl;
            }else if(zoo.getMoney() <= 0){
                std::cout << "You've run out of money! Game over" << std::endl;
            }
            selectionFlag = false;
        }
    }
}