#include "Point.h"
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;
using namespace Clustering;

//
// Default constructor
// Initializes the point to (0.0, 0.0, 0.0)
Point::Point() {

}

// Constructor

Point::Point(int numofdemensions)
{

       dim = numofdemensions;
      coords = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        coords[i] = 0;
    }
}

Point::Point(int numofdemensions, double *array)
{
    dim = numofdemensions;
    coords = new double[dim];

    for (int i = 0; i < dim; i++)
    {
        coords[i] = array[i];
    }

}

Point::Point(const Point &temp)
    {
        dim = temp.dim;
        coords = new double[dim];
        for (int i = 0; i < dim; i++)
        {
            coords[i] = temp.coords[i];
        }
    }

// Destructor
//Releases the memory occupied by the coords pointer
Point::~Point()
{
  delete[] coords;
}

double Point::getValue(int index) const
{
    return coords[index - 1];

}


void Point::setValue(int index, double value)
{
    coords[index - 1] = value;
}

 Point& Point::operator=(const Point &rhs)
 {
     if(this == &rhs)
         return *this;

     dim = rhs.dim;

     for(int i = 0; i < dim; i++)
     {

         coords[i] = rhs.coords[i];
     }

     return *this;
 }

namespace Clustering {

    bool operator==(const Point &lhs, const Point &rhs) {
        bool result;

        for (int i = 0; i < lhs.getDims(); i++) {
            if (lhs.coords[i] == rhs.coords[i])
                result = true;
            else {
                result = false;
                return result;
            }
        }

        return result;
    }


    bool operator!=(const Point &lhs, const Point &rhs) {
        bool result;

        for (int i = 0; i < lhs.getDims(); i++) {
            if (lhs.coords[i] == rhs.coords[i])
                result = false;
            else {
                result = true;
                return result;
            }
        }

        return result;
    }

    bool operator<(const Point &lhs, const Point &rhs) {
        int index = 0;

        for (int i = 0; i < lhs.getDims(); i++) {
            if (lhs.coords[i] == rhs.coords[i])
                index++;
            else
                break;
        }

        if (lhs.coords[index] < rhs.coords[index])
            return true;
        else
            return false;
    }

    bool operator>(const Point &lhs, const Point &rhs) {
        int index = 0;

        for (int i = 0; i < lhs.getDims(); i++) {
            if (lhs.coords[i] == rhs.coords[i])
                index++;
            else
                break;
        }

        if (lhs.coords[index] > rhs.coords[index])
            return true;
        else
            return false;
    }

    bool operator<=(const Point &lhs, const Point &rhs) {
        int index = 0;
        bool same;
        for (int i = 0; i < lhs.getDims(); i++) {
            if (lhs.coords[i] == rhs.coords[i]) {
                index++;
                same = true;
            }
            else
                same = false;
            break;
        }
        if (same == true)
            return true;
        else {
            if (lhs.coords[index] < rhs.coords[index])
                return true;
            else
                return false;
        }
    }

    bool operator>=(const Point &lhs, const Point &rhs) {
        int index = 0;
        bool same;
        for (int i = 0; i < lhs.getDims(); i++) {
            if (lhs.coords[i] == rhs.coords[i]) {
                index++;
                same = true;
            }
            else
                same = false;
            break;
        }
        if (same == true)
            return true;
        else {
            if (lhs.coords[index] > rhs.coords[index])
                return true;
            else
                return false;
        }
    }

    Point &operator+=(Point &lhs, const Point &rhs)
    {
        for(int i = 0; i < lhs.dim; i++)
        {
            lhs.coords[i] += rhs.coords[i];
        }

        return lhs;

    }


    Point &operator-=(Point &lhs, const Point &rhs)
    {
        for(int i = 0; i < lhs.dim; i++)
        {
            lhs.coords[i] -= rhs.coords[i];
        }

        return lhs;

    }


    const Point operator+(const Point &lhs, const Point &rhs)
    {
        Point result(lhs.dim);

        for(int i = 0; i < lhs.dim; i++)
        {
           result.coords[i] = lhs.coords[i] + rhs.coords[i];
        }

        return result;


    }

    const Point operator-(const Point &lhs, const Point &rhs)
    {
        Point result(lhs.dim);

        for(int i = 0; i < lhs.dim; i++)
        {
            result.coords[i] = lhs.coords[i] - rhs.coords[i];
        }

        return result;


    }

    Point &Point::operator*=(double number)
    {
        for(int i = 0; i < dim; i++)
        {
            coords[i] *= number;
        }

        return *this;
    }

    Point &Point::operator/=(double number)
    {
        assert( number != 0);

        for(int i = 0; i < dim; i++)
        {
            coords[i] /= number;
        }

    }

    const Point Point::operator*(double number) const
    {
        Point result(dim);

        for(int i = 0; i < dim; i++)
        {
            result.coords[i] = coords[i] * number;
        }

        return result;

    }

    const Point Point::operator/(double number) const
    {
        Point result(dim);

        for(int i = 0; i < dim; i++)
        {
            result.coords[i] = coords[i] / number;
        }

        return result;

    }

    std::ostream &operator<<(std::ostream &output, const Point &point)
    {

        for (int i = 0; i < point.getDims(); i++) {

            output << point.coords[i] << ",";

        }

        return output;

    }

    std::istream &operator>>(std::istream &input, Point &point)
    {

        string value;
        double d;
        int i = 0;


        while (getline(input, value, point.POINT_VALUE_DELIM)) {
            d = stod(value);

            cout << "Value: # " << i << "   " << d << endl;

            point.setValue(++i, d);
        }


        return input;
    }


}

// Mutator methods
// Change the values of private member variables


// Accessors
// Return the current values of private member variables



double Point::distanceTo(Point &point1)
{
    assert(dim == point1.dim);
    double sum = 0;
    double difference = 0;
    for(int i = 0; i < dim; i++)
    {
        difference = (pow(coords[i] - point1.coords[i], 2));
        sum += difference;
    }

    sum = sqrt(sum);

  return sum;
}