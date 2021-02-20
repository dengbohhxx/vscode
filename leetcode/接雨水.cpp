/*
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            int l_max=0;int r_max=0;
            for(int j=i;j<n;j++)
            {
                r_max=max(r_max,height[j]);
            }
            for(int j=i;j>=0;j--)
            {
                l_max=max(l_max,height[j]);
            }
            res+=min(l_max,r_max)-height[i];
        }
        return res;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
            return 0;
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        lmax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            lmax[i]=max(height[i],lmax[i-1]);
        }
        rmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rmax[i]=max(height[i],rmax[i+1]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans+=min(lmax[i],rmax[i])-height[i];
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
            return 0;
        int ans=0;
        int current=0;
        stack<int> stk;
        while(current<n)
        {
            while(!stk.empty()&&height[current]>height[stk.top()])
            {
                int top=stk.top();
                stk.pop();
                if(stk.empty())
                    break;
                int distance=current-stk.top()-1;
                int bounded_height=min(height[current],height[stk.top()])-height[top];
                ans+=distance*bounded_height;
            }
            stk.push(current);
            current++;
        }
        return ans;     
    }
};
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
            return 0;
        int left=0;
        int right=n-1;
        int lmax=height[0];
        int rmax=height[n-1];
        int ans=0;
        while(left<=right)
        {
            lmax=max(lmax,height[left]);
            rmax=max(rmax,height[right]);
            if(lmax<rmax)
            {
                ans+=lmax-height[left];
                left++;
            }
            else
            {
                ans+=rmax-height[right];
                right--;
            }
        }
        return ans;
    }
};