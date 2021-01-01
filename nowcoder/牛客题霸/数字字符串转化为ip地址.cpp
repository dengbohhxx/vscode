class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    vector<string> restoreIpAddresses(string s) {
        // write code here
        vector<string> arrResult,arrTmp;
        backtrack(s,arrResult,arrTmp,0);
        return arrResult;
    }
    bool isValid(string& s){
        if((s.size()>1 && s[0]=='0')||s.size()>3)//判断是否失效
            return false;
        return stoi(s)<256;//还要小于255
    }
    void backtrack(string& s,vector<string>& res,vector<string>& cur,int pos)
    {

        if(cur.size()==4 && pos==s.size()){//符合条件，将当前路径加入容器中
            res.push_back(cur[0]+'.'+cur[1]+'.'+cur[2]+'.'+cur[3]);
            return;
        }
        for(int i=pos;i<s.size();i++){
            string tmp = s.substr(pos,i-pos+1);//
            if(isValid(tmp)){
                cur.push_back(tmp);//做选择
                backtrack(s,res,cur,i+1);//迭代
                cur.pop_back();//撤销选择
            }
        }
        
        
    }
};