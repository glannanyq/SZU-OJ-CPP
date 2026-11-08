#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

template <typename T>
void printVector(const vector<T>& data, bool isFloat = false) {
    cout << "[";
    for (int i = 0; i < (int)data.size(); i++) {
        if (isFloat) {
            cout << fixed << setprecision(1) << data[i];
        } else {
            cout << data[i];
        }
        if (i < (int)data.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string type;
        int n;
        char c1, c2, c3, colon;
        int beg, end;
        
        ss >> type >> n >> c1 >> beg >> c2 >> end >> c3 >> colon;
        
        if (beg < 0) beg = 0;
        if (end > n) end = n;
        if (beg > end) swap(beg, end);
        
        if (type == "int") {
            vector<int> data;
            int temp;
            while (ss >> temp) {
                data.push_back(temp);
            }
            if (beg < end && (int)data.size() == n) {
                sort(data.begin() + beg, data.begin() + end);
            }
            printVector(data);
        } else if (type == "string") {
            vector<string> data;
            string temp;
            while (ss >> temp) {
                data.push_back(temp);
            }
            if (beg < end && (int)data.size() == n) {
                sort(data.begin() + beg, data.begin() + end);
            }
            printVector(data);
        } else if (type == "float") {
            vector<float> data;
            float temp;
            while (ss >> temp) {
                data.push_back(temp);
            }
            if (beg < end && (int)data.size() == n) {
                sort(data.begin() + beg, data.begin() + end);
            }
            printVector(data, true);
        }
    }
    
    return 0;
}
