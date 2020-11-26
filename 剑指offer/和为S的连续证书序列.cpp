class Solution {
public:
    int sum1(int start,int end)
    {
        int total=0;
        for(int i=start;i<=end;i++)
        {
            total+=i;
        }
        return total;
        
    }
    vector<vector<int> > FindContinuousSequence(int sum) 
    {
        vector<vector<int> > vec;
        if(sum<=2)
            return vec;
        vector<int> num;
        int small=1;
        int big=2;
        int middle=sum/2;
        while(small<=middle)
        {
            if(sum1(small,big)==sum)
            {
                for(int i=small;i<=big;i++)
                {
                    num.push_back(i);
                }
                vec.push_back(num);
                num.clear();
                big++;
                continue;
            }
            else if(sum1(small,big)<sum)
            {
                big++;
            }
            else
            {
                small++;
            }
        }
        return vec;
    }
};