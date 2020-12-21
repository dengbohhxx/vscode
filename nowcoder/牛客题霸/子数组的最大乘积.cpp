#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
double maxProduct(vector<double> arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        if(n==1)
            return arr[0];
        vector<double> dpmax(n);
        vector<double> dpmin(n);
        dpmax[0]=arr[0];
        dpmin[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            double ai=arr[i];
            if(ai>0)
            {
                dpmax[i]=max(ai,dpmax[i-1]*ai);
                dpmin[i]=min(ai,dpmin[i-1]*ai);
            }
            else if(ai<0)
            {
                dpmax[i]=max(ai,dpmin[i-1]*ai);
                dpmin[i]=min(ai,dpmax[i-1]*ai);
            }
            else
            {
                dpmax[i]=0;
                dpmin[i]=0;
            }
        }
        return *max_element(dpmax.begin(),dpmax.end());
}
int main()
{
    vector<double> vec;
    vec.push_back(0.5);
    vec.push_back(0.3);
    vec.push_back(4.0);
    cout<<maxProduct(vec)<<endl;




    return 0;
}
