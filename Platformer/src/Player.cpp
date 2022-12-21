#include "Player.h"

// Constructor
Player::Player(double xPosition, double yPosition, double xVelocity, double yVelocity, double xBaseSpeed,
	double yBaseSpeed, Shape* shape, Map* map) :
	xPosition(xPosition), yPosition(yPosition), xVelocity(xVelocity), yVelocity(yVelocity), xBaseSpeed(xBaseSpeed),
	yBaseSpeed(yBaseSpeed), shape(shape), map(map) {
}

// getters
double Player::getXPosition() {
	return xPosition;
}

double Player::getYPosition() {
	return yPosition;
}

double Player::getXVelocity() {
	return xVelocity;
}

double Player::getYVelocity() {
	return yVelocity;
}

// setters
void Player::setXPosition(double newXPosition) {
	xPosition = newXPosition;
}

void Player::setYPosition(double newYPosition) {
	yPosition = newYPosition;
}

void Player::setXVelocity(double newXVelocity) {
	xVelocity = newXVelocity;
}

void Player::setYVelocity(double newYVelocity) {
	yVelocity = newYVelocity;
}



// draws the player model
void Player::drawPlayer() {
	shape->draw();
}

// updates the player
void Player::updatePlayer() {

	std::pair<double, double> currentPosition = { xPosition, yPosition };

	// checks if the player is touching a boundary
	if (touchingTop(currentPosition)) {
		xPosition += xVelocity;
		stopVertical();
	}
	else if (touchingBottom(currentPosition)) {
		xPosition += xVelocity;
		stopVertical();
	}
	else if (touchingLeft(currentPosition)) {
		yPosition += yVelocity;
		yVelocity += gravity;
		stopHorizontal();
	}
	else if (touchingRight(currentPosition)) {
		yPosition += yVelocity;
		yVelocity += gravity;
		stopHorizontal();
	}
	else {
		xPosition += xVelocity;
		yPosition += yVelocity;
		yVelocity += gravity;
	}

	// checks if the player is touching the outer boundaries
	if (xPosition > windowwidth - width - 1) {
		xPosition = windowwidth - width - 1;
	}
	if (xPosition < 0) {
		xPosition = 0;
	}
	if (yPosition > windowheight - height - 1) {
		yPosition = windowheight - height - 1;
		stopVertical();
	}
	if (yPosition < 0) {
		yPosition = 0;
		stopVertical();
	}

	updateShape();
}

bool Player::touchingLeft(std::pair<double, double> currentPosition) {
	return map->insideBarrier(xPosition + xVelocity, yPosition) || 
		map->insideBarrier(xPosition + xVelocity, yPosition + height);
}

bool Player::touchingRight(std::pair<double, double> currentPosition) {
	return map->insideBarrier(xPosition + xVelocity + width, yPosition) ||
		map->insideBarrier(xPosition + xVelocity + width, yPosition + height);
}

bool Player::touchingTop(std::pair<double, double> currentPosition) {
	return map->insideBarrier(xPosition, yPosition + yVelocity + height) ||
		map->insideBarrier(xPosition + width, yPosition + yVelocity + height);
}

bool Player::touchingBottom(std::pair<double, double> currentPosition) {
	return map->insideBarrier(xPosition, yPosition + yVelocity) ||
		map->insideBarrier(xPosition + width, yPosition + yVelocity);
}

void Player::updateShape() {
	delete shape;
	shape = new Rectangle(xPosition + 1, yPosition, 0, width, height, 0, 127, 0);
}


void Player::moveHorizontal(bool direction) {
	if (direction) {
		xVelocity = xBaseSpeed;
	}
	else {
		xVelocity = -xBaseSpeed;
	}
}

void Player::moveVertical() {
	if (yPosition == 0 || map->insideBarrier(xPosition, yPosition - 1) ||
		map->insideBarrier(xPosition + width, yPosition - 1)) {
		yVelocity = yBaseSpeed;
	}
}

void Player::stopHorizontal() {
	xVelocity = 0;
}

void Player::stopVertical() {
	yVelocity = 0;
}