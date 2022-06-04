#include "Object.h"
#include <time.h>
#include <stdlib.h>
#include "Simulation.h"

Object::Object()
{
	throw "Object needs parameters";
}

Object::Object(int x, int y, int s)
{
	Object::eaten = 1;
	Object::size = 1;
	Object::speed = 1;
	Object::sense = 1;
	Object::x = x;
	Object::y = y;
	switch (s)
	{
	case 0:
		Object::objectState = empty;
		break;
	case 1:
		Object::objectState = food;
		break;
	case 2:
		Object::objectState = blob;
		break;
	default:
		throw "Illegal Argument in object state";
	}
}

bool Object::shouldReproduce()
{
	if(!Object::eaten)
		return false;
}

bool Object::shouldMutate()
{
	if (objectState != blob)
		return false;
	srand(time(NULL));
	int r = rand() % 100 + 1;
	if (r < 5)
		return true;
	return false;
}

int Object::calculateMovement()
{
	return 0;
}

state Object::getState()
{
	return Object::objectState;
}
