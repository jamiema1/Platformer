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

	double xBaseSpeed;
	double yBaseSpeed;
	Shape* shape;
	Map* map;

	const double width = 40;
	const double height = 40;
	const double gravity = -0.001;
	const int windowwidth = 1365;
	const int windowheight = 768 - 23;
	const int frequency = 1;
public:
	Player(double xPosition, double yPosition, double xVelocity, double yVelocity, double xBaseSpeed,
		double yBaseSpeed, Shape* shape, Map* map);

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
	void moveHorizontal(bool direction);
	void moveVertical();
	void stopHorizontal();
	void stopVertical();
	bool hittingBarrier();

private:
	bool touchingLeft();
	bool touchingRight();
	bool touchingTop();
	bool touchingBottom();
};

