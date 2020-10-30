#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while (getline(cin,str))
    {
        int k = 0;
        int k1 = 0;
        int k2 = 0;
        int k3 = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
                k++;
            else if (str[i] >= '0' && str[i] <= '9')
                k2++;
            else if (str[i] == ' ')
                k1++;
            else
                k3++;
        }
        cout << k << endl;
        cout << k1 << endl;
        cout << k2 << endl;
        cout << k3 << endl;
    }

    return 0;
}