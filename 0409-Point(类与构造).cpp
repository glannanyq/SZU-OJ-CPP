#include <bits/stdc++.h>
using namespace std;

class Point {
	double x, y;
public:
	Point();
	Point(double x_value,double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point p);
};

Point::Point() : x(0), y(0) {}

Point::Point(double x_value, double y_value) {
	x = x_value;
	y = y_value;
}
void Point::setX(double x_value) {
	x = x_value;
}

void Point::setY(double y_value) {
	y = y_value; 
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

double Point::distanceToAnotherPoint(Point p) {
	double dx = x - p.getX();
    double dy = y - p.getY();
	return sqrt(dx * dx + dy * dy);
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		Point p1(x1, y1);
		Point p2(x2, y2);
		
		double d = p1.distanceToAnotherPoint(p2);
		cout << "Distance of Point(" << fixed << setprecision(2) << x1 << "," 
		<< fixed << setprecision(2) << y1 << ") to Point(" 
		<< fixed << setprecision(2) << x2 << "," 
		<< fixed << setprecision(2) << y2 << ") is " 
		<< fixed << setprecision(2) << d << endl;
	}
}
