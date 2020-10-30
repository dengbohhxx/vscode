#include <bits/stdc++.h>
using namespace std;
//判断一个数是否为素数
bool IsPrimer(int n)
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
//匈牙利算法，为某一个目标奇数找到它的素数伴侣（偶数）,皆以下标表示
bool FindMate(const int n, vector<vector<bool>>& map, vector<int>& match, vector<bool> &vis)
{
    for (int i = 0; i < match.size(); i++)
    {
        if (!vis[i] && map[i][n])//偶数未被访问过并且能与目标奇数组成素数（有关系）
        {
            vis[i] = true;
            if (match[i] == -1 || FindMate(match[i], map, match, vis))//当前偶数没有匹配或能给被抛弃的奇数找到新的偶数
            {
                match[i] = n;//找到这个偶数
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int num = 0;
    while (cin >> num)
    {
        int count = 0;//匹配对数
        vector<int> even;//偶数
        vector<int> odd;//奇数
        int val = 0;
        //读取数据
        while (num--)
        {
            cin >> val;
            if (val % 2 == 0)
            {
                odd.push_back(val);
            }
            else
            {
                even.push_back(val);
            }
        }
        if (odd.empty() || even.empty())
        {
            cout << count << endl;
            continue;
        }
        //建立关系表，图中的边
        vector<vector<bool>> map(even.size(), vector<bool>(odd.size(), false));
        for (int i = 0; i < even.size(); i++)
        {
            for (int j = 0; j < odd.size(); j++)
            {
                if (IsPrimer(even[i] + odd[j]))
                {
                    map[i][j] = true;
                }
            }
        }
        //建立初始匹配表
        vector<int> match(even.size(), -1);    
        //为每一个奇数都尝试去找对应的偶数，    
        for (int i = 0; i < odd.size(); i++)
        {
            vector<bool> vis(even.size(), false);//每一次查找都相当于重新分配，标志要清零
            if (FindMate(i, map, match, vis))
            {
                count++;
            }
        }
        cout << count << endl;
    }
}
