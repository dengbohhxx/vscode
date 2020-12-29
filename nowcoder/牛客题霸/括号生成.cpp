class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    void backtrace(int left,int right,vector<string> &vec,string &str)//可用左括号为left。可用右括号为right
    {
        if(left<0||right<0)
            return;
        if(right<left)
            return;
        if(left==0&&right==0)
        {
            vec.push_back(str);
            return;
        }
        str.push_back('(');
        backtrace(left-1,right,vec,str);
        str.pop_back();
        
        str.push_back(')');
        backtrace(left,right-1,vec,str);
        str.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        // write code here
        vector<string> vec;
        if(n==0)
            return vec;
        string str;
        backtrace(n,n,vec,str);
        return vec;
    }
};