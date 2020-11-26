class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0)
            return 0;
        vector<int> vec(index);
        vec[0]=1;
        int p2=0;//初始化三个指向三个潜在成为最小丑数的位置
        int p3=0;
        int p5=0;
        for(int i=1;i<index;i++)
        {
            vec[i]=min(min(vec[p2]*2,vec[p3]*3),vec[p5]*5);
            if(vec[i]==vec[p2]*2)//为了防止重复需要三个if都能够走到
                p2++;
            if(vec[i]==vec[p3]*3)//为了防止重复需要三个if都能够走到
                p3++;
            if(vec[i]==vec[p5]*5)//为了防止重复需要三个if都能够走到
                p5++;
        }
        return vec[index-1];
    }
};