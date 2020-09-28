class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        int m=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]!='('&&A[i]!=')')
                return false;
            else
            {
                if(A[i]=='(')
                    m++;
                if(A[i]==')')
                    m--;
                if(m<0)
                    return false;
            }
        }
        if(m==0)
            return true;
        else
            return false;
    }
};