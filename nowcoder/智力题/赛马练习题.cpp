class HorseRace {
public:
    int winMost(vector<int> oppo, vector<int> horses, int n) {
        // write code here
        sort(horses.begin(),horses.end());
        int l=0;
        int r=n-1;
        int ret=0;
        sort(oppo.begin(),oppo.end());
        for(int i=n-1;i>=0;i--)
        {
            if(horses[r]>oppo[i])
            {
                ret++;
                r--;
            }
        }
        return ret;
    }
};