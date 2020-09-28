class Transform {
public:
    bool chkTransform(string A, int lena, string B, int lenb) {
        // write code here
        if(lena!=lenb)
            return false;
        //新建两个哈希表
        vector<vector<char> > hash1(256);
        vector<vector<char> > hash2(256);
        for(string::size_type i=0; i!=A.size();i++)
        {
            hash1[A[i]-NULL].push_back(A[i]);
        }
        for(string::size_type i=0; i!=B.size();i++)
        {
            hash2[B[i]-NULL].push_back(B[i]);
        }
        //判断两个哈希表是否相等
        if(hash1==hash2)
            return true;
        else
            return false;
    }
};