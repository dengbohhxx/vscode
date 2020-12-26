class Solution {
public:
    
    bool ismatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                    //一个是*号代表空序列的话，则比较的s的前i个元素和p的前j-1个元素的关系，
                    //即dp[i][j-1]的值。当*代表的不是空序列的话，比较的是s[:i-1]与p[:j]是否相同，如果相同不管s[i-1]最后是什么字符都不会有影响

                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
    bool isMatch(const char *s, const char *p) {
        string s1(s);
        string s2(p);
        return ismatch(s1,s2);
    }
};