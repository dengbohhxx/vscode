class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        for(int i=0;i<numbers.size();i++)
        {
            for(int j=i+1;j<numbers.size();j++)
            {
                if(to_string(numbers[i])+to_string(numbers[j])>to_string(numbers[j])+to_string(numbers[i]))\
                    swap(numbers[i],numbers[j]);
            }
        }
        string s;
        for(int i=0;i<numbers.size();i++)
        {
            s+=to_string(numbers[i]);
        }
        return s;
    }
};