#include "Symulacja.h"
#include <time.h>
#include <stdlib.h>

Symulacja::Symulacja(int foodAmount, int blobAmount) : 
	foodAmount(foodAmount), blobAmount(blobAmount) 
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			Symulacja::board[i][j] = empty;
	placeBlobs();
}

void Symulacja::start()
{

}

void Symulacja::placeBlobs()
{
	srand(time(NULL));
}

void Symulacja::placeFood()
{
	srand(time(NULL));
}
