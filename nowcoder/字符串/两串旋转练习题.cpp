class Rotation {
public:
    bool chkRotation(string A, int lena, string B, int lenb) {
        // write code here
        if(lena!=lenb)
            return false;
        A=A+A;
        if(A.find(B)!=string::npos)
            return true;
        else
            return false;
    }
};