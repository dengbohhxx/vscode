#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
bool is8bitnum(string s)
{
    int num = 0;
    int size = s.size();
    if (s[0] == 0)
        return false;
    int n = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        num = num + (s[i] -'0')* pow(10, n++);
    }
    if (num >= 0 && num <= 255)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string str;
    while (cin >> str)
    {
        vector<string> vec;
        int f = 0;
        int l = 0;
        str = str + '.';
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '.')
            {
                string s(str.begin() + f, str.begin() + l);
                vec.push_back(s);
                f = i + 1;
                l++;
            }
            else
            {
                l++;
            }
        }
        bool flag = true;
        for (int i = 0; i < vec.size(); i++)
        {
            if (!is8bitnum(vec[i]))
            {
                flag = false;
                break;
            }
        }
        if(flag==true)
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}