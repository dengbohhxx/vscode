#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
vector<int>matmut(vector<int> mat1,vector<int> mat2)
{
    int m1=mat1[0];
    int m2=mat1[1];
    int m3=mat2[1];
    vector<int> vec;
    vec.push_back(m1);
    vec.push_back(m3);
    vec.push_back(m1*m2*m3);
    return vec;
}
int main()
{
    int num=0;
    while(cin>>num)
    {
        vector<vector<int> > vec;
        vector<int> row;
        while(num--)
        {
            int m=0;
            int n=0;
            cin>>m>>n;
            row.push_back(m);
            row.push_back(n);
            vec.push_back(row);
            row.clear();
        }
        string str;
        cin>>str;
        stack<char> sta;
        int sum=0;
        if(str.size()==0)
            return sum;
        int len=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]!='('&&str[i]!=')')
                len++;
        }
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==')')
            {
                int idx2=sta.top()-'A';
                sta.pop();
                int idx1=sta.top()-'A';
                sta.pop();
                vector<int> mat1=vec[idx1];
                vector<int> mat2=vec[idx2];
                vector<int>mat=matmut(mat1,mat2);
                vector<int> mat3(2);
                mat3[0]=mat[0];
                mat3[1]=mat[1];
                vec.push_back(mat3);
                sum+=mat[2];
                sta.pop();
                if(sta.empty())
                    break;
                sta.push('A'+len);
                len++;
            }
            else
            {
                sta.push(str[i]);
            }
            
            
        }
        cout<<sum<<endl;
    }
    return 0;
}