class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int size=numbers.size();
        if(size<5)
            return false;
        sort(numbers.begin(),numbers.end());
      
        int countzero=0;
        for(int i=0;i<size;i++)
        {
            if(numbers[i]==0)
                countzero++;
        }
        if(countzero==size-1)
            return true;
          for(int i=countzero+1;i<size;i++)
        {
            if(numbers[i]==numbers[i-1])
                return false;
        }
       int countkongxi=0;
        for(int i=countzero+1;i<size;i++)
        {
            if(numbers[i]-numbers[i-1]!=1)
                countkongxi+=numbers[i]-numbers[i-1]-1;
        }
        if(countkongxi==countzero)
            return true;
        else
            return false;
    }
};