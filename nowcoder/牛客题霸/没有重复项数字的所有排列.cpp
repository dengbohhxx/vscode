#include<iostream>
#include<string>
#include<vector>
using namespace std;
void dfs(vector<int>num,int start,int end,vector<int> &row,vector<vector<int> > &vec,vector<bool> &used)
    {
        if(start==end)
        {
            vec.push_back(row);
            return;
        }
        for(int i=0;i<num.size();i++)
        {
                if(used[i]==false)
                {
                    used[i]=true;
                    row.push_back(num[i]);
                    dfs(num,start+1,end,row,vec,used);
                    row.pop_back();
                    used[i]=false;
                }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        int size=num.size();
        vector<int> row;
        vector<vector<int> > vec;
        vector<bool> used(size,false);
        if(size==0)
            return vec;
        dfs(num,0,size,row,vec,used);
        return vec;
    }
    int main()
    {
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        auto vec1=permute(vec);




        return 0;
    }