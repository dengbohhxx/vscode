#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> vec)
{
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "++++++++++++++" << endl;
}
int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec(a, a + 10);
    print(vec);
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end();)
    {
        if (*iter == 7)
            iter = vec.erase(iter);
        else
        {
            iter++;
        }
    }
    print(vec);
    return 0;
}
