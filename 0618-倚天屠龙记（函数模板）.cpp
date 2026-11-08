#include <iostream>
#include <string>
using namespace std;

template <typename T>
void concat(T a[], T b[], int n, T result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        result[n + i] = b[i];
    }
}

template <typename T>
void print(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        char type;
        int n;
        cin >> type >> n;
        
        if (type == 'I') {
            int* a = new int[n];
            int* b = new int[n];
            int* result = new int[2 * n];
            
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            for (int i = 0; i < n; i++) {
                cin >> b[i];
            }
            
            concat(a, b, n, result);
            print(result, 2 * n);
            
            delete[] a;
            delete[] b;
            delete[] result;
        } else if (type == 'D') {
            double* a = new double[n];
            double* b = new double[n];
            double* result = new double[2 * n];
            
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            for (int i = 0; i < n; i++) {
                cin >> b[i];
            }
            
            concat(a, b, n, result);
            print(result, 2 * n);
            
            delete[] a;
            delete[] b;
            delete[] result;
        } else if (type == 'C') {
            string a, b;
            cin >> a >> b;
            cout << b << a << endl;
        }
    }

}
