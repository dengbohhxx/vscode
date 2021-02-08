class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > vec(n,vector<int>(n,0));
        int left=0;
        int right=n-1;
        int top=0;
        int btm=n-1;
        int k=1;
        while(left <= right && top <= btm){             // 循环条件：
            // 圈的第一步
            for(int i=left;i<=right;++i)                // 第一步循环条件
                {
                    vec[top][i]=k;
                    k++;
                }      
            // 圈的第二步
            if(top<btm)                                 // 第二步边界条件
                for(int i=top+1;i<=btm;++i)             // 第二步循环条件
                    {
                        vec[i][right]=k;
                        k++;  
                    }
                     // 第二步坐标
            // 圈的第三步
            if(top<btm && left<right)                   // 第三步边界条件
                for(int i=right-1;i>=left;--i)          // 第三步循环条件
                    {
                        vec[btm][i]=k;
                        k++;
                    }  // 第三步坐标
            // 圈的第四步
            if(top+1<btm && left<right)                 // 第四步边界条件
                for(int i=btm-1;i>=top+1;--i)           // 第四步循环条件
                    {
                        vec[i][left]=k;
                        k++;
                    } // 第四步坐标

            ++left;--right;++top;--btm;
        }
        return vec;
    }
};