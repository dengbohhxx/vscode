#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isnum(char c)
{
    if ((c - '0') >= 0 && (c - '0') <= 9)
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
        string s;
        for (int i = 0; i < str.size(); i++)
        {
            if (!isnum(str[i]))
            {
                s = s + str[i];
            }
            else
            {
                s = s + '*';
                s = s + str[i];
                s = s + '*';
            }
        }
        string::size_type pos = 0;
        while ((pos = s.find("**")) != string::npos)
        {
            s.erase(pos, 2);
        }
        cout<<s<<endl;
    }
    return 0;
}