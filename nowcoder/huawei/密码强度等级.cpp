#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        int score = 0;
        //长度
        int size = str.size();
        if (size <= 4)
            score = score + 5;
        else if (size >= 5 && size <= 7)
            score = score + 10;
        else
            score += 25;
        //字母
        bool low = false;
        bool up = false;
        for (int i = 0; i < size; i++)
        {
            if (str[i] >='a' && str[i] <= 'z')
                low = true;
            else if (str[i] >= 'A' && str[i] <='Z')
                up = true;
        }
        if (up == false && low == false)
        {
            score += 0;
        }
        else if (up == true && low == true)
        {
            score += 20;
        }
        else
        {
            score += 10;
        }
        //数字
        int k = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
                k++;
        }
        if (k == 0)
            score += 0;
        else if (k == 1)
            score += 10;
        else
            score += 20;
        //符号
        int k1 = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 0x21 && str[i] <= 0x2F || str[i] >= 0x3A && str[i] <= 0x40 && str[i] >= 0x5B && str[i] <= 0x60 || str[i] >= 0x7B && str[i] <= 0x7E)
                k1++;
        }
        if (k1 == 0)
            score += 0;
        else if (k1 == 1)
            score += 10;
        else
            score += 25;
        //奖励
        if (up == true && low == true && k >= 1 && k1 >= 1)
            score += 5;
        else if ((up == false && low == true) || (up == true && low == false) && k >= 1 && k1 >> 1)
            score += 3;
        else if ((up == false && low == true) || (up == true && low == false) && k >= 1)
            score += 2;

        //输出
        if (score >= 90)
            cout << "VERY_SECURE" << endl;
        else if (score >= 80)
            cout << "SECURE" << endl;
        else if (score >= 70)
            cout << "VERY_STRONG" << endl;
        else if (score >= 60)
            cout << "STRONG" << endl;
        else if (score >= 50)
            cout << "AVERAGE" << endl;
        else if (score >= 25)
            cout << "WEAK" << endl;
        else if (score >= 0)
            cout << "VERY_WEAK" << endl;
    }

    return 0;
}