class Solution {
public:
    static bool cmp(int &x,int &y)
    {
        return x>y;
    }
    int leastInterval(vector<char>& tasks, int n) {
        int l=tasks.size();
        vector<int> vec(26,0);
        for(int i=0;i<l;i++)
        {
            vec[tasks[i]-'A']++;
        }
        sort(vec.begin(),vec.end(),cmp);
        int count=1;
        while(count<vec.size()&&vec[count]==vec[0])
            count++;
        return max(l,count+(n+1)*(vec[0]-1));

    }
};