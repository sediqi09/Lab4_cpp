#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;

public:
    // Constructors
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}

    void inputFromKeyboard() {
        cout << "Enter x coordinate: ";
        while (!(cin >> x)) {
            cout << "Invalid input. Please enter a numeric value for x: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter y coordinate: ";
        while (!(cin >> y)) {
            cout << "Invalid input. Please enter a numeric value for y: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    double distanceToOrigin() const {
        return sqrt(x * x + y * y);
    }

    // Overloaded output operator
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    // Unary operators
    Point& operator--() { // Decrease x and y by 1
        --x;
        --y;
        return *this;
    }

    Point operator-() { // Swap x and y
        return Point(y, x);
    }

    // Type cast operators
    operator int() const { // Implicit cast to int (integer part of x)
        return static_cast<int>(x);
    }

    explicit operator double() const { // Explicit cast to double (y coordinate)
        return y;
    }

    // Binary operators
    Point operator-(int value) const { // Subtract integer from x
        return Point(x - value, y);
    }

    double operator-(const Point& p) const { // Distance to another point
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }

    // Additional function: Calculate the midpoint between two points
    Point midpoint(const Point& p) const {
        return Point((x + p.x) / 2, (y + p.y) / 2);
    }
};

int main() {
    Point p1, p2;

    cout << "Enter coordinates for Point p1:" << endl;
    p1.inputFromKeyboard();

    // Task 1 functionality
    cout << "Point p1: " << p1 << endl;
    cout << "Distance from p1 to origin: " << p1.distanceToOrigin() << endl;

    // Task 2 functionality
    --p1;
    cout << "Decrease the x and y coordinates by 1: " << p1 << endl;

    Point swappedP1 = -p1;
    cout << "After swapping coordinates of p1: " << swappedP1 << endl;

    // Input for p2
    cout << "Enter coordinates for Point p2:" << endl;
    p2.inputFromKeyboard();

    // Calculate distance between p1 and p2
    cout << "Distance between p1 and p2: " << p1 - p2 << endl;

    // Subtract an integer from p1
    int subValue;
    cout << "Enter an integer to subtract from x of p1: ";
    while (!(cin >> subValue)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Point newP1 = p1 - subValue;
    cout << "After subtracting " << subValue << " from p1.x: " << newP1 << endl;

    // Type casts
    int xPart = p1;
    cout << "Integer part of p1.x: " << xPart << endl;

    double yPart = static_cast<double>(p1);
    cout << "Double value of p1.y: " << yPart << endl;

    // Additional functionality: Calculate midpoint
    Point mid = p1.midpoint(p2);
    cout << "Midpoint between p1 and p2: " << mid << endl;

    return 0;
}

/*
midpoint:  (((x1+x2)/2),((y1+y2)/2)))

input:
Enter coordinates for Point p1:
Enter x coordinate: 3
Enter y coordinate: 4
Enter coordinates for Point p2:
Enter x coordinate: 6
Enter y coordinate: 8
Enter an integer to subtract from x of p1: 2


output:
Point p1: (3, 4)
Distance from p1 to origin: 5
Decrease the x and y coordinates by 1: (2, 3)
After swapping coordinates of p1: (3, 2)
Distance between p1 and p2: 6.40312
After subtracting 2 from p1.x: (0, 3)
Integer part of p1.x: 2
Double value of p1.y: 3
Midpoint between p1 and p2: (4, 5.5)
*/