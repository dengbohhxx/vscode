class Solution {
public:
    vector<string> fizzBuzz(int n) {
        string s;
        vector<string> vec;
        for(int i=1;i<=n;i++)
        {
            if(i%3==0&&i%5!=0)
            {
                s="Fizz";
                vec.push_back(s);
            }
            else if(i%3!=0&&i%5==0)
            {
                s="Buzz";
                vec.push_back(s);
            }
            else if(i%3==0&&i%5==0)
            {
                s="FizzBuzz";
                vec.push_back(s);
            }
            else
            {
                s=to_string(i);
                vec.push_back(s);
            }
        }
        return vec;
    }
};