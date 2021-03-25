class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        if(n==0)
            return path;
        vector<string> vec;
        path+="/";
        for(int i=0;i<n;i++)
        {
            int l=i;
            int r=i;
            if(path[i]=='/'&&(i!=n-1))
            {
                l=i;
                r=i+1;
                while(path[r]!='/')
                {
                    r++;
                }
                if(r-l==1)
                    continue; 
                string s=path.substr(l+1,r-l-1);
                if(s!="."&&s!="..")
                {
                    vec.push_back(s);
                }
                else if(s==".")
                {
                    i=r-1;
                    continue;
                }
                else if(s=="..")
                {
                    if(!vec.empty())
                    {
                        vec.pop_back();
                    }
                }
                i=r-1;
            }
        }
        int m=vec.size();
        if(m==0)
            return "/";
        string str;
        for(int i=0;i<m;i++)
        {
            str+="/";
            str+=vec[i];
        }
        return str;

    }
};