class Prior {
public:
    string findSmallest(vector<string> strs, int n) {
        // write code here
        for(int i=0;i<strs.size();i++)
        {
            for(int j=i;j<strs.size();j++)
            {
                if(strs[i]+strs[j]>strs[j]+strs[i])
                swap(strs[i],strs[j]);
                
            }
        }
        string str;
        for(int i=0;i<strs.size();i++)
            str+=strs[i];
        return str;
    }
};