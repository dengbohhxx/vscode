class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> res(n+1,0);
        for(int i=0;i<n;i++)
        {
            res[i+1]=digits[i];
        }
        res[n]++;
        int flag=0;
        for(int i=n;i>=0;i--)
        {
            int temp=res[i]+flag;
            flag=(temp)/10;
            res[i]=(temp)%10;
        }
        if(res[0]==0)
            {
                vector<int> vec(res.begin()+1,res.end());
                return vec;
            }
        return res;
    }
};