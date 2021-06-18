#include <iostream>
#include <string>
using namespace std;
class Shape {
private:
	int x;
	int y;
public:
	Shape(int X = 0, int Y = 0)
		:x(X), y(Y) {
		cout << "Shape Constructor..." << endl;
	}
	void setCoord(int X, int Y) {
		x = X;
		y = Y;
	}
	void print() {
		cout << "(" << x<<"," << y << ")";
		}
};
class Circle :public Shape {
	float radius;
public:
	Circle(int X = 0, int Y = 0, float r = 0)
		:Shape(X, Y), radius(r) {
		cout << "Circle Constructor..." << endl;
	}
	void setRadius(float r) {
		radius = r;
	}
	void print() {
		Shape::print();
		cout <<", "<<radius;
	}
};

class ColoredCircle :public Circle {
	string color;
public:
	ColoredCircle(int X = 0, int Y = 0, float r = 0,string c="red")
		:Circle(X, Y,r), color(c) {
		cout << "ColoredCircle Constructor..." << endl;
	}
	void setColor(string c) {
		color = c;
	}
	void print() {
		Circle::print();
		cout << ", " << color;
	}
};
int main() {
	Circle c1(1, 2, 5.0);
	c1.setCoord(3, 2);
	c1.setRadius(7);
	c1.print();
	cout << endl;

	ColoredCircle cc(1, 2, 5.0,"blue");
	cc.setCoord(3, 2);
	cc.setRadius(7);
	cc.setColor("yellow");
	cc.print();
	
	Shape shape;
	shape.setCoord(1, 2);
	shape.print();
	cout << endl;

	return 0;
}