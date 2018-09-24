#include <iostream>

enum WarHead { EXPLOSIVE, NUCLEAR };

struct Missile {

	WarHead payload;
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

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << y << std::endl;
	}

}Coordinates;


typedef struct Enemy {

	Coordinates coordinates;

}Target;