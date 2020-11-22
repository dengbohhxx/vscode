/*
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> result;
        int num=array.size();
        for(int i=0;i<num;i++)
            {
            if(array[i]%2==1)
                result.push_back(array[i]);
        }
        for(int i=0;i<num;i++)
            {
            if(array[i]%2==0)
                result.push_back(array[i]);
        }
        array=result;
    }
};
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size=array.size();
        bool flag=false;
        while(size--)
        {
            for(int i=0;i<array.size();i++)
            {
                if(array[i]%2==0&&array[i+1]%2==1)
                {
                    swap(array[i],array[i+1]);
                    flag=true;
                }
            }
            if(flag==false)
                break;
        }
    }
};