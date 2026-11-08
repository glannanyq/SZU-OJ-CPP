#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class Point {
private:
    double x, y;
public:
    Point(double xx = 0, double yy = 0) : x(xx), y(yy) {}
    
    double distance() const {
        return sqrt(x * x + y * y);
    }
    
    bool operator>(const Point& other) const {
        return distance() > other.distance();
    }
    
    bool operator<(const Point& other) const {
        return distance() < other.distance();
    }
    
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << fixed << setprecision(1) << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

template <typename T>
void mysort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void print(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << " " << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        char type;
        int n;
        cin >> type >> n;
        
        if (type == 'I') {
            int* arr = new int[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            mysort(arr, n);
            print(arr, n);
            delete[] arr;
        } else if (type == 'D') {
            double* arr = new double[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            mysort(arr, n);
            print(arr, n);
            delete[] arr;
        } else if (type == 'S') {
            string* arr = new string[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            mysort(arr, n);
            print(arr, n);
            delete[] arr;
        } else if (type == 'P') {
            Point* arr = new Point[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            mysort(arr, n);
            print(arr, n);
            delete[] arr;
        }
    }
    
    return 0;
}
