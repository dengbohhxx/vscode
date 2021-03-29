struct str2freq
{
    string str;
    int fre;
};
class Solution {
public:
    static bool cmp(str2freq a,str2freq b)
    {
        if(a.fre>b.fre)
            return true;
        else if(a.fre==b.fre)
        {
            if(a.str<b.str)
                return true;
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int> hash;
        for(int i=0;i<n;i++)
        {
            hash[words[i]]++;
        }
        vector<str2freq> vec;
        for(unordered_map<string,int>::iterator iter=hash.begin();iter!=hash.end();iter++)
        {
            str2freq temp;
            temp.str=iter->first;
            temp.fre=iter->second;
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<string> res;
        for(int i=0;i<k;i++)
        {
            res.push_back(vec[i].str);
        }
        return res;
    }
};