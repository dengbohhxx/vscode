class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool res=false;
        if(pushV.empty()||popV.empty())
            return res;
        stack<int> help;
        int popindex=0;
        for(int i=0;i<pushV.size();i++)
        {
            help.push(pushV[i]);
            while(!help.empty()&&help.top()==popV[popindex])
            {
                help.pop();
                popindex++;
            }
        }
        if(help.empty())
            res=true;
        return res;
    }
};