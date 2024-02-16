#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
  
    Rectangle():width(0), height(0) {}

    Rectangle(double w, double h):width(w), height(h) {}

    double calculateArea() {
        return width * height;
    }

    void display() {
        cout << "Width" << width <<endl;
        cout << "Height" << height <<endl;
        cout << "Area" << calculateArea() <<::endl;
    }
};

int main() {   
    Rectangle rect1;
    cout << " First Rectangle" <<endl;
    rect1.display();
    
    Rectangle rect2(10, 7);
    cout << "\n Second Rectangle 2" <<endl;
    rect2.display();

    return 0;
}
