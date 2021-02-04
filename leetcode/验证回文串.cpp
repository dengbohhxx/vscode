class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return true;
        int left=0;
        int right=n-1;
        while(left<right)
        {
            while(left<right&&!isalpha(s[left])&&!isdigit(s[left]))
            {
                left++;
            }
            while(left<right&&!isalpha(s[right])&&!isdigit(s[right]))
            {
                right--;
            }
            if(tolower(s[left])!=tolower(s[right]))
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
};