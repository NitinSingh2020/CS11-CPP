#ifndef POINT_HH
#define POINT_HH

class Point {
    double x_coord, y_coord;    // Data-members

public:
    Point();                    // Default Constructor
    Point(double x, double y);  // Constructor
    Point(const Point &point);  // Copy Constructor

    ~Point();                   // Destructors

    // Accessor methods
    double getX();
    double getY();

    // Mutators
    void setX(double x);
    void setY(double y);

    Point operator+(Point &p);  // Overloading the + operator
};

#endif /* POINT_HH */