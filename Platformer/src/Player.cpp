#include "Player.h"


Player::Player(double xPosition, double yPosition, double xVelocity, double yVelocity, Shape* shape, Map* map) : 
	xPosition(xPosition), yPosition(yPosition), xVelocity(xVelocity), yVelocity(yVelocity), shape(shape), map(map) {
}

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




void Player::drawPlayer() {
	shape->draw();
}

void Player::updatePlayer() {

	xPosition += xVelocity;
	yPosition += yVelocity;

	if (yPosition != height) {
		yVelocity += gravity;
	}

	if (xPosition > windowwidth - width) {
		xPosition = windowwidth - width;
	}
	if (xPosition < 0) {
		xPosition = 0;
	}
	if (yPosition > windowheight) {
		yPosition = windowheight;
	}
	if (yPosition < 0) {
		yPosition = 0;
	}

	if (hittingBarrier()) {
		if (map->insideBarrier(xPosition - xVelocity, yPosition - yVelocity)) {
			xPosition -= xVelocity;
			yPosition -= yVelocity;
		}
		else if (map->insideBarrier(xPosition - xVelocity, yPosition)) {
			xPosition -= xVelocity;
		}
		else if (map->insideBarrier(xPosition, yPosition - yVelocity)) {
			yPosition -= yVelocity;
		}
	}
	updateShape();
}


void Player::updateShape() {
	delete shape;
	shape = new Rectangle(xPosition, yPosition, 0, width, height, 127, 0, 0);
}

void Player::movePlayer(double newXVelocity, double newYVelocity) {
	xVelocity = newXVelocity;
	if (yPosition == 0 || map->insideBarrier(xPosition, yPosition - 1)) {
		yVelocity = newYVelocity;
	}
}

bool Player::hittingBarrier() {
	return map->insideBarrier(xPosition, yPosition) ||
		map->insideBarrier(xPosition + width, yPosition) ||
		map->insideBarrier(xPosition, yPosition + height) ||
		map->insideBarrier(xPosition + width, yPosition + height);
}