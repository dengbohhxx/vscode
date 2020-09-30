#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    
    int n ;
    while (cin >> n)
    {
         string str;
        vector<string> vec;
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            vec.push_back(str);
        }
        vector<string> vec1;
        for (int i = 0; i < vec.size(); i++)
        {
            int len = vec[i].size();
            int iter = len / 8;
            int f = 0;
            for (int j = 0; j < iter; j++)
            {
                string s(vec[i].begin() + f, vec[i].begin() + f + 8);
                vec1.push_back(s);
                f = f + 8;
            }
            string s1(vec[i].begin() + f, vec[i].end());
            if (len % 8)
            {
                int l = 8 - len % 8;
                for (int i = 0; i < l; i++)
                {
                    s1 = s1 + '0';
                }
                vec1.push_back(s1);
            }
        }
        for (int i = 0; i < vec1.size(); i++)
        {
            cout << vec1[i] << endl;
        }
    }
    return 0;
}