#include <iostream>
#include <math.h>
#include "Point.hh"

using namespace std;

void outputPoint(Point &p);
void rotate90(Point &p);
double euclideanDistance(Point &p1, Point &p2);

int main() {
    Point p1;              // Calls defafult constructor
    Point p2(3, 4);        // Calls 2-arg constructor
    Point p3(p2);          // Calls copy constructor
    cout << "P2 = ";
    outputPoint(p2);
    rotate90(p2);
    cout << "P2 after rotation = ";
    outputPoint(p2);

    cout << "Distance: " << euclideanDistance(p2, p3) << endl;

    Point p4(12, 34);
    Point p5(22, 41);
    Point p6 = p4 + p5;
    outputPoint(p6);

    /* Heap Allocation example */
    Point *p = new Point(3.5, 2.1);
    cout << "Point is located at: ";
    outputPoint(*p);
    p->setX(3.8);
    cout << "New Position is: ";
    outputPoint(*p);
    delete p; // Free the point
}

void outputPoint(Point &p) {
    cout << "(" << p.getX()
         << "," << p.getY() << ")" << endl;
}

void rotate90(Point &p) {
    double x = p.getX();
    double y = p.getY();
    p.setX(y);
    p.setY(-x);
}

double euclideanDistance(Point &p1, Point &p2) {
    double x = p1.getX() - p2.getX();
    double y = p1.getY() - p2.getY();

    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}