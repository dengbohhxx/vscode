class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t flag=1;
        int count=0;
        while(flag>0)
        {
            if((flag&n)!=0)
            {
                count++;
            }
            flag=flag<<1;
        }
        return count;
    }
};