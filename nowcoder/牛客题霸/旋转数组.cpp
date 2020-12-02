class Solution {
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    void reverse(vector<int> & vec,int start,int end)
    {
        int i=start;
        int j=end;
        while(i<j)
        {
            swap(vec[i],vec[j]);
            i++;
            j--;
        }
    }
    vector<int> solve(int n, int m, vector<int>& a) {
        // write code here
        m=m%n;
        if(m==0)
            return a;
        int left=0;
        int right=n;
        int index=right-m;
        reverse(a,left,right-m-1);
        reverse(a,right-m,right-1);
        reverse(a,left,right-1);
        return a;
    }
};