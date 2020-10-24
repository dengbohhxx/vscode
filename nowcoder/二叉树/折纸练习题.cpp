class FoldPaper {
public:
    void inorder(int n,string str,vector<string> &vec)
    {
        if(n==0)
            return;
        else
        {
            inorder(n-1,"down",vec);
            vec.push_back(str);
            inorder(n-1,"up",vec);
        }
        
        
    }
    vector<string> foldPaper(int n) {
        // write code here
        vector<string> vec;
        inorder(n,"down",vec);
        return vec;
    }
};