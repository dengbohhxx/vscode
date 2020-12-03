class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     class Solution {
public:

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
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        map<int,int> a;
        vector<int> vec;
        for(int i=0;i<numbers.size();i++)
        {
            if(a.count(target-numbers[i])>0)
            {
                vec.push_back(a[target-numbers[i]]+1);
                vec.push_back(i+1);
                break;
            }
            a.insert(map<int,int>::value_type(numbers[i],i));
        }
        return vec;
            
    }
};