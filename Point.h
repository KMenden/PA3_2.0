// An n-dimensional point class!
// Coordinates are double-precision floating point.

#ifndef __point_h
#define __point_h
#include <iostream>


namespace Clustering {
    class Point {
        int dim;
        double *coords;
        static constexpr char POINT_VALUE_DELIM = ',';

    public:
        // Constructors
        Point();                      // default constructor
        Point(int);    // constructor with a given number of dimensions
        Point(int, double *);
        Point(const Point &);

        // Destructor
        ~Point();

        // Overloaded assignment, comparison, and arithmetic operators
        Point &operator=(const Point &rhs);

        friend bool operator==(const Point &, const Point &);

        friend bool operator!=(const Point &, const Point &);

        friend bool operator<(const Point &, const Point &);

        friend bool operator>(const Point &, const Point &);

        friend bool operator<=(const Point &, const Point &);

        friend bool operator>=(const Point &, const Point &);

        friend Point &operator+=(Point &, const Point &);

        friend Point &operator-=(Point &, const Point &);

        friend const Point operator+(const Point &, const Point &);

        friend const Point operator-(const Point &, const Point &);

        double &operator[](int index) { return coords[index - 1]; }

        friend std::ostream &operator<<(std::ostream &output, const Point &point);

        friend std::istream &operator>>(std::istream &, Point &);

        //Member Variable overloaded arithemtic operators
        Point &operator*=(double);

        Point &operator/=(double);

        const Point operator*(double) const;

        const Point operator/(double) const;

        // Mutator methods
        double getValue(int) const;
        void setValue(int, double);

        // Accessor methods
        int getDims() const { return dim; }

        double distanceTo(Point &point1);


    };
}

#endif // __point_h