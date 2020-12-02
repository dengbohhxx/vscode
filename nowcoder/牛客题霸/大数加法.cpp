class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        int carry=0;
        int index1=s.size()-1;
        int index2=t.size()-1;
        string str;
        while(index1>=0||index2>=0||carry!=0)
        {
            int a=0;
            int b=0;
            if(index1>=0)
                a=s[index1]-'0';
            if(index2>=0)
                b=t[index2]-'0';
            int sum=a+b+carry;
            str+=to_string(sum%10);
            carry=sum/10;
            index1--;
            index2--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};