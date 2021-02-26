class Solution {
public:
    string waiguan(string str)
    {
        int n=str.size();
        string s;
        for(int i=0;i<n;i++)
        {
            int temp=str[i];
            int k=1;
            for(int j=i+1;j<n;j++)
            {
                if(temp==str[j])
                {
                    k++;
                }
                else
                {
                    break;
                }
            }
            s+=to_string(k);
            s+=str[i];
            i=i+k-1;
        }
        return s;
    }
    string countAndSay(int n) {
        string str="1";
        for(int i=1;i<n;i++)
        {
            str=waiguan(str);
        }
        return str;
    }
};