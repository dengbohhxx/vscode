#include <iomanip> 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n=0;
    double num=0;
    while(cin>>n)
    {
        vector<int> p;
        vector<int> neg;
        while(n--)
        {
            cin>>num;
            if(num>0)
            {
                p.push_back(num);
            }
            else if(num<0)
            {
                neg.push_back(num);
            }
        }
        double sum=0;
        for(int i=0;i<p.size();i++)
        {
            sum+=p[i];
        }
        cout<<neg.size()<<" "<<fixed << setprecision(1) <<sum/p.size()<<endl;
    }
    
    
    
    
    
    
    return 0;
}