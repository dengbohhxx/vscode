#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(int idx,int currentnum,vector<int> vec,bool &res)
{
    if(currentnum==24)
    {
        res=true;
        return;
    }
    else if(res==true||currentnum>24||idx>=4)
        return;
    else
    {
        for(int operflag=0;operflag<4;operflag++)
        {
            switch(operflag)
            {
                case 0:
                    dfs(idx+1,currentnum+vec[idx],vec,res);
                    break;
                case 1:
                    dfs(idx+1,currentnum-vec[idx],vec,res);
                    break;
                case 2:
                    dfs(idx+1,currentnum*vec[idx],vec,res);
                    break;
                case 3:
                    dfs(idx+1,currentnum/vec[idx],vec,res);
            }
            //if(res==true)
                //return ;
        }
    }
    
}
int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        vec.push_back(d);
        sort(vec.begin(),vec.end());
        bool res=false;
        do
        {
            dfs(1,vec[0],vec,res);
            if(res==true)
                break;
        }while(next_permutation(vec.begin(),vec.end()));
        if(res==true)
              cout<<"true"<<endl;
        else      
            cout<<"false"<<endl;
        
    }
    return 0;
}