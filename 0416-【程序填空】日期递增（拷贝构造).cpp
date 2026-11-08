//头文件区域
#include <iostream>
using namespace std;

// 日期类CDate
class CDate
{
	int *year,*month,*day;
public:
	CDate(int y,int m, int d);
	void print();
	~CDate();
    // 补齐CDate拷贝构造函数声明
    CDate(const CDate &d);
};

CDate::~CDate()
{
	delete year;
	delete month;
	delete day;
}

void CDate::print()
{
	cout << *year << "/" << *month << "/" << *day << endl;
}

// 补齐构造函数和拷贝构造函数实现

CDate::CDate(int d, int m, int y)
{
    year = new int(y);
    month = new int(m);
    day = new int(d);
}

CDate::CDate(const CDate &d)
{
    int y = *d.year;
    int m = *d.month;
    int day_val = *d.day;
    
    day_val++;
    
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if (day_val > 31)
        {
            day_val = 1;
            m++;
        }
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        if (day_val > 30)
        {
            day_val = 1;
            m++;
        }
    }
    else if (m == 2)
    {
        int isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if ((isLeap && day_val > 29) || (!isLeap && day_val > 28))
        {
            day_val = 1;
            m++;
        }
    }
    
    if (m > 12)
    {
        m = 1;
        y++;
    }
    
    year = new int(y);
    month = new int(m);
    day = new int(day_val);
}
//主函数
int main()
{	int a,b,c;
	cin>>a>>b>>c;
	CDate d1(a,b,c);
	CDate d2=d1;
	CDate d3(d2);
	d1.print();
	d2.print();
	d3.print();
	return 0;
}
