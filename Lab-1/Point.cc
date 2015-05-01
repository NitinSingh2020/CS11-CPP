#include "Point.hh"
#include <iostream>

// Default (aka no-argument) constructor
Point::Point() {
    x_coord = 0;
    y_coord = 0;
}

// Two-argument constructor - sets point to (x, y)
Point::Point(double x, double y) {
	x_coord = x;
	y_coord = y;
}

// Copy Constructor
Point::Point(const Point &point) {
	std::cout << "Copy constructor called" << endl;
}

// Clean up a Point instance.
Point::~Point() {
	// no dynamically allocated resources, so doesnt do anything
	std::cout << "Destructor called" << endl;
}

// Returns X-coordinate of a Point
double Point::getX() {
    return x_coord;
}
// Returns Y-coordinate of a Point
double Point::getY() {
    return y_coord;
}
// Sets X-coordinate of a Point
void Point::setX(double x) {
    x_coord = x;
}
// Sets Y-coordinate of a Point
void Point::setY(double y) {
    y_coord = y;
}

// Overloading of the + operator
Point Point::operator+(Point &p) {
	return Point(this->getX()+p.getX(), this->getY()+p.getY());
}