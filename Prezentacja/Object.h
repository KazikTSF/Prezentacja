#pragma once
#include "State.h"
class Object
{
private:
	float size, speed;
	int sense; // jak daleko blob widzi
	int x, y;
	bool eaten;
	state objectState;
public:
	Object();
	Object(int, int, int); //x, y, state
	bool shouldReproduce();
	bool shouldMutate();
	int calculateMovement();
	state getState();
};

