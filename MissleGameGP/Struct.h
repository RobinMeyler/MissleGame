#pragma once

#include <iostream>

enum WarHead { EXPLOSIVE, NUCLEAR };

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

}Coordinates;

typedef struct Enemy {

	Coordinates coordinates;

}Target;

struct Missile {
	
	WarHead payload = EXPLOSIVE;
	Coordinates coordinates;
	Target target;
	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}
	void update()
	{
		coordinates.x += 1;
		coordinates.y += 2;
	}
};

