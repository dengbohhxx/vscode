
class Reverse {
public:
    void reverse (string &A,int start,int end)
    {
        int f=start;
        int e=end;
        while(f<e)
        {
           swap(A[f],A[e]);
            f++;
            e--;
        }
    }
    string reverseSentence(string A, int n) {
        // write code here
        reverse(A,0,n-1);
        int i=0;
        int str_start=0;
        while(i<=n)
        {
            if(i<n&&A[i]!=' ')
               i++;
            else
            {
                reverse(A,str_start,i-1);
                i++;
                str_start=i;
            }
        }
        return A;
    }
};