#ifndef POINT_HH
#define POINT_HH

class Point {
    double x_coord, y_coord, z_coord;      // Data-members

public:
    /* Constructors */
    Point();                              // Default Constructor
    Point(double x, double y, double z);  // Constructor
    Point(const Point &point);            // Copy Constructor

    /* Destructor */
    ~Point();                         

    /* Accessor methods */
    double getX();
    double getY();
    double getZ();

    /* Mutators */
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    /* Miscallaneous Methods */
    double distanceTo(const Point &p);
    void rotate90aboutZaxis();
    void printPoint();
};

#endif /* POINT_HH */