#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        s=s+" ";
        vector<string> vec;
        int k = s.size();
        string temp = "";
        for (int i = 0; i < k; i++)
        {
            if (s[i] >= 'A'&& s[i] <= 'Z' || s[i] >= 'a'&& s[i] <= 'z')
            {
                temp += s[i];
            }
            else
            {
                if (temp.size() > 0)
                {
                    vec.push_back(temp);
                    temp = "";
                }
            }
        }

        int size = vec.size();
        cout << vec[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            cout << " " << vec[i];
        }
        cout << endl;
    }
    return 0;
}