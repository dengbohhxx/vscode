#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string str;
    vector<vector<char>> vec(256);
    while (cin >> str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            vec[str[i] - NULL].push_back(str[i]);
        }
        string result;
        char c;
        while (true)
        {
            int max = 0;
            int indix=0;
            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i].size() > max)
                {
                    max=vec[i].size() ;
                    c = vec[i][0];
                    indix=i;

                }
            }
            if (max != 0)
            {
                result = result + c;
                vec[indix].clear();
            }
            else
            {
                break;
            }
        }
        cout<<result<<endl;
    }

    return 0;
}