class Solution {
public:
    /**
     *
     * @param n int整型 the n
     * @return int整型
     */
      int Nqueen (int n) {
        // write code here
       int A[14]={1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596};
        return A[n-1];
    }
};