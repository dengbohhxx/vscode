#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    bool IsContinuous( vector<int> numbers ) {
        int size=numbers.size();
        if(size<5)
            return false;
        sort(numbers.begin(),numbers.end());
        int czero=0;
        for(int i=0;i<size;i++)
        {
            if(numbers[i]==0)
                czero++;
        }
        for(int i=czero+1;i<size;i++)
        {
            if(numbers[i]==numbers[i-1])
                return false;
        }
        int cgap=0;
        for(int i=czero+1;i<size;i++)
        {
            if(numbers[i]-numbers[i-1]!=1)
                cgap+=numbers[i]-numbers[i-1]-1;
        }
        if(cgap<=czero)
            return true;
        else
            return false;
    }
int main()
{
    int a[]={0,3,2,6,4};
    vector<int> vec(a,a+5);
    bool res=IsContinuous(vec);
    cout<<res<<endl;
}