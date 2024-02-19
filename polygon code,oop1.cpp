#include <iostream>
using namespace std;

class Polygon {
public:
    virtual double area()=0 ;
};
class Tri : public Polygon {
private:
    double base, height;
public:
    Tri(double b, double h) {
        base = b;
        height = h;
    }
    double area() {
        return 0.5 * base * height;
    }
};
class Circle : public Polygon {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double area() {
        return 3.142 * radius * radius;
    }
};

class Rec : public Polygon {
private:
    double length, width;
public:
    Rec(double l, double w) {
        length = l;
        width = w;
    }
    double area() {
        return length * width;
    }
};

class Square : public Polygon {
private:
    double side;
public:
    Square(double s) {
        side = s;
    }
    double area() {
        return side * side;
    }
};

int main() {
    char choice;
    cout << "ENTER YOUR CHOICE"<<endl;
    cout << "A. Circle"<<endl;
    cout << "B. Rectangle"<<endl;
    cout << "C. Triangle"<<endl;
    cout << "D. Square"<<endl;

    cin >> choice;

    switch (choice) {
        case 'A': {
            double radius;
            cout << "Enter radius of the circle";
            cin >> radius;
            Circle c(radius);
            cout << "Area of the circle is " << c.area() << endl;
            break;
        }
        case 'B': {
            double length, width;
            cout << "Enterlength , width of the rectangle ";
            cin >> length >> width;
            Rec r(length, width);
            cout << "Area of the rectangle is" << r.area() << endl;
            break;
        }
          case 'C': {
            double base, height;
            cout << "Enter base , height of triangle";
            cin >> base>>height;
            Tri t(base, height);
            cout << "Area of the triangle is" << t.area() << endl;
            break;
        }
         case 'D': {
            double side;
            cout << "Enter side of square";
            cin >> side;
            Square s(side);
            cout << "Area of the square is" << s.area() << endl;
            break;
        }
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}