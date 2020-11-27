class Solution {
public:
    int Add(int num1, int num2)
    {
      while(num2!=0)
      {
          int temp=num1^num2;//模仿加法不进位
          num2=(num1&num2)<<1;//只模仿进位
          num1=temp;
      }
        return num1;
    }
};