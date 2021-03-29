class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1=(C-A)*(D-B);
        int area2=(G-E)*(H-F);
        if(E>=C||F>=D||A>=G||B>=H)//两个矩形不想交
            return area1+area2;
        int area=(min(C,G)-max(A,E))*(min(D,H)-max(B,F));
        return area1+area2-area;
    }
};