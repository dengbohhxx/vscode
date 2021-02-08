class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int count=1;
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            int start=intervals[i][0];
            if(start>=end)
            {
                count++;
                end=intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
};