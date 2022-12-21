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

	// checks if the player is touching a boundary
	if (xVelocity > 0 && touchingRight()) {
		stopHorizontal();
	}
	else if (xVelocity < 0 && touchingLeft()) {
		stopHorizontal();
	} 
	else if (yVelocity > 0 && touchingTop()) {
		stopVertical();
		xPosition += xVelocity;
	}
	else if (yVelocity < 0 && touchingBottom()) {
		stopVertical();
		xPosition += xVelocity;
	}
	else {
		xPosition += xVelocity;
		yPosition += yVelocity;
		yVelocity += gravity;
	}
	
	
	// checks if the player is touching the outer boundaries
	if (xPosition > windowwidth - width - 1) {
		xPosition = windowwidth - width - 1;
		stopHorizontal();
	}
	if (xPosition < 0) {
		xPosition = 0;
		stopHorizontal();
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

// idk why - 1s are needed
bool Player::touchingLeft() {
	for (int y = yPosition; y < yPosition + height - 1; y += frequency) {
		if (map->insideBarrier(xPosition + xVelocity, y)) {
			return true;
		}
	}
	return false;
}

bool Player::touchingRight() {
	for (int y = yPosition; y < yPosition + height - 1; y += frequency) {
		if (map->insideBarrier(xPosition + xVelocity + width, y)) {
			return true;
		}
	}
	return false;
}

bool Player::touchingTop() {
	for (int x = xPosition; x < xPosition + width - 1; x += frequency) {
		if (map->insideBarrier(x, yPosition + yVelocity + height)) {
			return true;
		}
	}
	return false;
}

bool Player::touchingBottom() {
	for (int x = xPosition; x < xPosition + width - 1; x += frequency) {
		if (map->insideBarrier(x, yPosition + yVelocity)) {
			return true;
		}
	}
	return false;
}

void Player::updateShape() {
	delete shape;

	// idk why + 1 is required
	shape = new Rectangle(xPosition + 1, yPosition, 0, width, height, 0, 127, 0);
}


// true = right, false = left
void Player::moveHorizontal(bool direction) {
	if (direction) {
		xVelocity = xBaseSpeed;
	}
	else {
		xVelocity = -xBaseSpeed;
	}
}

void Player::moveVertical() {
	/*if (yPosition == 0) {
		yVelocity = yBaseSpeed;
	}
	else {*/
		// check across whole base of player
		for (int x = xPosition; x < xPosition + width - 1; x += frequency) {
			if (map->insideBarrier(x, yPosition - 1)) {
				yVelocity = yBaseSpeed;
				break;
			}
		}
	//}
}

void Player::stopHorizontal() {
	xVelocity = 0;
}

void Player::stopVertical() {
	yVelocity = 0;
}