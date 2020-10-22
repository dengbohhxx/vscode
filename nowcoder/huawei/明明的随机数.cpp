#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    int num = 0;
    while (cin >> n)
    {
        vector<vector<int>> vec(1001, vector<int>());
        while (n--)
        {
            cin >> num;
            vec[num].push_back(num);
        }
        for (int i = 1; i <= 1000; i++)
        {
            if (!vec[i].empty())
                cout << vec[i][0] << endl;
        }
    }

    return 0;
}