#include <iostream>
using namespace std;

class CDate
{
public:
    CDate(int, int, int); // 构造函数
    void print();   // 输出：mm/dd/yyyy, 星期
    void getWeekofDay(); // 按题目给出公式计算星期几，即week值，1～7

private:
    int month;
    int day;
    int year;
    int week;  
};
// 补齐CDate的构造函数头，空函数体{}已给出
CDate::CDate(int y, int m, int d) : year(y), month(m), day(d)
{
}
// 补齐getWeekofDay,print成员函数和主函数
void CDate::getWeekofDay()
{
    int y = year;
    int m = month;
    int d = day;
    
    // 如果month为1或2，则公式里month取13或14，year减1
    if (m == 1 || m == 2) {
        m += 12;
        y -= 1;
    }
    
    // 按照公式计算星期
    // week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7 + 1
    int result = (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7;
    week = result + 1;
}

void CDate::print()
{
    // 输出日期格式：月/日/年
    cout << month << "/" << day << "/" << year << ", ";
    
    // 根据week的值输出对应的星期
    switch(week) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
        case 7: cout << "Sunday"; break;
    }
    cout << endl;
}

int main()
{
    int n;
  	cin >> n;
  	while (n--) {
  	int y, m, d;
    
    // 读取三组数据
    for (int i = 0; i < n; i++) {
        cin >> y >> m >> d;
        CDate date(y, m, d);
        date.getWeekofDay();
        date.print();
    }
    }
    return 0;
}
