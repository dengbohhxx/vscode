#include <iostream>
#include <vector>
using namespace std;
bool perfect(int x)
{
    int k = 0;
    for (int i = 1; i < x; i++)
    {
        if (x % i == 0)
        {
            k += i;
        }
    }
    if (k == x)
        return true;
    else
    {
        return false;
    }
}
int main()
{
    int n = 0;
    while (cin >> n)
    {
        int k = 0;
        for (int i = 1; i <= n; i++)
        {
            if (perfect(i))
                k++;
        }
        cout << k << endl;
    }
    return 0;
}