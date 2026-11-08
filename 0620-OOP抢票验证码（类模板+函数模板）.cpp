#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool isValid(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        char type;
        cin >> type;
        
        if (type == 'i' || type == 'I') {
            int arr[6];
            for (int i = 0; i < 6; i++) {
                cin >> arr[i];
            }
            if (isValid(arr, 6)) {
                cout << "Valid" << endl;
            } else {
                cout << "Invalid" << endl;
            }
        } else if (type == 'c' || type == 'C') {
            char arr[6];
            for (int i = 0; i < 6; i++) {
                cin >> arr[i];
            }
            if (isValid(arr, 6)) {
                cout << "Valid" << endl;
            } else {
                cout << "Invalid" << endl;
            }
        } else if (type == 'f' || type == 'F') {
            float arr[6];
            for (int i = 0; i < 6; i++) {
                cin >> arr[i];
            }
            if (isValid(arr, 6)) {
                cout << "Valid" << endl;
            } else {
                cout << "Invalid" << endl;
            }
        }
    }

}
