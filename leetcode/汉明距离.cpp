/*
class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp=x^y;
        int a=1;
        int count=0;
        while(a>0)
        {
            if((temp&a)!=0)
            {
                count++;
            }
            a=a<<1;
        }
        return count;
    }
};
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp=x^y;
        int k=0;
        while(temp)
        {
            temp=temp&(temp-1);
            k++;
        }
        return k;
    }
};