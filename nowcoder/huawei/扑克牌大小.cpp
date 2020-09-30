#include <iostream>
#include <vector>
#include <string>
using namespace std;
int transform(string str)
{
    if (str == "3")
        return 1;
    else if (str == "4")
        return 2;
    else if (str == "5")
        return 3;
    else if (str == "6")
        return 4;
    else if (str == "7")
        return 5;
    else if (str == "8")
        return 6;
    else if (str == "9")
        return 7;
    else if (str == "10")
        return 8;
    else if (str == "J")
        return 9;
    else if (str == "Q")
        return 10;
    else if (str == "K")
        return 11;
    else if (str == "A")
        return 12;
    else if (str == "2")
        return 13;
    else if (str == "joker")
        return 14;
    else if (str == "JOKER")
        return 15;
}
vector<int> strtovec(string s)
{
    vector<int> vec;
    int f = 0;
    int l = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            l++;
        }
        else
        {
            string str(s.begin() + f, s.begin() + l);
            int a = transform(str);
            vec.push_back(a);
            l++;
            f = l;
        }
    }
    return vec;
}
void print(vector<int> s)
{
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
    cout << "------------------------" << endl;
}
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
    string tb = "345678910JQKjokerJOKER";
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
            int i2=tb.find(s1[0]);
            if(i1<i2)
            {
                cout<<s1<<endl;
            }
            else
            {
                cout<<s2<<endl;
            }
        }
    }

    return 0;
}