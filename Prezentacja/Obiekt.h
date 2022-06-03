#pragma once
class Obiekt
{
private:
	float size, speed;
	int sense;
	bool eaten;
public:

	bool shouldReproduce();
	bool shouldMutate();
	int calculateMovement();
};

