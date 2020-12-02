class Solution {
public:
    /**
     * 进制转换
     * @param M int整型 给定整数
     * @param N int整型 转换到的进制
     * @return string字符串
     */
    string solve(int M, int N) {
        // write code here
        string str;
        string s={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        if(M>=0)
        {
            while(M!=0)
            {
                int yushu=M%N;
                M=M/N;
                str+=s[yushu];
            }
            reverse(str.begin(),str.end());
        }
        else
        {
            M=0-M;
            while(M!=0)
            {
                int yushu=M%N;
                M=M/N;
                str+=s[yushu];
            }
            str+='-';
            reverse(str.begin(),str.end());
        }
        return str;
    }
};