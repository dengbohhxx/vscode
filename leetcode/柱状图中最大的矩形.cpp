/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for (int mid = 0; mid < n; ++mid) {
            // 枚举高
            int height = heights[mid];
            int left = mid, right = mid;
            // 确定左右边界
            while (left - 1 >= 0 && heights[left - 1] >= height) {
                --left;
            }
            while (right + 1 < n && heights[right + 1] >= height) {
                ++right;
            }
            // 计算面积
            ans = max(ans, (right - left + 1) * height);
        }
        return ans;
    }
};
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> s1;
        for(int i=n-1;i>=0;i--)//找出左边最近的，比他小的柱形的下标
        {
            while(!s1.empty()&&heights[i]<=heights[s1.top()])
            {
                s1.pop();
            }
            right[i]=s1.empty()?-1:s1.top();
            s1.push(i);
        }
        stack<int> s2;
        for(int i=0;i<n;i++)//找出右边最近的，比他小的柱形的下标
        {
            while(!s2.empty()&&heights[i]<=heights[s2.top()])
            {
                s2.pop();
            }
            left[i]=s2.empty()?-1:s2.top();
            s2.push(i);
        }
        int aera=0;
        for(int i=0;i<n;i++)
        {
            right[i]=right[i]==-1?n:right[i];
            aera=max(aera,heights[i]*(right[i]-left[i]-1));
        }
        return aera;
    }
};