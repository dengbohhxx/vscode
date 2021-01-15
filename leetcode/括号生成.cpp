class Solution {
public:
    void backtrace(int left,int right,vector<string> &vec,string &str)
    {
        if(left==0&&right==0)
        {
            vec.push_back(str);
            return;
        }
        if(left<0||right<0)
        {
            return;
        }
        if(right<left)
        {
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
        vector<string> vec;
        if(n==0)
            return vec;
        string str;
        backtrace(n,n,vec,str);
        return vec;
    }
};