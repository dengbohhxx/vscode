class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param str string字符串 待判断的字符串
     * @return bool布尔型
     */
    bool reverse(string str,int start,int end)
    {
        int i=start;
        int j=end;
        
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool judge(string str) {
        // write code here
        int size=str.size();
        if(size==0||size==1)
            return true;
        bool res=reverse(str,0,size-1);
        return res;
    }
};