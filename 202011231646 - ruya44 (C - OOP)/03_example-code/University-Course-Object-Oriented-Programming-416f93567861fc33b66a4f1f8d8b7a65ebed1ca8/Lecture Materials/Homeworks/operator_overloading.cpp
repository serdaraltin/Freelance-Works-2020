#include <iostream>
using namespace std;
class Point {
	friend Point operator*(const Point&, int);
	friend ostream& operator<<(ostream &, const Point& );
	friend istream& operator>>(istream &, Point&);
	friend Point operator--(Point &p);
	friend Point operator--(Point &p, int i);
	friend Point operator*(int, const Point&);
	int x;
	int y;
	static int count;
public:
	Point(int X = 0, int Y = 0)
		:x(X), y(Y) {
		count++;
	}
	~Point(){
		count--;
	}

	void print() const {
		cout << "(" << x << ", " << y << ")" << endl;
	}
	Point& setXY(int X, int Y) {
		x = X;
		y = Y;
		return *this;
	}
	static void printCount() {
		cout << "Count: " << count <<endl;	
	}
	void printC() {
		cout << "Count: " << count << endl;
	}

	Point operator-(const Point &p) {
		Point tmp;
		tmp.x = x - p.x;
		tmp.y = y - p.y;
		return tmp;
	}
	Point operator++() {
		x++;
		y++;
		return *this;
	}
	Point operator++(int i) {
		Point tmp = *this;
		x++;
		y++;
		return tmp;
	}

	int operator[](int i) {
		if (i == 1)
			return x;
		else if (i == 2)
			return y;
		else {
			cout << "indeks hatali..." << endl;
			return 0;
		}
	}

};

Point operator*(const Point& p, int i)
{
	Point tmp;
	tmp.x = p.x*i;
	tmp.y = p.y*i;
	return tmp;
}
Point operator*(int i,const Point& p)
{
	Point tmp;
	tmp.x = p.x*i;
	tmp.y = p.y*i;
	return tmp;
}

ostream& operator<<(ostream &out, const Point& p) {
	out << "(" << p.x << "," << p.y << ")" << endl;
	return out;
}

istream& operator>>(istream &in, Point& p) {
	in >> p.x >> p.y;
	return in;
}

Point operator--(Point &p) {
	p.x--;
	p.y--;
	return p;
}
Point operator--(Point &p,int i) {
	Point tmp = p;
	p.x--;
	p.y--;
	return tmp;
}


int Point::count = 0;
int main() {

	Point p1(3, 5), p2(1, 2), p3;


	p2 = (++p1);

	p3 = (p1++);

	p2 = (--p1);

	p3 = (p1--);

	
	cin >> p1;

	cout << p1;




	p3 = p1 - p2;

	p3 = p1 * 5;

	p3 = 5 * p1;

	cout << "p1[1]= (x)"<<p1[1] << endl;
	cout << "p1[2]= (y)" << p1[2] << endl;
	cout << "p1[3]= (hatali)" << p1[3] << endl;




	return 0;
}














