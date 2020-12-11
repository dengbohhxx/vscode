class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> sta;
        vector<int> vec(T.size());
        for(int i=T.size()-1;i>=0;i--)
        {
            while(!sta.empty()&&T[i]>=T[sta.top()])
                sta.pop();
            vec[i]=sta.empty()?0:(sta.top()-i);
            sta.push(i);
        }
        return vec;
    }
};