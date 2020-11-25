class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
    {
        int num=0;
        int n=data.size();
        for(int i=0;i<n;i++)
        {
            num^=data[i];
        }
        int k=1;
        while(!(num&(1<<k)))
        {
            k++;
        }
        int a=0;int b=0;
        for(int i=0;i<n;i++)
        {
            if(data[i]&(1<<k))
                *num1^=data[i];
            else
                *num2^=data[i];
        }
    }
};