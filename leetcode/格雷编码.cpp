class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> vec;
        vec.push_back(0);
        for(int i=0;i<n;i++)
        {
            int add=1<<i;
            for(int j=vec.size()-1;j>=0;j--)
            {
                vec.push_back(vec[j]+add);
            }
        }
        return vec;
    }
};