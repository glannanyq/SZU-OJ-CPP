#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix {
private:
    int rows, cols;
    vector<vector<T> > data;
public:
    Matrix(int m, int n) : rows(m), cols(n) {
        data.resize(rows, vector<T>(cols));
    }
    
    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }
    
    Matrix<T> transport() {
        Matrix<T> result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
    
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j];
                if (j < cols - 1) cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        char type;
        int m, n;
        cin >> type >> m >> n;
        
        if (type == 'I') {
            Matrix<int> mat(m, n);
            mat.input();
            Matrix<int> result = mat.transport();
            result.print();
        } else if (type == 'D') {
            Matrix<double> mat(m, n);
            mat.input();
            Matrix<double> result = mat.transport();
            result.print();
        } else if (type == 'C') {
            Matrix<char> mat(m, n);
            mat.input();
            Matrix<char> result = mat.transport();
            result.print();
        }
    }
    
    return 0;
}
