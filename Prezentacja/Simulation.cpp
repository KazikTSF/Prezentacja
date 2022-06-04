#include "Simulation.h"
#include <time.h>
#include <stdlib.h>
#include "State.h"

Simulation::Simulation(int foodAmount, int blobAmount)
{
	Simulation::foodAmount = foodAmount;
	Simulation::blobAmount = blobAmount;
	placeBlobs();
	for(int i = 0; i < 1000000; i++)
		day();
}

state Simulation::getBoardState(int x, int y)
{
    return board[x][y].getState();
}

void Simulation::placeBlobs()
{
	srand(time(NULL));
    for (int i = 0; i < Simulation::blobAmount; i++)
    {
        if (rand() % 2 == 0)
        {
            if (rand() % 2 == 0)
            {
                int x = 0;
                int y = rand() % 100;
                if (board[x][y].getState() == empty)
                    board[x][y] = Object(x, y, blob);
                else
                    i--;
            }
            else
            {
                int x = 99;
                int y = rand() % 100;
                if (board[x][y].getState() == empty)
                    board[x][y] = Object(x, y, blob);
                else
                    i--;
            }
        }
        else
        {
            if (rand() % 2 == 0)
            {
                int x = rand() % 100;
                int y = 0;
                if (board[x][y].getState() == empty)
                    board[x][y] = Object(x, y, blob);
                else
                    i--;
            }
            else
            {
                int x = rand() % 100;
                int y = 99;
                if (board[x][y].getState() == empty)
                    board[x][y] = Object(x, y, blob);
                else
                    i--;
            }
        }
    }
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

void Simulation::reproduce()
{
    for (int i = 0; i < 100; i++)
    {
        if (Simulation::board[i][0].getState() == blob)
        {
            if (Simulation::board[i][0].shouldReproduce())
            {
                for(int j = 0; true; j++)
                {
                    if (i-j > 0)
                    {
                        if (Simulation::board[i - j][0].getState() == empty)
                        {
                            Simulation::board[i - j][0] = Object(i - j, 0, blob);
                            Simulation::board[i - j][0].mutate();
                            break;
                        }
                    }
                    if (i+j < 99)
                    {
                        if (Simulation::board[i + j][0].getState() == empty)
                        {
                            Simulation::board[i + j][0] = Object(i + j, 0, blob);
                            Simulation::board[i + j][0].mutate();
                            break;
                        }
                    }
                }
            }
        }
        if (Simulation::board[i][99].getState() == blob)
        {
            if (Simulation::board[i][0].shouldReproduce())
            {
                for (int j = 0; true; j++)
                {
                    if (i - j > 0)
                    {
                        if (Simulation::board[i - j][99].getState() == empty)
                        {
                            Simulation::board[i - j][99] = Object(i - j, 99, blob);
                            Simulation::board[i - j][99].mutate();
                            break;
                        }
                    }
                    if (i + j < 99)
                    {
                        if (Simulation::board[i + j][99].getState() == empty)
                        {
                            Simulation::board[i + j][99] = Object(i + j, 99, blob);
                            Simulation::board[i + j][99].mutate();
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 100; i++)
    {
        if (Simulation::board[0][i].getState() == blob)
        {
            if (Simulation::board[0][i].shouldReproduce())
            {
                for (int j = 0; true; j++)
                {
                    if (i - j > 0)
                    {
                        if (Simulation::board[0][i - j].getState() == empty)
                        {
                            Simulation::board[0][i - j] = Object(0, i - j, blob);
                            Simulation::board[0][i - j].mutate();
                            break;
                        }
                    }
                    if (i + j < 99)
                    {
                        if (Simulation::board[0][i + j].getState() == empty)
                        {
                            Simulation::board[0][i + j] = Object(0, i + j, blob);
                            Simulation::board[0][i + j].mutate();
                            break;
                        }
                    }
                }
            }
        }
        if (Simulation::board[99][i].getState() == blob)
        {
            if (Simulation::board[99][i].shouldReproduce())
            {
                for (int j = 0; true; j++)
                {
                    if (i - j > 0)
                    {
                        if (Simulation::board[99][i - j].getState() == empty)
                        {
                            Simulation::board[99][i - j] = Object(99, i - j, blob);
                            Simulation::board[99][i - j].mutate();
                            break;
                        }
                    }
                    if (i + j < 99)
                    {
                        if (Simulation::board[99][i + j].getState() == empty)
                        {
                            Simulation::board[99][i + j] = Object(99, i + j, blob);
                            Simulation::board[99][i + j].mutate();
                            break;
                        }
                    }
                }
            }
        }
    }
}
