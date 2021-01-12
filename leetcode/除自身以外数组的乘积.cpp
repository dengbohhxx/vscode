#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> vec;
    int n = nums.size();
    if (n == 0)
        return vec;
    vector<int> prefix(n, 0);
    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp *= nums[i];
        prefix[i ] = temp;
    }
    vector<int> lastfix(n, 0);
    temp = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        temp *= nums[i];
        lastfix[i] = temp;
    }
    int i = 0;
    while (i < n)
    {
        if (i == 0)
        {
            vec.push_back(lastfix[i + 1]);
        }
        else if (i == n - 1)
        {
            vec.push_back(prefix[i - 1]);
        }
        else
        {
            vec.push_back(prefix[i - 1] * lastfix[i + 1]);
        }
        i++;
    }
    return vec;
}
int main()
{
    vector<int> vec={1,2,3,4};
    auto res= productExceptSelf(vec);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }



    return 0;
}