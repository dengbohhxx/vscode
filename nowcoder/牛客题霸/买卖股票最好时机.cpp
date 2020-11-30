class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        int size=prices.size();
        int m=0;
        for(int i=1;i<size;i++)
        {
            
            for(int j=0;j<i;j++)
            {
                if(prices[i]>prices[j])
                {
                    int profit=prices[i]-prices[j];
                    m=max(m,profit);
                }
            }
        }
        return m;
    }
};