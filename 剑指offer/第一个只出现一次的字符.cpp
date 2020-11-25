class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int n=-1;
        vector<int> hash(256,0);
        for(int i=0;i<str.size();i++)
        {
            hash[str[i]-NULL]+=1;
        }
        for(int i=0;i<str.size();i++)
        {
            if(hash[str[i]-NULL]==1)
            {
                n=i;
                break;
            }
        }
        return n;
         
    }
};