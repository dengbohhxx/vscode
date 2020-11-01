class ThreeColor {
public:
    vector<int> sortThreeColor(vector<int> A, int n) {
        // write code here
        int left=0;
        int right=n-1;
        for(int i=0;i<=right;i++)
        {
            if(A[i]==0)
            {
                swap(A[left],A[i]);
                left++;
            }
            else if(A[i]==2)
            {
                swap(A[right],A[i]);
                right--;
                i--;
            }
            
        }
        return A;
    }
};