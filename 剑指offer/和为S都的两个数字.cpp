class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> vec;
        int size=array.size();
        if(size<=1)
            return vec;
        int start=0;
        int end=size-1;
        int cursum=0;
        int mint=INT_MAX;
        while(start<end)
        {
            cursum=array[start]+array[end];
            if(cursum==sum)
            {
                /*if(array[start]*array[end]<=mint)
                {
                    mint=array[start]*array[end];
                    vec.clear();
                    vec[0]=array[start];
                    vec[1]=array[end];
                }*/
                vec.push_back(array[start]);
                vec.push_back(array[end]);
                break;
            }
            else if(cursum>sum)
                end--;
            else
                start++;
        }
        return vec;
    }
};