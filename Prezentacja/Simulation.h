#pragma once
#include "Object.h"
class Simulation
{

private:
	int width, height, foodAmount, blobAmount;
	Object board[100][100]; //(0,0) w lewym górnym rogu
	void placeBlobs();
	void placeFood();
	void day();
public:
	Simulation(int, int);
};