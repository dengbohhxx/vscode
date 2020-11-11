class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        vector<int> vec(2);
        int size=numbers.size();
        for(int i=0;i<size-1;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(target==numbers[i]+numbers[j])
                {
                    vec[0]=i+1;
                    vec[1]=j+1;
                }
            }
        }
        return vec;
    }
};