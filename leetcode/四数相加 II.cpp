class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> countab;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                countab[A[i]+B[j]]++;
            }
        }
        int ans=0;
        for(int i=0;i<C.size();i++)
        {
            for(int j=0;j<D.size();j++)
            {
                ans+=countab[0-C[i]-D[j]];
            }
        }
        return ans;
    }
};