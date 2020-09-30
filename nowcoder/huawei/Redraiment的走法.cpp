#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n = 0;
    while (cin >> n)
    {
        int num = 0;
        vector<int> vec;
        while (n--)
        {
            cin >> num;
            vec.push_back(num);
        }
        int size = vec.size();
        vector<int> dp(size);
        dp[0]=1;
        for (int i = 1; i < vec.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (vec[i] > vec[j])
                {
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i] ++;
        }
        cout<<*max_element(dp.begin(), dp.end())<<endl;
    }
    return 0;
}