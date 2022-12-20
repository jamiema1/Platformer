#include <vector>
#include "Shape.h"
#pragma once

class Map
{
private:
	double width;
	double height;
	std::vector<std::vector<bool>> barrier;
	std::vector<Shape*> shapes;
public:
	Map(double width, double height);
	Map(double width, double height, std::vector<Shape*> shapes);

	void draw();
	void addShape(Shape* shape);
	void updateBarrier(Shape* shape);
	std::vector<std::vector<bool>> getBarrier();
	bool insideBarrier(double x, double y);
};

