#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> vec(n1 + n2, 0);
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i = 0; i < num2.size(); i++)
    {
        for (int j = 0; j < num1.size(); j++)
        {
            vec[i + j] += (num1[j] - '0') * (num2[i] - '0');
        }
    }
    int flag = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int temp=vec[i] + flag;
        flag = temp/ 10;
        vec[i] = temp% 10;
    }
    reverse(vec.begin(), vec.end());
    bool flag1 = false;
    string res;
    int i=0;
    for ( i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0 && flag1 == false)
            continue;
        if (vec[i] != 0)
        {
            flag1 = true;
        }
        res += to_string(vec[i]);
    }  
    if(i==vec.size()&&res.size()==0)
            return "0";
      return res;
}
int main()
{
    string str1="0";
    string str2="0";
    cout<<multiply(str1,str2)<<endl;
    return 0;
}