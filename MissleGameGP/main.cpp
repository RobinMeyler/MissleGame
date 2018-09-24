
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
	while (true)
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
		while (launchCode != 3278)											// Launch code, could be changed into a game like processes
		{	
			std::cout << "To Arm missle, enter code 3278" << std::endl;
			std::cin >> launchCode;
		}
		myMissle.arm();														// Arm the missile

		std::cout << "Shot Fired \nCurrently firing" << std::endl;
		while (myMissle.armed == true)										// If armed update
		{
			std::cout << ".";
			myMissle.update();
			if (myMissle.coordinates.x > myMissle.target.coordinates.x && myMissle.coordinates.y > myMissle.target.coordinates.y)
			{
				myMissle.arm();												// Reset missile if confirmed miss
				std::cout << "Missle has missed the target" << std::endl;
			}
			else if (myMissle.coordinates.x == myMissle.target.coordinates.x && myMissle.coordinates.y == myMissle.target.coordinates.y)
			{
				myMissle.arm();												// Or if you hit
				std::cout << "You have hit the target hurray" << std::endl;
			}
		}
	}

	return 0;
}
