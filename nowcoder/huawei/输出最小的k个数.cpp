#include<iostream>
#include<vector>
using namespace std;
void heap(vector<int> &vec,int len,int index)
{
    int minidx=index;
    while(index<len)
    {
        int left=2*index+1;
        int right=2*index+2;
        if(left<len&&vec[left]<vec[minidx])
            minidx=left;
        if(right<len&&vec[right]<vec[minidx])
            minidx=right;
        if(minidx!=index)
        {
            swap(vec[minidx],vec[index]);
            index=minidx;
        }
        else
        {
            break;
        }
    }
}
int main()
{
    int n=0;
    int k=0;
    while(cin>>n>>k)
    {
        vector<int> vec;
        int num=0;
        int m=n;
        while(n--)
        {
            cin>>num;
            vec.push_back(num);
        }
        
        for(int i=m/2-1;i>=0;i--)
        {
            heap(vec,m,i);
        }
        vector<int> res;
        int s=0;
        for(int i=m-1;i>0;i--)
        {
            if(s!=k)
            {
                res.push_back(vec[0]);
                s++;
                swap(vec[0],vec[i]);
                heap(vec,i,0);
            }
        }
        cout<<res[0];
        for(int i=1;i<k;i++)
        {
            cout<<" "<<res[i];
        }
        cout<<endl;
    }
    return 0;
}