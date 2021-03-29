class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]<b[0])
            return true;
        else if(a[0]==b[0]&&a[1]>b[1])
            return true;
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        int n=people.size();
        vector<vector<int> > res(n);
        for(int j=0;j<n;j++)
        {
            int spaces=people[j][1]+1;
            for(int i=0;i<n;i++)
            {
                if(res[i].empty())
                {
                    spaces--;
                    if(spaces==0)
                    {
                        res[i]=people[j];
                        break;
                    }
                }
            }
        }
        return res;

    }
};