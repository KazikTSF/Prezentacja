#pragma once
class Symulacja
{
enum state
{
	empty = 0,
	food = 1,
	blob = 2
};
private:
	int width, height, foodAmount, blobAmount;
	state board[100][100]; //(0,0) w lewym górnym rogu
	void placeBlobs();
	void placeFood();
public:
	Symulacja(int, int);
	void start();
};