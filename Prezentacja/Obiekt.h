#pragma once
class Obiekt
{

private:
	float size, speed;
	int sense; // jak daleko blob widzi
	bool eaten;
public:
	bool shouldReproduce();
	bool shouldMutate();
	int calculateMovement();
};

