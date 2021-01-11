class Solution {
public:
    /**
     * 栈排序
     * @param a int整型一维数组 描述入栈顺序
     * @param aLen int a数组长度
     * @return int整型vector
     */
    vector<int> solve(int* a, int aLen) {
        // write code here
        vector<int> vec;
        vector<int> rmax(aLen,0);//数组rmax[i]表示第 i 项到第 n 项的数的最大值
        stack<int> stk;
        if(aLen==0)
            return vec;
        int maxval=INT_MIN;
        for(int i=aLen-1;i>=0;i--)
        {
            maxval=max(a[i],maxval);
            rmax[i]=maxval;
        }
        for(int i=0;i<aLen;i++)
        {
            stk.push(a[i]);
            while(!stk.empty()&&stk.top()>=rmax[i+1])//如果栈顶元索大于第i项到第n项的最大值，那么直接让这个元索出栈，让大的先出栈总能保证字典序最大。
            {
                vec.push_back(stk.top());
                stk.pop();
            }
        }
        while(!stk.empty())
        {
            vec.push_back(stk.top());
            stk.pop();
        }
        return vec;
    }
};