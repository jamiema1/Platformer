#include "Shape.h"

void Circle::draw() {
    glBegin(GL_TRIANGLES);
    glColor3b(red, green, blue);
    for (double i = angle1; i < angle2; i++) {
        glVertex2d(x, y);
        glVertex2d(x + radius * cos(i * pi / 180), y + radius * sin(i * pi / 180));
        glVertex2d(x + radius * cos((i + 1) * pi / 180), y + radius * sin((i + 1) * pi / 180));
    }
    glEnd();
}


void Point::draw() {
    glBegin(GL_POINTS);
    glColor3b(red, green, blue);
    glVertex2d(x, y);
    glEnd();
}


void Line::draw() {

    glBegin(GL_LINES);
    glColor3b(red, green, blue);
    glVertex2d(x, y);
    glVertex2d(x + width * cos(angle * pi / 180), y + width * sin(angle * pi / 180));
    glEnd();

}

void Triangle::draw() {
    glBegin(GL_TRIANGLES);
    glColor3b(red, green, blue);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glVertex2d(x3, y3);

    glEnd();
}

void Rectangle::draw() {

    double theta = pi / 180 * angle;
    glBegin(GL_QUADS);
    glColor3b(red, green, blue);
    glVertex2d(x, y);
    glVertex2d(x + width * cos(theta), y + width * sin(theta));
    glVertex2d(x + width * cos(theta) - width * sin(theta), y + height * sin(theta) + height * cos(theta));
    glVertex2d(x - width * sin(theta), y + height * cos(theta));
    glEnd();

}

std::vector<std::pair<int, int>> Rectangle::getArea() {
    return area;
}

void Rectangle::setArea() {
    area.resize(0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            area.push_back(std::make_pair(x + j, y + i));
        }
    }
}