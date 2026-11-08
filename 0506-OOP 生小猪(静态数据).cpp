#include <iostream>
#include <vector>

using namespace std;

class Sow {
private:
    int age;
public:
    Sow() : age(0) {}

    void grow() {
        age++;
    }

    bool canBirth() const {
        return age >= 4;
    }

    Sow* giveBirth() const {
        return new Sow();
    }
};

int countSows(int years) {
    vector<Sow*> herd;
    herd.push_back(new Sow());  // 第 1 年初，只有 1 头母猪

    for (int year = 1; year <= years; year++) {
        // 1. 先让所有母猪长大 1 岁（使用传统 for 循环）
        for (int i = 0; i < herd.size(); i++) {
            herd[i]->grow();
        }

        // 2. 找出所有可以生育的母猪
        vector<Sow*> newborns;
        for (int i = 0; i < herd.size(); i++) {
            if (herd[i]->canBirth()) {
                newborns.push_back(herd[i]->giveBirth());
            }
        }

        // 3. 加入今年的新母猪
        for (int i = 0; i < newborns.size(); i++) {
            herd.push_back(newborns[i]);
        }
    }

    int count = herd.size();

    // 释放内存
    for (int i = 0; i < herd.size(); i++) {
        delete herd[i];
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << countSows(n) << endl;
    }
    return 0;
}
