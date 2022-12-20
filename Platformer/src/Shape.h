#include <math.h>
#include <GLFW/glfw3.h>
#include <vector>
#pragma once

class Shape {

protected:
	const double pi = acos(-1);
	std::vector<std::pair<int, int>> area;
public:
	void virtual draw() = 0;
	std::vector<std::pair<int, int>> virtual getArea() = 0;
	void virtual setArea() = 0;
};

class Point : public Shape {
private:
	int x;
	int y;
	int red;
	int green;
	int blue;
public:

	Point(int x, int y, int red, int green, int blue) :
		x(x), y(y), red(red), green(green), blue(blue) {}

	void draw();
	
};

class Line : public Shape {
private:
	int x;
	int y;
	int width;
	int angle;
	int red;
	int green;
	int blue;
public:
	Line(int x, int y, int width, int angle, int red, int green, int blue) :
		x(x), y(y), width(width), angle(angle), red(red), green(green), blue(blue) {}

	void draw();
};

class Circle : public Shape {
private:
	int x;
	int y;
	int radius;
	int angle1;
	int angle2;
	int red;
	int green;
	int blue;
public:
	Circle(int x, int y, int radius, int angle1, int angle2, int red, int green, int blue) :
		x(x), y(y), radius(radius), angle1(angle1), angle2(angle2), red(red), green(green), blue(blue) {}

	void draw();
};

class Triangle : public Shape {
private:
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int red;
	int green;
	int blue;
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int red, int green, int blue) :
		x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), red(red), green(green), blue(blue) {}

	void draw();
};

class Rectangle : public Shape {
private:
	int x;
	int y;
	int angle;
	int width;
	int height;
	int red;
	int green;
	int blue;
public:
	Rectangle(int x, int y, int angle, int width, int height, int red, int green, int blue) :
		x(x), y(y), angle(angle), width(width), height(height), red(red), green(green), blue(blue) {
		setArea();
	}

	void draw();
	std::vector<std::pair<int, int>> getArea();
	void setArea();
};
