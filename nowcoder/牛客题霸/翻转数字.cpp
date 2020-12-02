class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    void reverse(string &str,int start,int end)
    {
        int i=start;
        int j=end;
        while(i<j)
        {
            swap(str[i],str[j]);
            i++;
            j--;
        }
    }
    int strtoi(string str)
    {
        int res=0;
        int base=1;
        int size=str.size();
        for(int i=size-1;i>=0;i--)
        {
            res+=(str[i]-'0')*base;
            base=base*10;
        }
        return res;
    }
    int reverse(int x) {
        // write code here
        int res=0;
        if(x<0)
        {
            string str=to_string(-1*x);
            reverse(str,0,str.size()-1);
            res=strtoi(str);
            res=0-res;
        }
        else if(x>0)
        {
            string str=to_string(x);
            reverse(str,0,str.size()-1);
            res=strtoi(str);
        }
        return res;
    }
};