class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            hash[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(unordered_map<string,vector<string>>::iterator iter=hash.begin();iter!=hash.end();iter++)
        {
            res.push_back(iter->second);
        }
        return res;
    }
};