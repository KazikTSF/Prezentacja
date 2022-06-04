#include "Simulation.h"
#include <time.h>
#include <stdlib.h>
#include "State.h"

Simulation::Simulation(int foodAmount, int blobAmount) : 
	foodAmount(foodAmount), blobAmount(blobAmount) 
{
	for(int i = 0; i < 1000000; i++)
		day();
}

void Simulation::placeBlobs()
{
	srand(time(NULL));
}

void Simulation::placeFood()
{
	srand(time(NULL));
	for (int i = 0; i < Simulation::foodAmount; i++)
	{
		int x = rand() % 98 + 1;
		int y = rand() % 98 + 1;
		if (board[x][y].getState() == empty)
			board[x][y] = Object(x, y, food);
		else
			i--;
	}
}

void Simulation::day()
{
	for (int i = 1; i < 99; i++)
		for (int j = 1; j < 99; j++)
			board[i][j] = Object(i, j, empty);
	placeFood();
}
