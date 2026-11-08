#include <iostream>
#include <string>
#include <vector>
using namespace std;

class box {
private:
    string num;
    int length;
    int width;
    int height;
public:
    box(string n, int l, int w, int h) : num(n), length(l), width(w), height(h) {
        if (length < width) swap(length, width);
    }

    int volume() const {
        return length * width * height;
    }

    bool canPutInto(const box& outer) const {
        return (length <= outer.length && width <= outer.width && height <= outer.height);
    }

    int operator-(const box& outer) const {
        if (canPutInto(outer))
            return volume();
        else
            return -1;
    }

    string getNum() const { return num; }
};

int main() {
    int n;
    cin >> n;
    vector<box> boxes;
    for (int i = 0; i < n; i++) {
        string num;
        int l, w, h;
        cin >> num >> l >> w >> h;
        boxes.push_back(box(num, l, w, h));
    }

    string best_in, best_out;
    int max_overflow = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int overflow = boxes[i] - boxes[j];
            if (overflow > max_overflow) {
                max_overflow = overflow;
                best_in = boxes[i].getNum();
                best_out = boxes[j].getNum();
            }
        }
    }

    cout << best_in << "盒子放入" << best_out << "盒子溢出的水最多，为" << max_overflow << "。" << endl;

    return 0;
}
