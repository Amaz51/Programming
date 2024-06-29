#include<iostream>
using namespace std;
class BasicShape {
	double area;
	double shapearea;
public:
	double getarea() {
		return area;
	}
	void setarea(double ar) {
		area = ar;
	}
	
	virtual void calcArea() {

	}
};

class Circle:public BasicShape {
	long int centerX;
	long int centerY;
	double radius;
	
public:
	Circle(long int x,long int y,double rad) {
		centerX = x;
		centerY = y;
		radius = rad;
		calcArea();
	}
	long int getCenterX() {
		return centerX;
	}
	long int getCenterY() {
		return centerY;
	}
	void calcArea() {
		double a = 3.14159 * radius * radius;
		BasicShape::setarea(a);
	}
};
class Rectangle :public BasicShape {
	long int length;
	long int width;

public:
	Rectangle(long int len, long int wid) {
		length = len;
		width = wid;
		calcArea();
	}
	long int getwidth() {
		return width;
	}
	long int getlenght() {
		return length;
	}
	void calcArea() {
		double a = length*width;
		BasicShape::setarea(a);
	}

};


int main() {
	int x, y;
	double r;
	cout << "Enter X-Coordinate of the circle : ";
	cin >> x;
	cout << "Enter Y-Coordinate of the circle : ";
	cin >> y;
	cout << "Enter Radius of the circle : ";
	cin >> r;
	Circle c(x,y,r);
	cout << "Area of Circle is : " << c.getarea()<<endl<<endl;
	long int xx, yy;
	cout << "Enter length of rectangle : ";
	cin >> xx;
	cout << "Enter width of rectangle : ";
	cin >> yy;
	Rectangle rr(xx,yy);
	cout << "Area of Rectangle is : " << rr.getarea()<<endl;
}