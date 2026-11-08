#include <iostream>
#include <string>
using namespace std;

template <typename T>
void findMax(T arr[], int n, T& maxKey, int& maxCount) {
    maxCount = 0;
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxKey = arr[i];
        }
    }
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
            int maxKey;
            int maxCount;
            findMax(arr, n, maxKey, maxCount);
            cout << maxKey << " " << maxCount << endl;
            delete[] arr;
        } else if (type == 'C') {
            char* arr = new char[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            char maxKey;
            int maxCount;
            findMax(arr, n, maxKey, maxCount);
            cout << maxKey << " " << maxCount << endl;
            delete[] arr;
        } else if (type == 'S') {
            string* arr = new string[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            string maxKey;
            int maxCount;
            findMax(arr, n, maxKey, maxCount);
            cout << maxKey << " " << maxCount << endl;
            delete[] arr;
        }
    }

}
