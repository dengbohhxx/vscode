class Solution {
public:
    void sub(vector<int> S,vector<vector<int> > &vec,vector<int> &row,int start ,int end)
    {
        if(row.size()==end)
        {
            vec.push_back(row);
            return;
        }
        else
        {
            for(int i=start;i<S.size();i++//注意i=start开始
            {
                
                 row.push_back(S[i]);
                 sub(S,vec,row,i+1,end);
                 row.pop_back();
            }
        }
        
    }
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > vec;
        
        if(S.empty())
            return vec;
        int size=S.size();
        for(int i=0;i<=size;i++)
        {
            vector<int> row;
            sub(S,vec,row,0,i);
        }
        return vec;
    }
};