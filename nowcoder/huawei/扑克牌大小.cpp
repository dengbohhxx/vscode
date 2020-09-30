#include <iostream>
#include <vector>
#include <string>
using namespace std;
int count(string s)
{
    int pos = 0;
    int count = 0;
    while ((pos = s.find(" ", pos)) != string::npos)
    {
        pos++;
        count++;
    }
    return count;
}
int main()
{
    string tb = "345678910JQKA2jokerJOKER";
    string s;
    while (getline(cin, s))
    {
        int pos = s.find('-');
        string s1(s.begin(), s.begin() + pos);
        string s2(s.begin() + pos + 1, s.end());
        int c1 = count(s1);
        int c2 = count(s2);
        if(c1!=c2)
        {
            if(s1=="joker JOKER"||s2=="joker JOKER")
            {
                cout<<"joker JOKER"<<endl;
            }
            else if(c1==3)
                cout<<s1<<endl;
            else  if(c2==3)
                cout<<s2<<endl;
            else
            {
                cout<<"ERROR"<<  endl;
            }
        }
        else
        {
            int i1=tb.find(s1[0]);
            int i2=tb.find(s2[0]);
            if(i1<i2)
            {
                cout<<s2<<endl;
            }
            else
            {
                cout<<s1<<endl;
            }
        }
    }

    return 0;
}