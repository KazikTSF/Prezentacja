#pragma once
#include "Object.h"
class Simulation
{
private:
	int width, height, foodAmount, blobAmount;
	Object board[100][100]; //(0,0) w lewym g�rnym rogu
	void placeBlobs();
	void placeFood();
	void day();
	void reproduce();
public:
	Simulation(int, int);
	state getBoardState(int, int);
};