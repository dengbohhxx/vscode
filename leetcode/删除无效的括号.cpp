class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int left,right;
        getInvalid(s,left,right);
        string path(s.size(),' ');
        unordered_set<string> dedup;
        dfs(path,0,s,0,left,right,dedup);
        for(auto x : dedup){
            ans.push_back(x);
        }
        return ans;
    }

    void dfs(string& path,int cur,
            const string& s,int p,
            int left,int right,unordered_set<string>& dedup){
        if(left == 0 && right == 0){
            string t = path.substr(0,cur) + s.substr(p);
            int l,r;
            getInvalid(t,l,r);//在判断字符串是否有效。这里可以优化，但是增加复杂度。
            if(l == 0 && r == 0){
                dedup.insert(t);
            }
            return ;
        }
        if(p >= s.size() || cur >= path.size()){
            return ;
        }
        if(s[p] == '('){
            //保留'('
            path[cur] = '(';
            dfs(path,cur+1,s,p+1,left,right,dedup);
            if(left > 0){//删除'('
                dfs(path,cur,s,p+1,left-1,right,dedup);
            }
        }else  if(s[p] ==')'){
            //保留')'
            path[cur] = ')';
            dfs(path,cur+1,s,p+1,left,right,dedup);
            if(right > 0){//删除')'
                dfs(path,cur,s,p+1,left,right-1,dedup);
            }
        }else{//其它字符保留
            path[cur] = s[p];
            dfs(path,cur+1,s,p+1,left,right,dedup);
        }
    }

    //统计无效左括号，右括号的个数
    void getInvalid(const string & s,int& left,int& right){
        left = 0;
        right = 0;

        for(auto c : s){
            if(c == '('){
                left++;
            }else if(c == ')'){
                if(left > 0){
                    --left;
                }else{
                    right++;
                }
            }
        }
    }
};