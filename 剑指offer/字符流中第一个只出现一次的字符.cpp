class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        s += ch;
        count[ch-NULL]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int length = s.size();
        for(int i = 0; i < length; i++){
            if(count[s[i]-NULL] == 1){
                return s[i];
            }
        }
        return '#';
    }
private:
    string s;
    int count[256]={0};
};