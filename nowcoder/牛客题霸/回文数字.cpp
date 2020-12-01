#include<iostream>
#include<string>
using namespace std;
bool huiwen(string str)
    {
        bool res=true;
        int i=0;
        int j=str.size()-1;
        while(i<j)
        {
            if(str[i]!=str[j])
            {
                res=false;
                break;
            }
            else
            {
                i++;
                j--;
            }
        }
        return res;
    }
    bool isPalindrome(int x) {
    
        if(x<0)
            return false;
        bool res=huiwen(to_string(x));
        return res;
    }
int main()
{
 bool res= isPalindrome(0);
 cout<<res<<endl;



    return 0;
}