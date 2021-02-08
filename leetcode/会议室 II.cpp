class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> start;
        vector<int> end;
        for(int i=0;i<n;i++)
        {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0;int j=0;
        int count=0;
        int res=0;
        while(i<n)
        {
            if(start[i]<end[j])
            {
                count++;
                i++;
                res=max(res,count);
            }
            else if(start[i]>end[j])
            {
                count--;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return res;
    }
};