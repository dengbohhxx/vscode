class Solution {
public:
    /**
     * 返回一个严格四舍五入保留两位小数的字符串
     * @param n int整型 n
     * @return string字符串
     */
    string Probability(int n)
{
    // write code here0
    float m = 2 / pow(2, n);
    string str = to_string(m);
    int k = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            k = i;
            break;
        }
    }

    int jw = 0;
    if (str[k + 3] - '0' >= 5)
        jw = 1;
    for (int i = k + 2; i >= 0; i--)
    {
        if (str[i] == '.')
            continue;
        if (jw == 1)
        {
            if (str[i] - '0' + jw == 10)
            {
                str[i] = '0';
                jw = 1;
            }
            else
            {
                str[i] = str[i] + 1;
                jw = 0;
            }
        }
    }
    string s(str.begin(),str.begin()+k+3);
    return s;
}
};
class Solution {
public:
    /**
     * 返回一个严格四舍五入保留两位小数的字符串
     * @param n int整型 n
     * @return string字符串
     */
    string Probability(int n) {
        // write code here
        double m=2/pow(2,n);
        int zhengshu=int(m);
        m=m+0.005;
        string str=to_string(zhengshu)+".";
        for(int i=0;i<2;i++)
        {
            m=m*10;
            str+=to_string(int(m)%10);
        }
        return str;
    }
};