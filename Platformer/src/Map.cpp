#include "Map.h"

Map::Map(double width, double height): width(width), height(height) {

	barrier.resize(height, std::vector<bool>(width));
	std::fill(barrier.begin(), barrier.end(), std::vector<bool>(width, false));

}

Map::Map(double width, double height, std::vector<Shape*> shapes) : width(width), height(height), shapes(shapes) {

	barrier.resize(height, std::vector<bool>(width));
	std::fill(barrier.begin(), barrier.end(), std::vector<bool>(width, false));

	for (Shape* s : shapes) {
		updateBarrier(s);
	}
}

void Map::draw() {
	for (Shape* s : shapes) {
		s->draw();
	}
}

void Map::addShape(Shape* shape) {
	shapes.push_back(shape);
	updateBarrier(shape);
}

void Map::updateBarrier(Shape* shape) {
	for (std::pair<int, int> p : shape->getArea()) {
		barrier[p.second][p.first] = true;
	}
}

std::vector<std::vector<bool>> Map::getBarrier() {
	return barrier;
}

bool Map::insideBarrier(double x, double y) {
	return barrier[y][x];
}