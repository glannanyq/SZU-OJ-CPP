#include <iostream>
#include <cstring>
using namespace std;

class CTelNumber
{
    char *number;
public:
    CTelNumber(char *num);
    CTelNumber(const CTelNumber &tel);
    ~CTelNumber();
    void print();
    static bool isValid(char *num);
};

bool CTelNumber::isValid(char *num)
{
    int len = strlen(num);
    if (len != 7) return false;
    
    for (int i = 0; i < len; i++)
    {
        if (num[i] < '0' || num[i] > '9') return false;
    }
    
    if (num[0] < '2' || num[0] > '8') return false;
    
    return true;
}

CTelNumber::CTelNumber(char *num)
{
    number = new char[strlen(num) + 1];
    strcpy(number, num);
}

CTelNumber::CTelNumber(const CTelNumber &tel)
{
    char old[8];
    strcpy(old, tel.number);
    
    char newnum[9];
    
    if (old[0] >= '2' && old[0] <= '4')
    {
        newnum[0] = '8';
        for (int i = 0; i < 7; i++)
        {
            newnum[i + 1] = old[i];
        }
        newnum[8] = '\0';
    }
    else if (old[0] >= '5' && old[0] <= '8')
    {
        newnum[0] = '2';
        for (int i = 0; i < 7; i++)
        {
            newnum[i + 1] = old[i];
        }
        newnum[8] = '\0';
    }
    
    number = new char[9];
    strcpy(number, newnum);
}

CTelNumber::~CTelNumber()
{
    delete[] number;
}

void CTelNumber::print()
{
    cout << number << endl;
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        char num[8];
        cin >> num;
        
        if (!CTelNumber::isValid(num))
        {
            cout << "Illegal phone number" << endl;
            continue;
        }
        
        CTelNumber tel1(num);
        CTelNumber tel2 = tel1;
        tel2.print();
    }

}

