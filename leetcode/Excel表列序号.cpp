class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            int num=columnTitle[i]-'A'+1;
            res=res*26+num;
        }
        return res;

    }
};