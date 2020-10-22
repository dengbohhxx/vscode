#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
    string a[] = {"#", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s;
    while (cin >> s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A'&& s[i] <= 'Z')
            {
                s[i] = s[i]+33;
                if(s[i]>'z')
                {
                    s[i]=s[i]-'z'+'a'-1;
                }
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                for (int j= 0; j < 10; j++)
                {
                    if (a[j].find(s[i]) != string::npos)
                    {
                        s[i] = '0' + j;
                        break;
                    }
                }
            }
            else
            {
                /* code */
            }
            
        }
        cout << s << endl;
    }
    return 0;
}