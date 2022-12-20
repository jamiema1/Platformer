#include "Shape.h"
#include "Map.h"
#pragma once
class Player
{
private:
	double xPosition;
	double yPosition;
	double yVelocity;
	double xVelocity;

	Shape* shape;
	Map* map;

	const double width = 50;
	const double height = 50;
	const double gravity = -0.001;
	const int windowwidth = 1365;
	const int windowheight = 768 - 23 - 2;

public:
	Player(double xPosition, double yPosition, double xVelocity, double yVelocity, Shape* shape, Map* map);

	double getXPosition();
	double getYPosition();
	double getXVelocity();
	double getYVelocity();

	void setXPosition(double newXPosition);
	void setYPosition(double newYPosition);
	void setXVelocity(double newXVelocity);
	void setYVelocity(double newYVelocity);


	void drawPlayer();
	void updatePlayer();
	void updateShape();
	void movePlayer(double newXVelocity, double newYVelocity);
	bool hittingBarrier();
};

