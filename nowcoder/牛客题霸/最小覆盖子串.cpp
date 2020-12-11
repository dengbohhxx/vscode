#include <unordered_map>
class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    string minWindow(string S, string T) {
        // write code here
         // 记录最短子串的开始位置和长度
        int start=0;
        int minlen=INT_MAX;
        int left=0;
        int right=0;
        // 记录 window 中已经有多少字符符合要求了
        int match=0;
        // 相当于两个计数器
        unordered_map<char,int> window;
        unordered_map<char,int> need;
        for(int i=0;i<T.size();i++)
            need[T[i]]++;
        while(right<S.size())
        {
            char c1=S[right];
             // 加入 window
            if(need.count(c1)>0)
            {
                window[c1]++;
              // 字符 c1 的出现次数符合要求了
                if(window[c1]==need[c1])
                    match++;
            }
            right++;
            // window 中的字符串已符合 needs 的要求了
            while(match==need.size())
            {
                // 更新结果 res
                if(right-left<minlen)
                {
                // 更新最小子串的位置和长度
                    start=left;
                    minlen=right-left;
                }
                
                char c2=S[left];
                if(need.count(c2)>0)
                {
                    window[c2]--;// 移出 window
                    if(window[c2]<need[c2])
                        match--;// 字符 c2 出现次数不再符合要求
                }
                left++;
            }
        }
        return minlen==INT_MAX?"":S.substr(start,minlen);
    }
};