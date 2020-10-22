#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    while (cin >> n)
    {
        int start = 2;
        int sum = 2;
        for (int i = 1; i < n; i++)
        {
            start = start + 3;
            sum = sum + start;
        }
        cout << sum << endl;
    }


    return 0;
}