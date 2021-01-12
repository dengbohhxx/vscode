class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x==0)
            return true;
        else
        {
            string str=to_string(x);
            int n=str.size();
            int left=0;
            int right=n-1;
            while(left<right)
            {
                if(str[left]!=str[right])
                {
                    return false;
                }
                else
                {
                    left++;
                    right--;
                }
            }
            return true;
        }
    }
};