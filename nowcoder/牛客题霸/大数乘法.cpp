#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string solve(string s, string t)
{
    // write code here
    if (s.empty() || t.empty())
        return "0";
    int len1 = s.size();
    int len2 = t.size();
    vector<int> str(len1 + len2, 0);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            str[i + j] += (t[i] - '0') * (s[j] - '0');
        }
    }
    for (int i = 0; i < len1 + len2; i++)
    {
        str[i + 1] += str[i] / 10;
        str[i] = str[i] % 10;
    }
    int i = 0;
    for (i = len1 + len2 - 1; i >= 0; i--)
    {
        if (str[i] != 0)
            break;
    }
    if (i == -1)
        return "0";
    string str1;
    for (int k = i; k >= 0; k--)
    {
        str1 = str1 + to_string(str[k]);
    }
    return str1;
}
int main()
{
    string str1("733064366");
    string str2("459309139");
    string str = solve(str1, str2);
    cout << str << endl;

    return 0;
}