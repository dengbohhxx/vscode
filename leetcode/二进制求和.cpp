class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int m=a.size();
        int n=b.size();
        int c=max(m,n)+1;
        vector<int> vec(c,0);
        int i=0;int j=0;
        for(int k=0;k<c;k++)
        {
            int temp1=0;
            int temp2=0;
            if(i<m)
            {
                temp1=a[i]-'0';
            }
            if(j<n)
            {
                temp2=b[j]-'0';
            }
            vec[k]=temp1+temp2;
            i++;
            j++;
        }
        int flag=0;
        for(int k=0;k<c;k++)
        {
            int temp=vec[k]+flag;
            vec[k]=temp%2;
            flag=temp/2;
        }
        reverse(vec.begin(),vec.end());
        i=0;
        while(i<vec.size()&&vec[i]==0)
        {
            i++;
        }
        if(i==vec.size())
            return "0";
        auto s=vector<int>(vec.begin()+i,vec.end());
        string str;
        for(int i=0;i<s.size();i++)
        {
            str+=to_string(s[i]);
        }
        return str;
    }
};