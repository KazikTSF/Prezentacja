#include "Obiekt.h"
#include <time.h>
#include <stdlib.h>

bool Obiekt::shouldReproduce()
{
	if(!Obiekt::eaten)
		return false;

}

bool Obiekt::shouldMutate()
{
	srand(time(NULL));
	int r = rand() % 100 + 1;
	if (r < 5)
		return true;
	return false;
}

int Obiekt::calculateMovement()
{
	return 0;
}
