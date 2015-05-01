#include "Point.hh"
#include <iostream>
#include <math.h>

/* Default (aka no-argument) constructor */
Point::Point() {
    x_coord = 0;
    y_coord = 0;
    z_coord = 0;
}

/* Two-argument constructor - sets point to (x, y, z) */
Point::Point(double x, double y, double z) {
    x_coord = x;
    y_coord = y;
    z_coord = z;
}

/* Copy Constructor */
Point::Point(const Point &point) {
    std::cout << "Copy constructor called" << endl;
}

/* Clean up a Point instance */
Point::~Point() {
    // no dynamically allocated resources, so doesnt do anything
    std::cout << "Destructor called" << endl;
}

/* Returns X-coordinate of a Point */
double Point::getX () {
    return x_coord;
}
/* Returns Y-coordinate of a Point */
double Point::getY() {
    return y_coord;
}
/* Returns Z-coordinate of a Point */
double Point::getZ() {
    return z_coord;
}
/* Sets X-coordinate of a Point */
void Point::setX(double x) {
    x_coord = x;
}
/* Sets Y-coordinate of a Point */
void Point::setY(double y) {
    y_coord = y;
}
/* Sets Z-coordinate of a Point */
void Point::setZ(double z) {
    z_coord = z;
}

/* Finds the Euclid Distance of point from the another point P */
double Point::distanceTo(const Point &p) {
    double dx = x_coord - p.getX();
    double dy = y_coord - p.getY();
    double dz = z_coord - p.getZ();

    return sqrt(dx*dx + dy*dy + dz*dz);
}

/* Rotates the Point in Z-plane clockwise by 90 degrees */
void Point::rotate90aboutZaxis() {
    double x = x_coord;
    setX(y_coord);
    setY(-1*x);
}

/* Prints the Point out in cartesian coordinates form */
void Point::printPoint() {
    cout << "(" << x_coord
         << "," << y_coord
         << "," << z_coord << ")" << endl;
}