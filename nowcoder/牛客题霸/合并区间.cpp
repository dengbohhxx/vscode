/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval &a,Interval &b)
{
   return a.start<b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> merged;
        if(intervals.size()==0)
            return merged;
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<intervals.size();i++)
        {
            int l=intervals[i].start;
            int r=intervals[i].end;
            if(merged.size()==0||merged.back().end<l)
            {
                merged.push_back(intervals[i]);
            }
            else
            {
                merged.back().end=max(merged.back().end,r);
            }
        }
        return merged;
    }
};