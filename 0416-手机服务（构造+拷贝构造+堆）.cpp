#include <iostream>
#include <cstring>
using namespace std;

class Date
{
    int year, month, day;
public:
    Date(int y, int m, int d);
    void print();
};

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

void Date::print()
{
    cout << year << "." << month << "." << day;
}

class Phone
{
    char type;
    char *number;
    int state;
    Date *stopDate;
public:
    Phone(char t, char *num, int s, int y, int m, int d);
    Phone(const Phone &p);
    ~Phone();
    void print();
    void stop(int y, int m, int d);
};

Phone::Phone(char t, char *num, int s, int y, int m, int d)
{
    type = t;
    number = new char[strlen(num) + 1];
    strcpy(number, num);
    state = s;
    
    if (state == 3)
    {
        stopDate = new Date(y, m, d);
    }
    else
    {
        stopDate = NULL;
    }
    
    cout << "Construct a new phone " << number << endl;
}

Phone::Phone(const Phone &p)
{
    type = 'D';
    number = new char[strlen(p.number) + 2];
    strcpy(number, p.number);
    strcat(number, "X");
    state = p.state;
    
    if (p.stopDate != NULL)
    {
        stopDate = new Date(*p.stopDate);
    }
    else
    {
        stopDate = NULL;
    }
    
    cout << "Construct a copy of phone " << p.number << endl;
}

Phone::~Phone()
{
    delete[] number;
    if (stopDate != NULL)
    {
        delete stopDate;
    }
}

void Phone::print()
{
    cout << "类型=";
    if (type == 'A') cout << "机构";
    else if (type == 'B') cout << "企业";
    else if (type == 'C') cout << "个人";
    else if (type == 'D') cout << "备份";
    
    cout << "||号码=" << number << "||State=";
    if (state == 1) cout << "在用";
    else if (state == 2) cout << "未用";
    else if (state == 3) cout << "停用";
    
    if (state == 3 && stopDate != NULL)
    {
        cout << "||停机日期=";
        stopDate->print();
    }
    cout << endl;
}

void Phone::stop(int y, int m, int d)
{
    state = 3;
    stopDate = new Date(y, m, d);
    cout << "Stop the phone " << number << endl;
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        char type;
        char num[12];
        int state, y, m, d;
        cin >> type >> num >> state >> y >> m >> d;
        
        Phone p1(type, num, state, y, m, d);
        p1.print();
        
        Phone p2 = p1;
        p2.print();
        
        if (state != 3)
        {
            p1.stop(y, m, d);
        }
        p1.print();
        
        cout << "----" << endl;
        
    }

}
