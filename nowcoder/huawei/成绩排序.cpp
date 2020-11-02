#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;
struct student
{
    string name;
    int score;
    student(string str,int n):name(str),score(n){}
};
vector<student> upsort(vector<student> vec)
{
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<vec.size();i++)
    {
        if(max<=vec[i].score)
            max=vec[i].score;
        if(min>=vec[i].score)
            min=vec[i].score;
    }
    vector<vector<student> > temp(max-min+1);
    for(int i=0;i<vec.size();i++)
    {
        temp[vec[i].score-min].push_back(vec[i]);
    }
    vector<student> A;
    for(int i=0;i<temp.size();i++)
    {
        if(!temp[i].empty())
        {
            for(int j=0;j<temp[i].size();j++)
                A.push_back(temp[i][j]);
        }
    }
    return A;
}
vector<student> downsort(vector<student> vec)
{
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<vec.size();i++)
    {
        if(max<=vec[i].score)
            max=vec[i].score;
        if(min>=vec[i].score)
            min=vec[i].score;
    }
    vector<vector<student> > temp(max-min+1);
    for(int i=0;i<vec.size();i++)
    {
        temp[vec[i].score-min].push_back(vec[i]);
    }
    vector<student> A;
    for(int i=temp.size()-1;i>=0;i--)
    {
        if(!temp[i].empty())
        {
            for(int j=0;j<temp[i].size();j++)
                A.push_back(temp[i][j]);
        }
    }
    return A;
}
int main()
{
    int num=0;
    int flag=0;
    while(cin>>num>>flag)
    {
        string n;
        int s;
        vector<student> vec;
        for(int i=0;i<num;i++)
        {
            cin>>n>>s;
            student stu(n,s);
            vec.push_back(stu);
        }
        vector<student> res;
        if(flag==1)
        {
            res=upsort(vec);
        }
        else
        {
            res=downsort(vec);
        }
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i].name<<" "<<res[i].score<<endl;
        }
    }
    return 0;
}

