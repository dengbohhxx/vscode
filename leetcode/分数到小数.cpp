class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)
            return "0";
        if(denominator==0)
            return "";
        string result;
        long long num=(long long)numerator;
        long long denom=(long long)denominator;
        if((num>0)^(denom>0))
            result.push_back('-');
        num=llabs(num);
        denom=llabs(denom);
        result+=to_string(num/denom);

        num%=denom;
        if(num==0)
            return result;
        result.push_back('.');
        int index=result.size()-1;
        unordered_map<int,int> hash;
        while(num&&hash.count(num)==0)
        {
            hash[num]=++index;
            num*=10;
            result+=to_string(num/denom);
            num%=denom;
        }
        if(hash.count(num)>0)
        {
            result.insert(hash[num],"(");
            result.push_back(')');
        }
        return result;

    }
};