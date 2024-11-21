#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;

public:
    // Constructors
    Point() : x(0), y(0) {} // Default constructor
    Point(double x, double y) : x(x), y(y) {} // Parameterized constructor
    Point(const Point& p) : x(p.x), y(p.y) {} // Copy constructor

    double distanceToOrigin() const {
        return sqrt(x * x + y * y);
    }

    // Overloaded output operator
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

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
};

int main() {
    Point p1;

    cout << "Enter the coordinates of the point:" << endl;
    p1.inputFromKeyboard();

    cout << "Point p1: " << p1 << endl;
    cout << "Distance to origin: " << p1.distanceToOrigin() << endl;

    return 0;
}

// input : x=3 and y=4
// output : 5