#pragma once
#include "State.h"
class Object
{
private:
	float size, speed;
	int sense; // jak daleko blob widzi
	int x, y;
	bool eaten;
	bool moved;
	float energy;
	state objectState;
	bool shouldMutate();
public:
	Object();
	Object(int, int, state);
	bool shouldReproduce();
	int calculateMovement();
	void mutate();
	state getState();
	int getX();
	int getY();
	int getSense();
	int getSize();
	int getSpeed();
};

