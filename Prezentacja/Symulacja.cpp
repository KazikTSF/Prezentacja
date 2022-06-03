#include "Symulacja.h"
#include <time.h>
#include <stdlib.h>

Symulacja::Symulacja(int foodAmount, int blobAmount) : 
	foodAmount(foodAmount), blobAmount(blobAmount) 
{
	for(int i = 0; i < 1000000; i++)
		day();
}

void Symulacja::placeBlobs()
{
	srand(time(NULL));
}

void Symulacja::placeFood()
{
	srand(time(NULL));
	for (int i = 0; i < Symulacja::foodAmount; i++)
	{
		int x = rand() % 98 + 1;
		int y = rand() % 98 + 1;
		if (board[x][y] == empty)
			board[x][y] = food;
		else
			i--;
	}
}

void Symulacja::day()
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			Symulacja::board[i][j] = empty;
	placeBlobs();
	placeFood();
}
