#include <iostream>
#include <vector>
using namespace std;
vector<int> LIS(vector<int> &arr)
{
    // write code here
    vector<int> res;
    vector<int> maxlen;
    int n = arr.size();
    if (n == 0 || n == 1)
        return arr;
    res.push_back(arr[0]);
    maxlen.push_back(1);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > res.back())
        {
            res.push_back(arr[i]);
            maxlen.push_back(res.size());
        }
        else
        {
            int l = 0;
            int r = res.size()-1 ;
            int pos = 0;
            while (l <= r)
            {
                int mid = (r + l) / 2;
                if (res[mid] < arr[i])
                {
                    pos = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            if(r==-1)
            {
                res[pos]=arr[i];
                maxlen.push_back(1);
            }
            else
            {
                res[pos+1 ] = arr[i];
                maxlen.push_back(pos + 2);
            }
           
        }
    }
    for (int i = arr.size() - 1, j = res.size(); j > 0; i--)
    {
        if (maxlen[i] == j)
        {
            j--;
            res[j] = arr[i];
        }
    }
    return res;
}
int main()
{
    int a[] = {2, 1, 5, 3, 6, 4, 8, 9, 7};
    vector<int> vec(a,a+9);
    auto res=LIS(vec);
    cout<<"123"<<endl;

    return 0;
}