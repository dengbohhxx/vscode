/*
class Solution {
public:
     int  NumberOf1(int n) {
         int k=0;
         int flag=1;
         while(flag!=0)
         {
             if((flag&n)!=0)
                 k++;
             flag=flag<<1;
         }
         return k;
     }
};
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int k=0;
         while(n)
         {
             k++;
             n=n&(n-1);
         }
         return k;
     }
};