#include <math.h>
#include <iostream>
#include <string>
#include "Point.hh"

using namespace std;

double computeArea(Point &a, Point &b, Point &c);
bool validTriangle(double a, double b, double c);

int main() {
    double a, b, c;
    Point threePoints[3];
    string userInput;

    while (true) {
        for (int i = 0; i < 3; i++) {
            cout << "Enter the coordinates of the point # "
                 << i+1 << " (separated by space) : ";
            cin >> a >> b >> c;
            threePoints[i].setX(a);
            threePoints[i].setY(b);
            threePoints[i].setZ(c);
            cout << "Point # " << i+1 << " ";
            threePoints[i].printPoint();
        }

        cout << "Area is: " << computeArea(threePoints[0], threePoints[1],
            threePoints[2]) << endl;

        cout << "Want to continue? (yes/no)";
        cin >> userInput;

        if (userInput.compare("no") == 0 || userInput.compare("n") == 0)
            break;
    }

    /* Example for constructor */
    Point p1;              // Calls default constructor
    Point p2(3, 4, 5);     // Calls 2-arg constructor
    Point p3(p2);          // Calls copy constructor

    p2.printPoint();
    p2.rotate90aboutZaxis();
    p2.printPoint();

    /* Heap Allocation example */
    Point *p = new Point(3.5, 2.1, 4.7);  // Declare the memory
    cout << "New Point in heap memory is: ";
    p->printPoint();
    delete p;                             // Free the point
}

double computeArea(Point &a, Point &b, Point &c) {
    /*
     * a => Point 1
     * b => Point 2
     * c => Point 3
     * returns the area of the triangle
     * ============================= */
    double side_1 = a.distanceTo(b);
    double side_2 = b.distanceTo(c);
    double side_3 = c.distanceTo(a);

    if (validTriangle(side_1, side_2, side_3)) {
        /* Semi perimeter */
        double s = (side_1 + side_2 + side_3)/2.0;

        /* Triangle Area Using Heron's formula */
        return sqrt(s*(s-side_1)*(s-side_2)*(s-side_3));
    } else {
        cout << "Not a valid triangle" << endl;
        return 0;
    }
}

bool validTriangle(double a, double b, double c) {
    /*
     * a => Length of side 1
     * b => Length of side 2
     * c => Length of side 3
     * returns if the triangle is valid or not
     * ==================================== */
    return (a + b > c) && (b + c > a) && (c + a > b);
}
