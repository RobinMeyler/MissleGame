
// Name: Robin Meyler
// Student Num: C00231699
// Subject: Play Programming
// Project: Text Based Missile game

#include "Struct.h"
#include <iostream>
#include <ctime>

int main()
{
	srand(time(nullptr));													// Initialising
	Missile myMissle;
	myMissle.armed = false;
	myMissle.payload = EXPLOSIVE;
	myMissle.coordinates = { 0, 0 };
	myMissle.target = { 200, 200 };
	short selector = 0;
	short launchCode = 0;
	bool win = false;
	short launchInput = 0;
	short xMove = 0;
	short yMove = 0;

	while (win != true)
	{
		while (selector < 1 || selector > 2)								// Picking the bomb type
		{
			std::cout << "Which type of missle do you want to fire? \n1: Explosive 2: Nuclear" << std::endl;
			std::cin >> selector;
		}
		if (selector == 1)
		{
			myMissle.payload = EXPLOSIVE;
		}
		else if (selector == 2)
		{
			myMissle.payload = NUCLEAR;
		}
		selector = 0;														// Reset it
		myMissle.target = { rand() % 800, rand() % 800};					// Random position
		std::cout << "Enemy Target is located here" << std::endl;
		myMissle.target.coordinates.print();
		std::cout << std::endl;

		std::cout << "Your Coords are: X: " << xMove << " Y: " << yMove << std::endl;
		std::cout << "Would you like to move your tank?" << std::endl;
		std::cout << "How much would you like to move on the X axis?  (-100 -> 100)\n ::Larger values will be taken as 0::" << std::endl;
		std::cin >> xMove;
		std::cout << "How much would you like to move on the Y axis< (-100 -> 100)\n ::Larger values will be taken as 0::" << std::endl;
		std::cin >> yMove;
		if (xMove > -101 && xMove < 101)
		{
			myMissle.coordinates.x = myMissle.coordinates.x + xMove;				// Change the position of the tank if the values are correct
		}
		if (xMove > -101 && xMove < 101)
		{
			myMissle.coordinates.y = myMissle.coordinates.x + yMove;
		}
		std::cout << "New Coords are: X: " << xMove << " Y: " << yMove << std::endl;
	
		launchCode = rand() % 8000 + 1000;
		while (launchInput != launchCode)											// Launch code, could be changed into a game like processes
		{	
			std::cout << "To Arm missle, enter code " << launchCode << std::endl;
			std::cin >> launchInput;
		}
		myMissle.arm();														// Arm the missile
		launchInput = 0;														// Reset it

		std::cout << "Shot Fired \nCurrently firing" << std::endl;
		while (myMissle.armed == true)										// If armed update
		{
			std::cout << ".";
			myMissle.update();
			if (myMissle.coordinates.x > myMissle.target.coordinates.x && myMissle.coordinates.y > myMissle.target.coordinates.y)
			{
				myMissle.arm();												// Reset missile if confirmed miss
				std::cout << std::endl;
				std::cout << "Missle has missed the target" << std::endl;
			}
			else if (myMissle.coordinates.x == myMissle.target.coordinates.x && myMissle.coordinates.y == myMissle.target.coordinates.y)
			{
				myMissle.arm();												// Or if you hit
				std::cout << std::endl;
				std::cout << "You have hit the target hurray" << std::endl;
				win = false;
			}
		}
	}
	std::cout << "You have won, Game Over" << std::endl;
	system("PAUSE");
	return 0;
}
