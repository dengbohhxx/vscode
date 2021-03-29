class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b)
    {
        if(a[0]<b[0])
            return true;
        else if(a[0]==b[0]&&a[1]<b[1])
            return  true;
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > vec;
        vector<int> row(2);
        intervals.push_back(newInterval);
        int n=intervals.size();
        if(n==0||n==1)
            return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        int l=intervals[0][0];
        int r=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=r)
            {
                l=min(l,intervals[i][0]);
                r=max(r,intervals[i][1]);
                if(i==n-1)
                {
                    row[0]=l;
                    row[1]=r;
                    vec.push_back(row);
                }
            }
            else
            {
                row[0]=l;
                row[1]=r;
                vec.push_back(row);
                l=intervals[i][0];
                 r=intervals[i][1];
                 if(i==n-1)
                 {
                     vec.push_back(intervals[i]);
                 }
            }
           // l=intervals[i][0];
            //r=intervals[i][1];
        }
        return vec;
    }
};